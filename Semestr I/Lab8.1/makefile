CXX=g++
CXXFLAGS+=-Wall -O0 $(GXX_FLAGS)
CXXFLAGS+=-g -Wextra -pedantic

DEP_FLAGS=-MMD

DEP_FLAGS+=-MP

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

CXXFLAGS+=$(DEP_FLAGS)

all: MapaKlasa

MapaKlasa: $(OBJ)
	$(CXX) $(LFLAGS) $(OBJ) -o $@

.PHONY: clean run

#.SILENT: clean

clean:
	@rm -f MapaKlasa $(OBJ) $(DEP)

run: MapaKlasa
	@./MapaKlasa
valgrind: MapaKlasa
	@valgrind --leak-check=full ./MapaKlasa
gdb: MapaKlasa
	@gdb ./MapaKlasa
-include $(DEP)
