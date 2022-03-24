################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/GPS_Cnfg.c \
../HAL/GPS_Priv.c \
../HAL/GPS_Prog.c 

OBJS += \
./HAL/GPS_Cnfg.o \
./HAL/GPS_Priv.o \
./HAL/GPS_Prog.o 

C_DEPS += \
./HAL/GPS_Cnfg.d \
./HAL/GPS_Priv.d \
./HAL/GPS_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


