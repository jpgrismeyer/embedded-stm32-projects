################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/Src/led.c \
../drivers/Src/stm32l475xx_gpio_driver.c \
../drivers/Src/stm32l475xx_spi_driver.c \
../drivers/Src/stm32l47xx_adc_driver.c \
../drivers/Src/stm32l47xx_hts221.c \
../drivers/Src/stm32l47xx_i2c_driver.c \
../drivers/Src/stm32l47xx_systick.c \
../drivers/Src/stm32l47xx_usart_driver.c 

OBJS += \
./drivers/Src/led.o \
./drivers/Src/stm32l475xx_gpio_driver.o \
./drivers/Src/stm32l475xx_spi_driver.o \
./drivers/Src/stm32l47xx_adc_driver.o \
./drivers/Src/stm32l47xx_hts221.o \
./drivers/Src/stm32l47xx_i2c_driver.o \
./drivers/Src/stm32l47xx_systick.o \
./drivers/Src/stm32l47xx_usart_driver.o 

C_DEPS += \
./drivers/Src/led.d \
./drivers/Src/stm32l475xx_gpio_driver.d \
./drivers/Src/stm32l475xx_spi_driver.d \
./drivers/Src/stm32l47xx_adc_driver.d \
./drivers/Src/stm32l47xx_hts221.d \
./drivers/Src/stm32l47xx_i2c_driver.d \
./drivers/Src/stm32l47xx_systick.d \
./drivers/Src/stm32l47xx_usart_driver.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/Src/%.o drivers/Src/%.su drivers/Src/%.cyclo: ../drivers/Src/%.c drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DB_L475E_IOT01A2 -DSTM32L475VGTx -c -I"C:/Users/admin/Desktop/STM32/Mastering stm32/stm32l47xx_drivers/drivers/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-drivers-2f-Src

clean-drivers-2f-Src:
	-$(RM) ./drivers/Src/led.cyclo ./drivers/Src/led.d ./drivers/Src/led.o ./drivers/Src/led.su ./drivers/Src/stm32l475xx_gpio_driver.cyclo ./drivers/Src/stm32l475xx_gpio_driver.d ./drivers/Src/stm32l475xx_gpio_driver.o ./drivers/Src/stm32l475xx_gpio_driver.su ./drivers/Src/stm32l475xx_spi_driver.cyclo ./drivers/Src/stm32l475xx_spi_driver.d ./drivers/Src/stm32l475xx_spi_driver.o ./drivers/Src/stm32l475xx_spi_driver.su ./drivers/Src/stm32l47xx_adc_driver.cyclo ./drivers/Src/stm32l47xx_adc_driver.d ./drivers/Src/stm32l47xx_adc_driver.o ./drivers/Src/stm32l47xx_adc_driver.su ./drivers/Src/stm32l47xx_hts221.cyclo ./drivers/Src/stm32l47xx_hts221.d ./drivers/Src/stm32l47xx_hts221.o ./drivers/Src/stm32l47xx_hts221.su ./drivers/Src/stm32l47xx_i2c_driver.cyclo ./drivers/Src/stm32l47xx_i2c_driver.d ./drivers/Src/stm32l47xx_i2c_driver.o ./drivers/Src/stm32l47xx_i2c_driver.su ./drivers/Src/stm32l47xx_systick.cyclo ./drivers/Src/stm32l47xx_systick.d ./drivers/Src/stm32l47xx_systick.o ./drivers/Src/stm32l47xx_systick.su ./drivers/Src/stm32l47xx_usart_driver.cyclo ./drivers/Src/stm32l47xx_usart_driver.d ./drivers/Src/stm32l47xx_usart_driver.o ./drivers/Src/stm32l47xx_usart_driver.su

.PHONY: clean-drivers-2f-Src

