################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar.c \
../Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_arrow.c \
../Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_dropdown.c 

OBJS += \
./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar.o \
./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_arrow.o \
./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_dropdown.o 

C_DEPS += \
./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar.d \
./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_arrow.d \
./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_dropdown.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/%.o Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/%.su: ../Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/%.c Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/Squareline_ST7735/Core/Inc" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/Squareline_ST7735/Middlewares/Third_Party/LVGL" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/Squareline_ST7735/Core/ui" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/Squareline_ST7735/Middlewares/Third_Party/LVGL/hal_stm32_lvgl/encoder" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/Squareline_ST7735/Middlewares/Third_Party/LVGL/lvgl" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/Squareline_ST7735/Middlewares/Third_Party/LVGL/hal_stm32_lvgl/tft" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/Squareline_ST7735/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/Squareline_ST7735/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-calendar

clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-calendar:
	-$(RM) ./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar.d ./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar.o ./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar.su ./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_arrow.d ./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_arrow.o ./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_arrow.su ./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_dropdown.d ./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_dropdown.o ./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_dropdown.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-calendar

