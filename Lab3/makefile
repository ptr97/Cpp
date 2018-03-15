CXX=g++
CXXFLAGS+=-Wall -Wextra -pedantic -O0 $(GXX_FLAGS)
CXXFLAGS+=-g

DEP_FLAGS=-MMD

DEP_FLAGS+=-MP

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

CXXFLAGS+=$(DEP_FLAGS)

all: vtest 

vtest: $(OBJ)
	$(CXX) $(LFLAGS) $(OBJ) -o $@

.PHONY: clean run

#.SILENT: clean

clean:
	@rm -f vtest $(OBJ) $(DEP)

run: vtest
	@./vtest
valgrind: vtest
	@valgrind --leak-check=full ./vtest
gdb: vtest
	@gdb ./vtest
-include $(DEP)
