ifndef MODULE_SH_OPTIMIZATION
	MODULE_SH_OPTIMIZATION = -g3 -O0
endif

#**********************************************************************
# module_shift_register
#**********************************************************************
SH_H_FILE	:= $(shell find module_shift_register/ -maxdepth 3 -type f -name "*.h" )
SH_CPP_FILE	:= $(shell find module_shift_register/ -maxdepth 3 -type f -name "*.cpp" )
SH_DIR		:= $(shell find module_shift_register/ -maxdepth 3 -type d -name "*" )
SH_PATH		:= $(addprefix -I, $(SH_DIR))
SH_OBJ_FILE	:= $(addprefix build/obj/, $(SH_CPP_FILE))
SH_OBJ_FILE	:= $(patsubst %.cpp, %.o, $(SH_OBJ_FILE))

build/obj/module_shift_register/%.o:	module_shift_register/%.cpp
	@echo [CPP] $<
	@mkdir -p $(dir $@)
	@$(CPP) $(CPP_FLAGS) $(MK_INTER_PATH) $(SH_PATH) $(USER_CFG_PATH) $(STM32_F2_API_PATH) $(FREE_RTOS_PATH)  $(MODULE_SH_OPTIMIZATION) -c $< -o $@

# Добавляем к общим переменным проекта.
PROJECT_PATH			+= $(SH_PATH)
PROJECT_OBJ_FILE		+= $(SH_OBJ_FILE)