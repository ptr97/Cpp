CXX = g++
CXXFLAGS = -g -Wall -Wextra -pedantic -O0
CXXFLAGS += -std=c++11

SRC = $(wildcard *.cpp)
HDR = $(wildcard *.h)
OBJ = $(SRC:.cpp=.o)

APP = Program
ZIP = $(APP).zip

all: $(APP)

rebuild: clean $(APP)

$(APP): $(OBJ)
	$(CXX) $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

zip: $(SRC) $(HDR)
	tar czf $(ZIP) $^ makefile

run: $(APP)
	@./$(APP)

crun: $(APP)
	@clear
	@./$(APP)

valgrind: $(APP)
	@valgrind --leak-check=full ./$(APP)

gdb: $(APP)
	@gdb ./$(APP)

clean: 
	@rm -f $(APP) $(OBJ)

.PHONY: all rebuild zip run crun valgrind gdb clean
