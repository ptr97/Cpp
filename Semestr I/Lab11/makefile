CXX=g++
CXXFLAGS+=-Wall -Wextra -pedantic -O0 $(GXX_FLAGS)
CXXFLAGS+=-g

DEP_FLAGS=-MMD

DEP_FLAGS+=-MP

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

CXXFLAGS+=$(DEP_FLAGS)

all: Katy

Katy: $(OBJ)
	$(CXX) $(LFLAGS) $(OBJ) -o $@

.PHONY: clean run

#.SILENT: clean

clean:
	@rm -f Katy $(OBJ) $(DEP)

run: Katy
	@./Katy
valgrind: Katy
	@valgrind --leak-check=full ./Katy
gdb: Katy
	@gdb ./Katy
-include $(DEP)
