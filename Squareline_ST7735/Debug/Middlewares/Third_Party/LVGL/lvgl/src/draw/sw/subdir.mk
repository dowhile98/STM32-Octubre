################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_arc.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_blend.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_dither.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_gradient.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_img.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_letter.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_line.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_polygon.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_rect.c 

OBJS += \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_arc.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_blend.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_dither.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_gradient.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_img.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_letter.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_line.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_polygon.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_rect.o 

C_DEPS += \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_arc.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_blend.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_dither.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_gradient.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_img.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_letter.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_line.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_polygon.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_rect.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/%.o Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/%.su: ../Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/%.c Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/Squareline_ST7735/Core/Inc" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/Squareline_ST7735/Middlewares/Third_Party/LVGL" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/Squareline_ST7735/Core/ui" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/Squareline_ST7735/Middlewares/Third_Party/LVGL/hal_stm32_lvgl/encoder" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/Squareline_ST7735/Middlewares/Third_Party/LVGL/lvgl" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/Squareline_ST7735/Middlewares/Third_Party/LVGL/hal_stm32_lvgl/tft" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/Squareline_ST7735/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/Squareline_ST7735/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-draw-2f-sw

clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-draw-2f-sw:
	-$(RM) ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_arc.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_arc.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_arc.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_blend.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_blend.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_blend.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_dither.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_dither.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_dither.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_gradient.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_gradient.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_gradient.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_img.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_img.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_img.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_letter.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_letter.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_letter.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_line.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_line.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_line.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_polygon.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_polygon.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_polygon.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_rect.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_rect.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/lv_draw_sw_rect.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-draw-2f-sw

