# 编译器
CC = g++
# 输出文件名
TARGET = main

# 源文件
SOURCES = main.cpp 

# 头文件路径
INCLUDES = -I.

# 目标文件
OBJECTS = $(SOURCES:.cpp=.o)

# 编译规则
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o: %.cpp
	$(CC) -c $< -o $@ $(INCLUDES)

# 清理
clean:
	rm -f $(OBJECTS) $(TARGET)
