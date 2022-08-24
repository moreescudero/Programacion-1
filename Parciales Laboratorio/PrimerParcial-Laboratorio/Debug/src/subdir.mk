################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/PrimerParcial-Laboratorio.c \
../src/estructuras.c \
../src/funciones.c 

C_DEPS += \
./src/PrimerParcial-Laboratorio.d \
./src/estructuras.d \
./src/funciones.d 

OBJS += \
./src/PrimerParcial-Laboratorio.o \
./src/estructuras.o \
./src/funciones.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/PrimerParcial-Laboratorio.d ./src/PrimerParcial-Laboratorio.o ./src/estructuras.d ./src/estructuras.o ./src/funciones.d ./src/funciones.o

.PHONY: clean-src

