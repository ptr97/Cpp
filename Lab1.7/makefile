CXX=g++
CXXFLAGS+=-Wall -O0 $(GXX_FLAGS)
CXXFLAGS+=-g -Wextra -pedantic

DEP_FLAGS=-MMD

DEP_FLAGS+=-MP

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

CXXFLAGS+=$(DEP_FLAGS)

all: htest

htest: $(OBJ)
	$(CXX) $(LFLAGS) $(OBJ) -o $@

.PHONY: clean run fail

#.SILENT: clean

fail: CXXFLAGS+=-DCOMPILE_ERROR
fail: $(OBJ)
	$(CXX) $(LFLAGS) $(OBJ) -o $@

clean:
	@rm -f htest $(OBJ) $(DEP)

run: htest
	@./htest
valgrind: htest
	@valgrind --leak-check=full ./htest
gdb: htest
	@gdb ./htest
-include $(DEP)
