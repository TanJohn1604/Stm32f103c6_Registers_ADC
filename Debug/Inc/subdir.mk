################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/RccTimerConfig.c \
../Inc/adc.c \
../Inc/adc_interr.c 

OBJS += \
./Inc/RccTimerConfig.o \
./Inc/adc.o \
./Inc/adc_interr.o 

C_DEPS += \
./Inc/RccTimerConfig.d \
./Inc/adc.d \
./Inc/adc_interr.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/%.o: ../Inc/%.c Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"D:/Project STM/STM32F103C6_Registers_ADC/Core/Include" -I"D:/Project STM/STM32F103C6_Registers_ADC/Device/ST/STM32F1xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc

clean-Inc:
	-$(RM) ./Inc/RccTimerConfig.d ./Inc/RccTimerConfig.o ./Inc/adc.d ./Inc/adc.o ./Inc/adc_interr.d ./Inc/adc_interr.o

.PHONY: clean-Inc

