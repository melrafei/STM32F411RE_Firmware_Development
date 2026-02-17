################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Workspace_FreeRTOS/FreeRTOS-Kernel/croutine.c \
../Workspace_FreeRTOS/FreeRTOS-Kernel/event_groups.c \
../Workspace_FreeRTOS/FreeRTOS-Kernel/list.c \
../Workspace_FreeRTOS/FreeRTOS-Kernel/queue.c \
../Workspace_FreeRTOS/FreeRTOS-Kernel/stream_buffer.c \
../Workspace_FreeRTOS/FreeRTOS-Kernel/tasks.c \
../Workspace_FreeRTOS/FreeRTOS-Kernel/timers.c 

OBJS += \
./Workspace_FreeRTOS/FreeRTOS-Kernel/croutine.o \
./Workspace_FreeRTOS/FreeRTOS-Kernel/event_groups.o \
./Workspace_FreeRTOS/FreeRTOS-Kernel/list.o \
./Workspace_FreeRTOS/FreeRTOS-Kernel/queue.o \
./Workspace_FreeRTOS/FreeRTOS-Kernel/stream_buffer.o \
./Workspace_FreeRTOS/FreeRTOS-Kernel/tasks.o \
./Workspace_FreeRTOS/FreeRTOS-Kernel/timers.o 

C_DEPS += \
./Workspace_FreeRTOS/FreeRTOS-Kernel/croutine.d \
./Workspace_FreeRTOS/FreeRTOS-Kernel/event_groups.d \
./Workspace_FreeRTOS/FreeRTOS-Kernel/list.d \
./Workspace_FreeRTOS/FreeRTOS-Kernel/queue.d \
./Workspace_FreeRTOS/FreeRTOS-Kernel/stream_buffer.d \
./Workspace_FreeRTOS/FreeRTOS-Kernel/tasks.d \
./Workspace_FreeRTOS/FreeRTOS-Kernel/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Workspace_FreeRTOS/FreeRTOS-Kernel/%.o Workspace_FreeRTOS/FreeRTOS-Kernel/%.su Workspace_FreeRTOS/FreeRTOS-Kernel/%.cyclo: ../Workspace_FreeRTOS/FreeRTOS-Kernel/%.c Workspace_FreeRTOS/FreeRTOS-Kernel/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I"C:/ST/Projects/002_STM32CubeMXIDE/STM32CubeMXIDE/Workspace_FreeRTOS/FreeRTOS-Kernel/include" -I"C:/ST/Projects/002_STM32CubeMXIDE/STM32CubeMXIDE/Workspace_FreeRTOS/FreeRTOS-Kernel/portable/GCC/ARM_CM4F" -I"C:/ST/Projects/002_STM32CubeMXIDE/STM32CubeMXIDE/Workspace_FreeRTOS/FreeRTOS-Kernel/portable/MemMang" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Workspace_FreeRTOS-2f-FreeRTOS-2d-Kernel

clean-Workspace_FreeRTOS-2f-FreeRTOS-2d-Kernel:
	-$(RM) ./Workspace_FreeRTOS/FreeRTOS-Kernel/croutine.cyclo ./Workspace_FreeRTOS/FreeRTOS-Kernel/croutine.d ./Workspace_FreeRTOS/FreeRTOS-Kernel/croutine.o ./Workspace_FreeRTOS/FreeRTOS-Kernel/croutine.su ./Workspace_FreeRTOS/FreeRTOS-Kernel/event_groups.cyclo ./Workspace_FreeRTOS/FreeRTOS-Kernel/event_groups.d ./Workspace_FreeRTOS/FreeRTOS-Kernel/event_groups.o ./Workspace_FreeRTOS/FreeRTOS-Kernel/event_groups.su ./Workspace_FreeRTOS/FreeRTOS-Kernel/list.cyclo ./Workspace_FreeRTOS/FreeRTOS-Kernel/list.d ./Workspace_FreeRTOS/FreeRTOS-Kernel/list.o ./Workspace_FreeRTOS/FreeRTOS-Kernel/list.su ./Workspace_FreeRTOS/FreeRTOS-Kernel/queue.cyclo ./Workspace_FreeRTOS/FreeRTOS-Kernel/queue.d ./Workspace_FreeRTOS/FreeRTOS-Kernel/queue.o ./Workspace_FreeRTOS/FreeRTOS-Kernel/queue.su ./Workspace_FreeRTOS/FreeRTOS-Kernel/stream_buffer.cyclo ./Workspace_FreeRTOS/FreeRTOS-Kernel/stream_buffer.d ./Workspace_FreeRTOS/FreeRTOS-Kernel/stream_buffer.o ./Workspace_FreeRTOS/FreeRTOS-Kernel/stream_buffer.su ./Workspace_FreeRTOS/FreeRTOS-Kernel/tasks.cyclo ./Workspace_FreeRTOS/FreeRTOS-Kernel/tasks.d ./Workspace_FreeRTOS/FreeRTOS-Kernel/tasks.o ./Workspace_FreeRTOS/FreeRTOS-Kernel/tasks.su ./Workspace_FreeRTOS/FreeRTOS-Kernel/timers.cyclo ./Workspace_FreeRTOS/FreeRTOS-Kernel/timers.d ./Workspace_FreeRTOS/FreeRTOS-Kernel/timers.o ./Workspace_FreeRTOS/FreeRTOS-Kernel/timers.su

.PHONY: clean-Workspace_FreeRTOS-2f-FreeRTOS-2d-Kernel

