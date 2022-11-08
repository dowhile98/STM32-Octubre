################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LVGL/lvgl/src/extra/others/fragment/lv_fragment.c \
../Middlewares/Third_Party/LVGL/lvgl/src/extra/others/fragment/lv_fragment_manager.c 

OBJS += \
./Middlewares/Third_Party/LVGL/lvgl/src/extra/others/fragment/lv_fragment.o \
./Middlewares/Third_Party/LVGL/lvgl/src/extra/others/fragment/lv_fragment_manager.o 

C_DEPS += \
./Middlewares/Third_Party/LVGL/lvgl/src/extra/others/fragment/lv_fragment.d \
./Middlewares/Third_Party/LVGL/lvgl/src/extra/others/fragment/lv_fragment_manager.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LVGL/lvgl/src/extra/others/fragment/%.o Middlewares/Third_Party/LVGL/lvgl/src/extra/others/fragment/%.su: ../Middlewares/Third_Party/LVGL/lvgl/src/extra/others/fragment/%.c Middlewares/Third_Party/LVGL/lvgl/src/extra/others/fragment/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Core/Inc" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Middlewares/Third_Party/LVGL/hal_stm32_lvgl/encoder" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Middlewares/Third_Party/LVGL/lvgl" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Middlewares/Third_Party/LVGL/hal_stm32_lvgl/tft" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-extra-2f-others-2f-fragment

clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-extra-2f-others-2f-fragment:
	-$(RM) ./Middlewares/Third_Party/LVGL/lvgl/src/extra/others/fragment/lv_fragment.d ./Middlewares/Third_Party/LVGL/lvgl/src/extra/others/fragment/lv_fragment.o ./Middlewares/Third_Party/LVGL/lvgl/src/extra/others/fragment/lv_fragment.su ./Middlewares/Third_Party/LVGL/lvgl/src/extra/others/fragment/lv_fragment_manager.d ./Middlewares/Third_Party/LVGL/lvgl/src/extra/others/fragment/lv_fragment_manager.o ./Middlewares/Third_Party/LVGL/lvgl/src/extra/others/fragment/lv_fragment_manager.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-extra-2f-others-2f-fragment

