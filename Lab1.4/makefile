CXX=g++
CXXFLAGS+=-Wall -O0 $(GXX_FLAGS)
CXXFLAGS+=-g -Wextra -pedantic

DEP_FLAGS=-MMD

DEP_FLAGS+=-MP

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

CXXFLAGS+=$(DEP_FLAGS)

all: Lab08

Lab08: $(OBJ)
	$(CXX) $(LFLAGS) $(OBJ) -o $@

.PHONY: clean run

#.SILENT: clean

clean:
	@rm -f Lab08 $(OBJ) $(DEP)

run: Lab08
	@./Lab08
valgrind: Lab08
	@valgrind --leak-check=full ./Lab08
gdb: Lab08
	@gdb ./Lab08
-include $(DEP)
