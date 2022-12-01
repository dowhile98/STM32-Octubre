/**
 * @file helloworld.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>  //->copia el contenido del archivo .h .c
#include <stdlib.h>
#include <stdint.h>


/**
 * @brief 
 * #ifdef, ifndef endif
 * #if, else, elif
 * #error, waring
 * #define
 * ##
 */
#define LED  8  //->PIN (definir constantes simbolicas)

//#define WIFI


#ifndef lib
#define lib
//codigo

#endif

#ifndef lib
#define lib
//codigo

#endif

#define socket 0



#define GPIOA  200
#define GPIOB  100


#define SUMPORT(PORT) GPIO ## PORT + 1


int main(void){
    
    printf("PORT: %d\r\n", SUMPORT(A));
#if socket == 0
    printf("socket es 0\r\n");
#elif socket == 1

#elif socket == 2

#else

#endif

#ifdef WIFI         //if defined 
    printf("red wifi seleccionada\r\n");
#endif

#ifndef WIFI        //IF NOT DEFINED
    printf("SELECCIONAR RED WIFI");
#endif
    
    system("PAUSE");
    return 0;
}