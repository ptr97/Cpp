CXX=g++
CXXFLAGS+=-std=c++11 -Wall -O0 $(GXX_FLAGS)
CXXFLAGS+=-g -Wextra -pedantic

DEP_FLAGS=-MMD

DEP_FLAGS+=-MP

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

CXXFLAGS+=$(DEP_FLAGS)

all: ltest

ltest: $(OBJ)
	$(CXX) $(LFLAGS) $(OBJ) -o $@

.PHONY: clean run

#.SILENT: clean

clean:
	@rm -f ltest $(OBJ) $(DEP)

run: ltest
	@./ltest
valgrind: ltest
	@valgrind --leak-check=full ./ltest
gdb: ltest
	@gdb ./ltest
-include $(DEP)
