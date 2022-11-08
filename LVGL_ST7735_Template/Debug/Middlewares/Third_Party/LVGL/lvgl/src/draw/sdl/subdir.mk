################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_arc.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_bg.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_composite.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_img.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_label.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_line.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_mask.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_polygon.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_rect.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_utils.c 

OBJS += \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_arc.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_bg.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_composite.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_img.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_label.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_line.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_mask.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_polygon.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_rect.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_utils.o 

C_DEPS += \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_arc.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_bg.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_composite.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_img.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_label.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_line.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_mask.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_polygon.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_rect.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/%.o Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/%.su: ../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/%.c Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Core/Inc" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Middlewares/Third_Party/LVGL/hal_stm32_lvgl/encoder" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Middlewares/Third_Party/LVGL/lvgl" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Middlewares/Third_Party/LVGL/hal_stm32_lvgl/tft" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-draw-2f-sdl

clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-draw-2f-sdl:
	-$(RM) ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_arc.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_arc.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_arc.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_bg.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_bg.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_bg.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_composite.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_composite.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_composite.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_img.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_img.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_img.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_label.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_label.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_label.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_line.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_line.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_line.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_mask.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_mask.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_mask.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_polygon.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_polygon.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_polygon.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_rect.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_rect.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_rect.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_utils.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_utils.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_utils.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-draw-2f-sdl

