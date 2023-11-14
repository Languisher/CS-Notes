# Makefile for C project

# 编译器设置
CC = gcc
CFLAGS = -Wall -I./include

# 源文件和目标文件路径
SRC_DIR = src
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

# 源文件列表
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# 生成的可执行文件名
TARGET = main

# 默认目标
all: $(BUILD_DIR) $(OBJ_DIR) $(TARGET) 

# 创建生成目录
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# 创建目标目录
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# 编译规则
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# 链接规则
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

# 清理规则
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean






