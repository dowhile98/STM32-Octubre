################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_arc.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_img.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_label.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_line.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_mask.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_rect.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_triangle.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_buf.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_cache.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_decoder.c 

OBJS += \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_arc.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_img.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_label.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_line.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_mask.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_rect.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_triangle.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_buf.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_cache.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_decoder.o 

C_DEPS += \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_arc.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_img.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_label.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_line.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_mask.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_rect.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_triangle.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_buf.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_cache.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_decoder.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LVGL/lvgl/src/draw/%.o Middlewares/Third_Party/LVGL/lvgl/src/draw/%.su: ../Middlewares/Third_Party/LVGL/lvgl/src/draw/%.c Middlewares/Third_Party/LVGL/lvgl/src/draw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Core/Inc" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Middlewares/Third_Party/LVGL/hal_stm32_lvgl/encoder" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Middlewares/Third_Party/LVGL/lvgl" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Middlewares/Third_Party/LVGL/hal_stm32_lvgl/tft" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-draw

clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-draw:
	-$(RM) ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_arc.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_arc.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_arc.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_img.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_img.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_img.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_label.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_label.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_label.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_line.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_line.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_line.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_mask.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_mask.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_mask.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_rect.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_rect.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_rect.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_triangle.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_triangle.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_triangle.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_buf.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_buf.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_buf.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_cache.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_cache.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_cache.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_decoder.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_decoder.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_decoder.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-draw

