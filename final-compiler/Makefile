CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wno-unused-function -Wno-unused-parameter -O2
BISON = bison
FLEX = flex

TARGET = swiftc_subset

SRCS = parser.tab.c lex.yy.c symbol_table.cpp tac.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
OBJS := $(OBJS:.c=.o)

all: $(TARGET)

$(TARGET): parser.tab.c parser.tab.h lex.yy.c symbol_table.cpp tac.cpp main.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) parser.tab.c lex.yy.c symbol_table.cpp tac.cpp main.cpp

parser.tab.c parser.tab.h: parser.y ast_nodes.h symbol_table.h tac.h compiler_context.h
	$(BISON) -d -Wno-other parser.y

lex.yy.c: lexer.l parser.tab.h
	$(FLEX) lexer.l

clean:
	rm -f $(TARGET) parser.tab.c parser.tab.h lex.yy.c *.o

.PHONY: all clean
