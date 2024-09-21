# 设置编译器
CC = g++

# 设置编译选项
CXXFLAGS = -std=c++20 -Wall -g

# 指定搜索头文件的目录
INCLUDES = -I./net_src/

# 指定源文件和目标文件
SOURCES = main.cpp test.cpp Singleton.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = my_program

#链接到openssl库
#LIBS = -lssl -lcrypto

all: $(EXECUTABLE)

# 规则：构建可执行文件
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)


	

# 规则：编译.cpp文件到.o文件
%.o: %.cpp
	$(CC) -c $< -o $@ $(CXXFLAGS)

# 清理规则
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

# 默认目标（运行make时如果没有指定目标，则执行这个）
.DEFAULT_GOAL := all
