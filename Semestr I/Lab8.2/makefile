CXX=g++
CXXFLAGS+=-Wall -O0 $(GXX_FLAGS)
CXXFLAGS+=-g -Wextra -pedantic

DEP_FLAGS=-MMD

DEP_FLAGS+=-MP

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

CXXFLAGS+=$(DEP_FLAGS)

all: ListaStudentow

ListaStudentow: $(OBJ)
	$(CXX) $(LFLAGS) $(OBJ) -o $@

.PHONY: clean run

#.SILENT: clean

clean:
	@rm -f ListaStudentow $(OBJ) $(DEP)

run: ListaStudentow
	@./ListaStudentow
valgrind: ListaStudentow
	@valgrind --leak-check=full ./ListaStudentow
gdb: ListaStudentow
	@gdb ./ListaStudentow
-include $(DEP)
