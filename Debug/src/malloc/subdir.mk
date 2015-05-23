################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/malloc/_malloc.c 

OBJS += \
./src/malloc/_malloc.o 

C_DEPS += \
./src/malloc/_malloc.d 


# Each subdirectory must supply rules for building sources it contributes
src/malloc/%.o: ../src/malloc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


