# Компилятор и флаги
CC := g++
CFLAGS := -g -Wall -std=c++17

# Флаги линковки
LDFLAGS := -lfmt
TESTLDFLAGS := $(LDFLAGS) -lgtest -lgmock -lgtest_main -lpthread

# Пути
SRC_DIR := src
CLI_DIR := cli
TEST_DIR := __tests__
OBJ_DIR := obj
GTEST_INCLUDE := /usr/include/gtest
GTEST_LIB := /usr/lib

# Исполняемые файлы
APP_EXEC := app
TEST_EXEC := run_tests

# Исходные и объектные файлы
APP_SRCS := main.cpp $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(CLI_DIR)/*.cpp)
APP_OBJS := $(APP_SRCS:%.cpp=$(OBJ_DIR)/%.o)
TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS := $(filter-out $(OBJ_DIR)/main.o, $(APP_OBJS)) $(TEST_SRCS:%.cpp=$(OBJ_DIR)/%.o)

# Цели
.PHONY: all clean

all: $(APP_EXEC) $(TEST_EXEC)

$(APP_EXEC): $(APP_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(TEST_EXEC): $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L$(GTEST_LIB) $(TESTLDFLAGS)

# Общее правило для компиляции
$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I. -I$(SRC_DIR) -I$(GTEST_INCLUDE) -c $< -o $@

$(OBJ_DIR)/main.o: main.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I. -I$(SRC_DIR) -I$(GTEST_INCLUDE) -c main.cpp -o $(OBJ_DIR)/main.o

clean:
	rm -rf $(OBJ_DIR) $(APP_EXEC) $(TEST_EXEC)
