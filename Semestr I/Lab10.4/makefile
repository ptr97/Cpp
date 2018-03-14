CXX=g++
CXXFLAGS+=-Wall -O0 $(GXX_FLAGS)
CXXFLAGS+=-g -Wextra -pedantic

DEP_FLAGS=-MMD

DEP_FLAGS+=-MP

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

CXXFLAGS+=$(DEP_FLAGS)

all: StudentGrades

StudentGrades: $(OBJ)
	$(CXX) $(LFLAGS) $(OBJ) -o $@

.PHONY: clean run

#.SILENT: clean

clean:
	@rm -f StudentGrades $(OBJ) $(DEP)

run: StudentGrades
	@./StudentGrades
valgrind: StudentGrades
	@valgrind --leak-check=full ./StudentGrades
gdb: StudentGrades
	@gdb ./StudentGrades
-include $(DEP)
