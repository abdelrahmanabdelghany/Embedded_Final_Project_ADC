################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/src/adc.c \
../Drivers/src/gpio.c \
../Drivers/src/inter.c \
../Drivers/src/keypad.c \
../Drivers/src/lcd.c 

OBJS += \
./Drivers/src/adc.o \
./Drivers/src/gpio.o \
./Drivers/src/inter.o \
./Drivers/src/keypad.o \
./Drivers/src/lcd.o 

C_DEPS += \
./Drivers/src/adc.d \
./Drivers/src/gpio.d \
./Drivers/src/inter.d \
./Drivers/src/keypad.d \
./Drivers/src/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/src/%.o: ../Drivers/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F401CCUx -DDEBUG -DSTM32F401xx -I"C:/Users/Abdelrahman Muhsen/Desktop/Lab_4/Lab04/Drivers/include" -I"C:/Users/Abdelrahman Muhsen/Desktop/Lab_4/Lab04/inc" -I"C:/Users/Abdelrahman Muhsen/Desktop/Lab_4/Lab04/CMSIS/device" -I"C:/Users/Abdelrahman Muhsen/Desktop/Lab_4/Lab04/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


