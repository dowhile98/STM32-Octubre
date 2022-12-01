################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/widgets/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/misc/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/hal/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/font/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/win/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/tileview/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/tabview/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/spinner/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/spinbox/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/span/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/msgbox/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/meter/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/menu/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/list/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/led/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/keyboard/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/imgbtn/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/colorwheel/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/chart/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/animimg/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/themes/mono/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/themes/default/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/themes/basic/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/others/snapshot/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/others/monkey/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/others/gridnav/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/libs/sjpg/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/libs/rlottie/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/libs/qrcode/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/libs/png/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/libs/gif/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/libs/fsdrv/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/libs/freetype/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/libs/ffmpeg/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/libs/bmp/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/layouts/grid/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/layouts/flex/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/extra/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/draw/sw/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/draw/stm32_dma2d/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp_vglite/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp_pxp/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/draw/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/src/core/subdir.mk
-include Middlewares/Third_Party/LVGL/lvgl/env_support/rt-thread/subdir.mk
-include Middlewares/Third_Party/LVGL/hal_stm32_lvgl/tft/subdir.mk
-include Middlewares/Third_Party/LVGL/hal_stm32_lvgl/encoder/subdir.mk
-include Core/ui/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Squareline_ST7735
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Squareline_ST7735.elf \

MAP_FILES += \
Squareline_ST7735.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Squareline_ST7735.list \


# All Target
all: main-build

# Main-build Target
main-build: Squareline_ST7735.elf secondary-outputs

# Tool invocations
Squareline_ST7735.elf Squareline_ST7735.map: $(OBJS) $(USER_OBJS) D:\TRABAJO\UMAKER\CURSOS\ARM\ -\ NUCLEO\STM32-Octubre\Squareline_ST7735\STM32F407VGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Squareline_ST7735.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\TRABAJO\UMAKER\CURSOS\ARM - NUCLEO\STM32-Octubre\Squareline_ST7735\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Squareline_ST7735.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Squareline_ST7735.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Squareline_ST7735.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Squareline_ST7735.elf Squareline_ST7735.list Squareline_ST7735.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
