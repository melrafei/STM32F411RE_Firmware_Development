################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Workspace_FreeRTOS/FreeRTOS-Kernel/portable/MemMang/heap_4.c 

OBJS += \
./Workspace_FreeRTOS/FreeRTOS-Kernel/portable/MemMang/heap_4.o 

C_DEPS += \
./Workspace_FreeRTOS/FreeRTOS-Kernel/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
Workspace_FreeRTOS/FreeRTOS-Kernel/portable/MemMang/%.o Workspace_FreeRTOS/FreeRTOS-Kernel/portable/MemMang/%.su Workspace_FreeRTOS/FreeRTOS-Kernel/portable/MemMang/%.cyclo: ../Workspace_FreeRTOS/FreeRTOS-Kernel/portable/MemMang/%.c Workspace_FreeRTOS/FreeRTOS-Kernel/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I"C:/ST/Projects/002_STM32CubeMXIDE/STM32CubeMXIDE/Workspace_FreeRTOS/FreeRTOS-Kernel/include" -I"C:/ST/Projects/002_STM32CubeMXIDE/STM32CubeMXIDE/Workspace_FreeRTOS/FreeRTOS-Kernel/portable/GCC/ARM_CM4F" -I"C:/ST/Projects/002_STM32CubeMXIDE/STM32CubeMXIDE/Workspace_FreeRTOS/FreeRTOS-Kernel/portable/MemMang" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Workspace_FreeRTOS-2f-FreeRTOS-2d-Kernel-2f-portable-2f-MemMang

clean-Workspace_FreeRTOS-2f-FreeRTOS-2d-Kernel-2f-portable-2f-MemMang:
	-$(RM) ./Workspace_FreeRTOS/FreeRTOS-Kernel/portable/MemMang/heap_4.cyclo ./Workspace_FreeRTOS/FreeRTOS-Kernel/portable/MemMang/heap_4.d ./Workspace_FreeRTOS/FreeRTOS-Kernel/portable/MemMang/heap_4.o ./Workspace_FreeRTOS/FreeRTOS-Kernel/portable/MemMang/heap_4.su

.PHONY: clean-Workspace_FreeRTOS-2f-FreeRTOS-2d-Kernel-2f-portable-2f-MemMang

