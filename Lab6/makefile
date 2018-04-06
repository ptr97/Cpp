CXX=g++
CXXFLAGS+=-std=c++11 -Wall -Wextra -pedantic -O0 $(GXX_FLAGS)
CXXFLAGS+=-g

DEP_FLAGS=-MMD

DEP_FLAGS+=-MP

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

CXXFLAGS+=$(DEP_FLAGS)

all: mtest

mtest: $(OBJ)
	$(CXX) $(LFLAGS) $(OBJ) -o $@

.PHONY: clean run

#.SILENT: clean

clean:
	@rm -f mtest $(OBJ) $(DEP)

run: mtest
	@./mtest
valgrind: mtest
	@valgrind --leak-check=full ./mtest
gdb: mtest
	@gdb ./mtest
-include $(DEP)
