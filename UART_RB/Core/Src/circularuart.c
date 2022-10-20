/*
 * circularuart.c
 *
 *  Created on: 19 ago. 2022
 *      Author: jeffr
 */


#include <circularbuffer.h>
#include <circularuart.h>
#include <stm32f4xx.h>

/*Global variables -------------------------------------------------*/

// Variables.
static CircularBufferObject_t rxBufferObject, txBufferObject;

/*Function definition ----------------------------------------------*/

/*
 * @brief Initializes UART hardware with the given baud-rate.
 * @param baud The baud-rate to set.
 * @param parity Parity setting. 0 for no-parity, 1 for odd and 2 for even.
 */
void CircularUART2_Init(/*uint32_t pclk, const uint32_t baud, const uint8_t parity*/){

	// Reset the buffers.
	CircularBuffer_init(&rxBufferObject, NULL, 0);
	CircularBuffer_init(&txBufferObject, NULL, 0);


	// Enable USART2 interrupts.
//	USART_IRQPriorityConfig(USART2_IRQn, 0);
//	USART_IRQInterruptConfig(USART2_IRQn, ENABLE);
	NVIC_EnableIRQ(USART2_IRQn);

	// Configure USART1 as 8bit UART with no parity.
	//USART_Init(USART2, pclk, baud, parity);

	// Disable the USART1 transmit buffer empty interrupt.
	USART2->CR1 &=~ USART_CR1_TXEIE;

	// Disable the USART1 receive buffer not empty interrupt.
	USART2->CR1 &=~ USART_CR1_RXNEIE;

	// Enable USART1.
	USART2->CR1 |= USART_CR1_UE;

	return;
}

/*
 * @brief Initializes and enables TX.
 * @param buffer Memory buffer to use for tx circular buffer.
 * @param length_2N Size of the buffer memory, i.e. 8 indicates 2^8=256 bytes.
 */
void CircularUART_StartTx(uint8_t * const buffer, const uint8_t length_2N) {
	// Disable the USART1 transmit buffer empty interrupt.
	USART2->CR1 &=~ USART_CR1_TXEIE;

	// Initialize the buffer.
	CircularBuffer_init(&txBufferObject, buffer, length_2N);
}

/*
 * @brief Initializes and enables RX.
 * @param buffer Memory buffer to use for rx circular buffer.
 * @param length_2N Size of the buffer memory, i.e. 8 indicates 2^8=256 bytes.
 */
void CircularUART_StartRx(uint8_t * const buffer, const uint8_t length_2N) {
	//-- Disable the USART1 receive buffer not empty interrupt.
	USART2->CR1 &=~ USART_CR1_RXNEIE;

	// Initialize the buffer.
	CircularBuffer_init(&rxBufferObject, buffer, length_2N);

	//-- Clear the RXNE bit to prevent outdated data.
	USART2->SR &=~ USART_SR_RXNE;

	//-- Enable the USART1 receive buffer not empty interrupt.
	USART2->CR1 |= USART_CR1_RXNEIE;

	return;
}

/*
 * @brief Clear the TX buffer and fault flag.
 */
void CircularUART_ClearTx(void) {
	//-- Disable the USART1 transmit buffer empty interrupt.
	USART2->CR1 &=~ USART_CR1_TCIE;

	// Initialize the buffer.
	CircularBuffer_checkAndClearFault(&txBufferObject, true);
}

/*
 * @brief Clear the RX buffer and fault flag.
 */
void CircularUART_ClearRx(void) {
	// Clear buffer and fault.
	CircularBuffer_checkAndClearFault(&rxBufferObject, true);
}


/*
 * @brief Triggers transmission of data.
 * @param data Data to send.
 * @param maxlen The requested length for sending data.
 * @return Returns the actual length that was copied to the tx buffer.
 */
uint16_t CircularUART_Send(const uint8_t * data, const uint16_t maxlen) {
	uint16_t result = CircularBuffer_pushBack(&txBufferObject, data, maxlen);

	// Trigger the first transmission if TX is idle.
	if (USART2->SR & USART_SR_TC) {
		//-- Enable the USART1 receive buffer not empty interrupt.
		USART2->CR1 |= USART_CR1_TXEIE;
	}

	// Return result.
	return result;
}


/*
 * @brief Get the received data from rx buffer.
 * @param data Memory to write the received data.
 * @param maxlen The requested length for receiving data.
 * @return Returns the actual length that was copied from the rx buffer.
 */
uint16_t CircularUART_Receive(uint8_t * data, const uint16_t maxlen) {
	return CircularBuffer_popFront(&rxBufferObject, data, maxlen);
}

/*
 * @brief Get the number of bytes that are still in tx buffer.
 * @return Returns the number of unsent bytes.
 */
uint16_t CircularUART_GetUnsentCount(void) {
	return CircularBuffer_getUnreadSize(&txBufferObject);
}

/*
 * @brief Get the number of received bytes in the rx buffer.
 * @return Returns the number of unread bytes.
 */
uint16_t CircularUART_GetUnreadCount(void) {
	return CircularBuffer_getUnreadSize(&rxBufferObject);
}

/*
 * @brief Interrupt handler for RX and TX operations.
 */
void USART2_IRQHandler(void) {
	uint8_t data;
	//-- Transmit buffer empty interrupt.
	if (USART2->SR & USART_SR_TXE) {
		// Pop from tx buffer (if available) to UART.

		if (CircularBuffer_popFrontByte(&txBufferObject, &data)) {
			USART2->DR = data;
		} else {
			//-- Disable the USART1 transmit buffer empty interrupt.
			USART2->CR1 &=~ USART_CR1_TXEIE;
		}
	}

	//-- Reception complete interrupt.
	if (USART2->SR & USART_SR_RXNE) {
		// Push from UART to rx buffer.
		data = USART2->DR;
		CircularBuffer_pushBackByte(&rxBufferObject, data);
	}
}

