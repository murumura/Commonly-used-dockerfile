CXX = g++
CXXFLAGS =
LIBS = -lglfw -lGL -lGLU -lX11 -lpthread -lXrandr -lXi -ldl
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
EXEC_DIR  := $(BUILD)/exec
TARGET = openGL_test
INCLUDE  := -Iinclude/
INCLUDE_DIR := include
INCLUDE_FILE := $(wildcard $(INCLUDE_DIR)/*.h)
SRCDIR = src
SRC      := $(wildcard $(SRCDIR)/*.cc)         
OBJECTS  := $(SRC:%.c=$(OBJ_DIR)/%.o)

all: build $(EXEC_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cc
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@ $(LIBS)

$(EXEC_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(EXEC_DIR)/$(TARGET) $^ $(LIBS)

.PHONY:clean format build
build:
	@mkdir -p $(EXEC_DIR)
	@mkdir -p $(OBJ_DIR)

format:
	clang-format \
	-style=\
	"{BasedOnStyle: Google,BreakBeforeBraces: Stroustrup, IndentWidth: 4, IndentCaseLabels: false, TabWidth: 4, UseTab: ForIndentation, ColumnLimit: 0}"\
	 -i $(SRC) $(wildcard $(INCLUDE_DIR)/*.cc) $(wildcard $(INCLUDE_DIR)/*.h) 
clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(EXEC_DIR)/* 
	-@rm -rvf $(BUILD)