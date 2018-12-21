# all: main
# main: main.o stack.o maze.o
# 	gcc $^ -o $@

# clean:
# 	-rm main *.o
# .PHONY:  clean
	
# sources = main.c stack.c maze.c
# include $(sources:.c=.d)
# %.d: %.c
# 	set -e; rm -f $@; \
# 	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
# 	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
# 	rm -f $@.$$$$


# foo = $(bar)
# bar = Huh?
# nullstring :=
# nullstring ?= 1
# nullstring += $(shitman)
# shitman = shit
# all:
# 	@echo $(foo)
# 	@echo $(nullstring)

	
######################################
#无法工作，问题：连接文件夹里面的文件？
######################################
#source file
#源文件，自动找所有.c和.cpp文件，并将目标定义为同名.o文件
SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))
  
#target you can change test to what you want
#目标文件名，输入任意你想要的执行文件名
TARGET  := main
  
#compile and lib parameter
#编译参数
CC      := gcc
LIBS    := -lm -lpthread
LDFLAGS :=	
DEFINES :=
INCLUDE := -I ../include
CFLAGS  := -g -Wall -O0 $(DEFINES) $(INCLUDE)
CXXFLAGS:= $(CFLAGS) -DHAVE_CONFIG_H
  
  
#i think you should do anything here
#下面的基本上不需要做任何改动了
.PHONY : everything objs clean veryclean rebuild
  
everything : $(TARGET)
  
all : $(TARGET)
  
objs : $(OBJS)
  
rebuild: veryclean everything
                
clean :
	-rm -fr *.so
	-rm -fr *.o

veryclean : clean
	-rm -fr $(TARGET)
$(TARGET) : $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)