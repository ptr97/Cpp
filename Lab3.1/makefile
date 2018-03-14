CXX=g++
CXXFLAGS+=-Wall -O0 $(GXX_FLAGS)
CXXFLAGS+=-g -Wextra -pedantic

DEP_FLAGS=-MMD

DEP_FLAGS+=-MP

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

CXXFLAGS+=$(DEP_FLAGS)

all: RuchomeObrazki

RuchomeObrazki: $(OBJ)
	$(CXX) $(LFLAGS) $(OBJ) -o $@

.PHONY: clean run

#.SILENT: clean

clean:
	@rm -f RuchomeObrazki $(OBJ) $(DEP)

run: RuchomeObrazki
	@./RuchomeObrazki
valgrind: RuchomeObrazki
	@valgrind --leak-check=full ./RuchomeObrazki
gdb: RuchomeObrazki
	@gdb ./RuchomeObrazki
-include $(DEP)
