<<<<<<< HEAD
<<<<<<< HEAD
################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/LinkedList.c \
../src/main.c 

C_DEPS += \
./src/LinkedList.d \
./src/main.d 

OBJS += \
./src/LinkedList.o \
./src/main.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/LinkedList.d ./src/LinkedList.o ./src/main.d ./src/main.o

.PHONY: clean-src

=======
################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/LinkedList.c \
../src/main.c 

C_DEPS += \
./src/LinkedList.d \
./src/main.d 

OBJS += \
./src/LinkedList.o \
./src/main.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/LinkedList.d ./src/LinkedList.o ./src/main.d ./src/main.o

.PHONY: clean-src

>>>>>>> 6833bf949f6a750f15c7f7d0a71e40e671c423c3
=======
################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/LinkedList.c \
../src/main.c 

C_DEPS += \
./src/LinkedList.d \
./src/main.d 

OBJS += \
./src/LinkedList.o \
./src/main.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/LinkedList.d ./src/LinkedList.o ./src/main.d ./src/main.o

.PHONY: clean-src

>>>>>>> 6833bf949f6a750f15c7f7d0a71e40e671c423c3
