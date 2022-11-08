################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_arc.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_bar.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btn.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btnmatrix.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_canvas.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_checkbox.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_dropdown.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_img.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_label.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_line.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_objx_templ.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_roller.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_slider.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_switch.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_table.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_textarea.c 

OBJS += \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_arc.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_bar.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btn.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btnmatrix.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_canvas.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_checkbox.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_dropdown.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_img.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_label.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_line.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_objx_templ.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_roller.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_slider.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_switch.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_table.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_textarea.o 

C_DEPS += \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_arc.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_bar.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btn.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btnmatrix.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_canvas.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_checkbox.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_dropdown.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_img.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_label.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_line.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_objx_templ.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_roller.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_slider.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_switch.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_table.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_textarea.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LVGL/lvgl/src/widgets/%.o Middlewares/Third_Party/LVGL/lvgl/src/widgets/%.su: ../Middlewares/Third_Party/LVGL/lvgl/src/widgets/%.c Middlewares/Third_Party/LVGL/lvgl/src/widgets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Core/Inc" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Middlewares/Third_Party/LVGL/hal_stm32_lvgl/encoder" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Middlewares/Third_Party/LVGL/lvgl" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Middlewares/Third_Party/LVGL/hal_stm32_lvgl/tft" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-widgets

clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-widgets:
	-$(RM) ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_arc.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_arc.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_arc.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_bar.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_bar.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_bar.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btn.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btn.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btn.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btnmatrix.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btnmatrix.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btnmatrix.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_canvas.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_canvas.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_canvas.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_checkbox.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_checkbox.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_checkbox.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_dropdown.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_dropdown.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_dropdown.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_img.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_img.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_img.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_label.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_label.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_label.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_line.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_line.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_line.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_objx_templ.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_objx_templ.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_objx_templ.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_roller.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_roller.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_roller.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_slider.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_slider.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_slider.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_switch.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_switch.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_switch.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_table.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_table.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_table.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_textarea.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_textarea.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_textarea.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-widgets

