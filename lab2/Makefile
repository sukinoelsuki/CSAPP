CC = gcc
CFLAGS = -Wall -O0 -g

BUILD_DIR = build
TARGET = $(BUILD_DIR)/lab2_main.exe

# 自动搜寻 .c 和大写的 .S 文件
C_SOURCES   = $(wildcard *.c)
ASM_SOURCES = $(wildcard *.S)

# 统一映射到 build/ 目录下的 .o
OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(notdir $(C_SOURCES))) \
       $(patsubst %.S, $(BUILD_DIR)/%.o, $(notdir $(ASM_SOURCES)))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# 编译 C
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# 编译大写 .S（同样直接用 CC 编译，它会自动识别并处理预处理）
$(BUILD_DIR)/%.o: %.S
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean

clean:
	@echo "Cleaning up..."
	@rm -rf $(BUILD_DIR)