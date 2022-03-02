# SHELL := /bin/bash

TARGET = main

SRC_DIR = .
SRC_SUBDIR += . ./ad9208_api ./util ./platform_drivers
INCLUDE_DIR += . ./ad9208_api ./include ./platform_drivers
OBJ_DIR = build

CC = gcc
C_FLAGS = -g -Wall
LD = $(CC)
INCLUDES += ${addprefix -I, $(INCLUDE_DIR)}
LD_FLAFS += 
LD_LIBS =

ifeq ($(CC), g++)
	TYPE = cpp
else
	TYPE = c
endif

SRCS += ${foreach subdir, $(SRC_SUBDIR), ${wildcard $(SRC_DIR)/$(subdir)/*.$(TYPE)}}
OBJS += ${foreach src, $(notdir $(SRCS)), ${patsubst %.$(TYPE), $(OBJ_DIR)/%.o, $(src)}}

VPATH := $(SRC_DIR) $(SRC_SUBDIR)

all : $(TARGET)
	@echo "Builded target:" $^
	@echo "Done"

$(TARGET) : $(OBJS)
	@mkdir -p $(@D)
	@echo "Linking" $@ "from" $^ "..."
	$(LD) -o $@ $^ $(LD_FLAGS) $(LD_LIBS)
	@echo "Link finished\n"

$(OBJS) : $(OBJ_DIR)/%.o : %.$(TYPE)
	@mkdir -p $(@D)
	@echo "Compiling" $@ "from" $< "..."
	$(CC) -c -o $@ $< $(C_FLAGS) $(INCLUDES)
	@echo "Compile finished\n"

test : 
	@echo $(SRCS)
	@echo $(OBJS)
	@echo $(INCLUDES)

.PHONY : clean cleanobj
clean : cleanobj
	@echo "Remove all executable files"
	rm -f $(TARGET)
cleanobj :
	@echo "Remove object files"
	rm -rf $(OBJ_DIR)/*.o


# gcc -c MVBGen.c MVBCModel.c
# gcc MVBGen.o MVBCModel.o -o MVBGen.exe -fexec-charset=gbk -finput-charset=UTF-8