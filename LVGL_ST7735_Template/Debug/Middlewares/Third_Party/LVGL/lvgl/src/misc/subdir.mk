################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_anim.c \
../Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_anim_timeline.c \
../Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_area.c \
../Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_async.c \
../Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_bidi.c \
../Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_color.c \
../Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_fs.c \
../Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_gc.c \
../Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_ll.c \
../Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_log.c \
../Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_lru.c \
../Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_math.c \
../Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_mem.c \
../Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_printf.c \
../Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_style.c \
../Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_style_gen.c \
../Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_templ.c \
../Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_timer.c \
../Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_tlsf.c \
../Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_txt.c \
../Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_txt_ap.c \
../Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_utils.c 

OBJS += \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_anim.o \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_anim_timeline.o \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_area.o \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_async.o \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_bidi.o \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_color.o \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_fs.o \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_gc.o \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_ll.o \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_log.o \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_lru.o \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_math.o \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_mem.o \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_printf.o \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_style.o \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_style_gen.o \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_templ.o \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_timer.o \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_tlsf.o \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_txt.o \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_txt_ap.o \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_utils.o 

C_DEPS += \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_anim.d \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_anim_timeline.d \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_area.d \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_async.d \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_bidi.d \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_color.d \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_fs.d \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_gc.d \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_ll.d \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_log.d \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_lru.d \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_math.d \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_mem.d \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_printf.d \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_style.d \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_style_gen.d \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_templ.d \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_timer.d \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_tlsf.d \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_txt.d \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_txt_ap.d \
./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LVGL/lvgl/src/misc/%.o Middlewares/Third_Party/LVGL/lvgl/src/misc/%.su: ../Middlewares/Third_Party/LVGL/lvgl/src/misc/%.c Middlewares/Third_Party/LVGL/lvgl/src/misc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Core/Inc" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Middlewares/Third_Party/LVGL/hal_stm32_lvgl/encoder" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Middlewares/Third_Party/LVGL/lvgl" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Middlewares/Third_Party/LVGL/hal_stm32_lvgl/tft" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32-Octubre/LVGL_ST7735_Template/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-misc

clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-misc:
	-$(RM) ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_anim.d ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_anim.o ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_anim.su ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_anim_timeline.d ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_anim_timeline.o ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_anim_timeline.su ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_area.d ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_area.o ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_area.su ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_async.d ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_async.o ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_async.su ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_bidi.d ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_bidi.o ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_bidi.su ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_color.d ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_color.o ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_color.su ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_fs.d ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_fs.o ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_fs.su ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_gc.d ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_gc.o ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_gc.su ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_ll.d ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_ll.o ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_ll.su ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_log.d ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_log.o ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_log.su ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_lru.d ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_lru.o ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_lru.su ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_math.d ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_math.o ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_math.su ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_mem.d ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_mem.o ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_mem.su ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_printf.d ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_printf.o ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_printf.su ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_style.d ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_style.o ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_style.su ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_style_gen.d ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_style_gen.o ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_style_gen.su ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_templ.d ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_templ.o ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_templ.su ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_timer.d ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_timer.o ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_timer.su ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_tlsf.d ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_tlsf.o ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_tlsf.su ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_txt.d ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_txt.o ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_txt.su ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_txt_ap.d ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_txt_ap.o ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_txt_ap.su ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_utils.d ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_utils.o ./Middlewares/Third_Party/LVGL/lvgl/src/misc/lv_utils.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-misc

