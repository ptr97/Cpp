CXX=g++
CXXFLAGS+=-Wall -O0 $(GXX_FLAGS)
CXXFLAGS+=-g -Wextra -pedantic

DEP_FLAGS=-MMD

DEP_FLAGS+=-MP

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

CXXFLAGS+=$(DEP_FLAGS)

all: otest

otest: $(OBJ)
	$(CXX) $(LFLAGS) $(OBJ) -o $@

.PHONY: clean run

#.SILENT: clean

clean:
	@rm -f otest $(OBJ) $(DEP)

run: otest
	@./otest
valgrind: otest
	@valgrind --leak-check=full ./otest
gdb: otest
	@gdb ./otest
-include $(DEP)
