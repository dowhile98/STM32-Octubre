################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_disp.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_event.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_group.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev_scroll.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_class.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_draw.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_pos.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_scroll.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style_gen.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_tree.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_refr.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_theme.c 

OBJS += \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_disp.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_event.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_group.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev_scroll.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_class.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_draw.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_pos.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_scroll.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style_gen.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_tree.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_refr.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_theme.o 

C_DEPS += \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_disp.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_event.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_group.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev_scroll.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_class.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_draw.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_pos.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_scroll.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style_gen.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_tree.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_refr.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_theme.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LVGL/lvgl/src/core/%.o Middlewares/Third_Party/LVGL/lvgl/src/core/%.su: ../Middlewares/Third_Party/LVGL/lvgl/src/core/%.c Middlewares/Third_Party/LVGL/lvgl/src/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/Squareline_ST7735/Core/Inc" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/Squareline_ST7735/Middlewares/Third_Party/LVGL" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/Squareline_ST7735/Core/ui" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/Squareline_ST7735/Middlewares/Third_Party/LVGL/hal_stm32_lvgl/encoder" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/Squareline_ST7735/Middlewares/Third_Party/LVGL/lvgl" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/Squareline_ST7735/Middlewares/Third_Party/LVGL/hal_stm32_lvgl/tft" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/Squareline_ST7735/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/Squareline_ST7735/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-core

clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-core:
	-$(RM) ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_disp.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_disp.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_disp.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_event.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_event.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_event.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_group.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_group.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_group.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev_scroll.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev_scroll.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev_scroll.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_class.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_class.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_class.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_draw.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_draw.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_draw.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_pos.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_pos.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_pos.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_scroll.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_scroll.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_scroll.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style_gen.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style_gen.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style_gen.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_tree.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_tree.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_tree.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_refr.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_refr.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_refr.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_theme.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_theme.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_theme.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-core

