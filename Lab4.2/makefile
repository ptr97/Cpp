CXX=g++
CXXFLAGS+=-Wall -O0 $(GXX_FLAGS)
CXXFLAGS+=-g -Wextra -pedantic

DEP_FLAGS=-MMD

DEP_FLAGS+=-MP

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

CXXFLAGS+=$(DEP_FLAGS)

all: bib

bib: $(OBJ)
	$(CXX) $(LFLAGS) $(OBJ) -o $@

.PHONY: clean run

#.SILENT: clean

clean:
	@rm -f bib $(OBJ) $(DEP)

run: bib
	@./bib
valgrind: bib
	@valgrind --leak-check=full ./bib
gdb: bib
	@gdb ./bib
-include $(DEP)
