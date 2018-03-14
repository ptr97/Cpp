CXX=g++
CXXFLAGS+=-Wall -O0 $(GXX_FLAGS)
CXXFLAGS+=-g -Wextra -pedantic

DEP_FLAGS=-MMD

DEP_FLAGS+=-MP

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

CXXFLAGS+=$(DEP_FLAGS)

all: Lab09

Lab09: $(OBJ)
	$(CXX) $(LFLAGS) $(OBJ) -o $@

.PHONY: clean run

#.SILENT: clean

clean:
	@rm -f Lab09 $(OBJ) $(DEP)

run: Lab09
	@./Lab09
valgrind: Lab09
	@valgrind --leak-check=full ./Lab09
gdb: Lab09
	@gdb ./Lab09
-include $(DEP)
