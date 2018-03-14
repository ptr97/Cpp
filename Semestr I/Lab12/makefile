CXX=g++
CXXFLAGS+=-Wall -Wextra -pedantic -O0 $(GXX_FLAGS)
CXXFLAGS+=-g

DEP_FLAGS=-MMD

DEP_FLAGS+=-MP

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

CXXFLAGS+=$(DEP_FLAGS)

all: Point

Point: $(OBJ)
	$(CXX) $(LFLAGS) $(OBJ) -o $@

.PHONY: clean run

#.SILENT: clean

clean:
	@rm -f Point $(OBJ) $(DEP)

run: Point
	@./Point
valgrind: Point
	@valgrind --leak-check=full ./Point
gdb: Point
	@gdb ./Point
-include $(DEP)
