CC = gcc
CF = -g
CL = 

SRC = src/main.c src/tetris.c
ALL = $(SRC)
OUT := build/titres

# Windows
ifeq ($(OS),Windows_NT)
	OUT := $(OUT).exe
else
	CL := -lm
	OUT := $(OUT).o
endif

$(OUT): $(ALL)
	$(CC) $(CF) -o $@ $(SRC) $(CL)
