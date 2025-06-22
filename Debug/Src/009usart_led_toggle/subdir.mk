################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/009usart_led_toggle/009usart_led_toggle.c 

OBJS += \
./Src/009usart_led_toggle/009usart_led_toggle.o 

C_DEPS += \
./Src/009usart_led_toggle/009usart_led_toggle.d 


# Each subdirectory must supply rules for building sources it contributes
Src/009usart_led_toggle/%.o Src/009usart_led_toggle/%.su Src/009usart_led_toggle/%.cyclo: ../Src/009usart_led_toggle/%.c Src/009usart_led_toggle/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DB_L475E_IOT01A2 -DSTM32L475VGTx -c -I"C:/Users/admin/Desktop/STM32/Mastering stm32/stm32l47xx_drivers/drivers/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-009usart_led_toggle

clean-Src-2f-009usart_led_toggle:
	-$(RM) ./Src/009usart_led_toggle/009usart_led_toggle.cyclo ./Src/009usart_led_toggle/009usart_led_toggle.d ./Src/009usart_led_toggle/009usart_led_toggle.o ./Src/009usart_led_toggle/009usart_led_toggle.su

.PHONY: clean-Src-2f-009usart_led_toggle

