################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := TP_[3]
BUILD_ARTIFACT_EXTENSION :=
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: TP_[3]

# Tool invocations
TP_[3]: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: MacOS X C Linker'
	gcc  -o "TP_[3]" $(OBJS) $(USER_OBJS) $(LIBS)/Users/moreescudero/eclipse-workspace/TP_[3]/LinkedList.a
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) TP_[3]
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
