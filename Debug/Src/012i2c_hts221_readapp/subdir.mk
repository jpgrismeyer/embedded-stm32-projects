################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/012i2c_hts221_readapp/012i2c_hts221_readapp.c 

OBJS += \
./Src/012i2c_hts221_readapp/012i2c_hts221_readapp.o 

C_DEPS += \
./Src/012i2c_hts221_readapp/012i2c_hts221_readapp.d 


# Each subdirectory must supply rules for building sources it contributes
Src/012i2c_hts221_readapp/%.o Src/012i2c_hts221_readapp/%.su Src/012i2c_hts221_readapp/%.cyclo: ../Src/012i2c_hts221_readapp/%.c Src/012i2c_hts221_readapp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DB_L475E_IOT01A2 -DSTM32L475VGTx -c -I"C:/Users/admin/Desktop/STM32/Mastering stm32/stm32l47xx_drivers/drivers/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-012i2c_hts221_readapp

clean-Src-2f-012i2c_hts221_readapp:
	-$(RM) ./Src/012i2c_hts221_readapp/012i2c_hts221_readapp.cyclo ./Src/012i2c_hts221_readapp/012i2c_hts221_readapp.d ./Src/012i2c_hts221_readapp/012i2c_hts221_readapp.o ./Src/012i2c_hts221_readapp/012i2c_hts221_readapp.su

.PHONY: clean-Src-2f-012i2c_hts221_readapp

