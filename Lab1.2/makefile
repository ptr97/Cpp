CXX=g++
CXXFLAGS+=-Wall -O0 $(GXX_FLAGS)
CXXFLAGS+=-g -Wextra -pedantic

DEP_FLAGS=-MMD

DEP_FLAGS+=-MP

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

CXXFLAGS+=$(DEP_FLAGS)

all: Lab07

Lab07: $(OBJ)
	$(CXX) $(LFLAGS) $(OBJ) -o $@

.PHONY: clean run

#.SILENT: clean

clean:
	@rm -f Lab07 $(OBJ) $(DEP)

run: Lab07
	@./Lab07
valgrind: Lab07
	@valgrind --leak-check=full ./Lab07
gdb: Lab07
	@gdb ./Lab07
-include $(DEP)
