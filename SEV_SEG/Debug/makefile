################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
SEV_SEG.lss \

FLASH_IMAGE += \
SEV_SEG.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: SEV_SEG.elf secondary-outputs

# Tool invocations
SEV_SEG.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SEV_SEG.map -mmcu=atmega16 -o "SEV_SEG.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SEV_SEG.lss: SEV_SEG.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SEV_SEG.elf  >"SEV_SEG.lss"
	@echo 'Finished building: $@'
	@echo ' '

SEV_SEG.hex: SEV_SEG.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SEV_SEG.elf  "SEV_SEG.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SEV_SEG.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 SEV_SEG.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SEV_SEG.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
