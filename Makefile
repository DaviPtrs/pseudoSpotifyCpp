CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:=
EXECUTABLE	:= main


all: clean $(BIN)/$(EXECUTABLE)

dbg: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE) -u tests/usuarios.csv -f tests/favoritos.csv -g tests/generos.csv -m tests/midias.csv

set1: clean all
	clear
	./$(BIN)/$(EXECUTABLE) -u tests/set1/usuarios.csv -f tests/set1/favoritos.csv -g tests/set1/generos.csv -m tests/set1/midias.csv

set2: clean all
	clear
	./$(BIN)/$(EXECUTABLE) -u tests/set2/usuarios.csv -f tests/set2/favoritos.csv -g tests/set2/generos.csv -m tests/set2/midias.csv

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
