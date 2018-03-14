CXX=g++
CXXFLAGS+=-Wall -O0 $(GXX_FLAGS)
CXXFLAGS+=-g -Wextra -pedantic

DEP_FLAGS=-MMD

DEP_FLAGS+=-MP

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

CXXFLAGS+=$(DEP_FLAGS)

all: unique_ptr

unique_ptr: $(OBJ)
	$(CXX) $(LFLAGS) $(OBJ) -o $@

.PHONY: clean run

#.SILENT: clean

clean:
	@rm -f unique_ptr $(OBJ) $(DEP)

run: unique_ptr
	@./unique_ptr
valgrind: unique_ptr
	@valgrind --leak-check=full ./unique_ptr
gdb: unique_ptr
	@gdb ./unique_ptr
-include $(DEP)
