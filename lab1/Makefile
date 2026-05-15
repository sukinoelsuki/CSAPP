CC = gcc
CFLAGS = -g -Wall -fdiagnostics-color=always -std=c99

# 1. 确保路径使用正斜杠
BUILD_DIR = build
TARGET = $(BUILD_DIR)/lab1_main.exe

# 2. 扫描源码
SRCS = $(wildcard *.c)
# 将 .c 映射到 build/ 目录下的 .o
OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRCS))

# 3. 声明伪目标，防止与同名文件冲突
.PHONY: all clean

# 4. 默认目标
all: $(BUILD_DIR) $(TARGET)

# 5. 链接规则：确保链接的是 build 目录下的所有 .o
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 6. 编译规则：模式匹配编译到 build/
$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 7. 创建目录：使用 -p 避免重复创建报错
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# 8. 清理规则
clean:
	rm -rf $(BUILD_DIR)