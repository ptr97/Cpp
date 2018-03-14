CXX=g++
CXXFLAGS+=-Wall -Wextra -pedantic -O0 $(GXX_FLAGS)
CXXFLAGS+=-g

DEP_FLAGS=-MMD

DEP_FLAGS+=-MP

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

CXXFLAGS+=$(DEP_FLAGS)

all: Fraction

Fraction: $(OBJ)
	$(CXX) $(LFLAGS) $(OBJ) -o $@

.PHONY: clean run

#.SILENT: clean

clean:
	@rm -f Fraction $(OBJ) $(DEP)

run: Fraction
	@./Fraction
valgrind: Fraction
	@valgrind --leak-check=full ./Fraction
gdb: Fraction
	@gdb ./Fraction
-include $(DEP)
