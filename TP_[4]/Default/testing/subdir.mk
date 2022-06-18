################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../testing/utest.c 

C_DEPS += \
./testing/utest.d 

OBJS += \
./testing/utest.o 


# Each subdirectory must supply rules for building sources it contributes
testing/%.o: ../testing/%.c testing/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-testing

clean-testing:
	-$(RM) ./testing/utest.d ./testing/utest.o

.PHONY: clean-testing

