CXX=g++
CXXFLAGS+=-Wall -Wextra -pedantic -O0 $(GXX_FLAGS)
CXXFLAGS+=-g

DEP_FLAGS=-MMD

DEP_FLAGS+=-MP

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

CXXFLAGS+=$(DEP_FLAGS)

all: Mario

Mario: $(OBJ)
	$(CXX) $(LFLAGS) $(OBJ) -o $@

.PHONY: clean run

#.SILENT: clean

clean:
	@rm -f Mario $(OBJ) $(DEP)

run: Mario
	@./Mario
valgrind: Mario
	@valgrind --leak-check=full ./Mario
gdb: Mario
	@gdb ./Mario
-include $(DEP)
