EXE = main
EXT = .cpp
SRC = $(wildcard *$(EXT)) $(wildcard **/*$(EXT))
OBJ = $(patsubst %$(EXT),%.o,$(SRC))
##
CXX = g++
CPPFLAGS =
CFLAGS = -std=c++0x -g
LDFLAGS =
LOADLIBES =
LDLIBS =

#No configuration needed below here

all: $(OBJ) $(EXE)

$(EXE) : $(OBJ)
	$(CXX) -o $(EXE) $(OBJ) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)

%.o :: %$(EXT)
	$(CXX) -c $< -o $@ $(CPPFLAGS) $(CFLAGS)

.PHONY : clean
clean :
	rm -i $(realpath $(OBJ))