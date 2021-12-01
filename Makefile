CC = gcc
CF = -g
CL = 

SRC = src/main.c src/tic.c
ALL = $(SRC)
OUT := build/tic

# Windows
ifeq ($(OS),Windows_NT)
	OUT := $(OUT).exe
else
	CL := -lm
	OUT := $(OUT).o
endif

$(OUT): $(ALL)
	$(CC) $(CF) -o $@ $(SRC) $(CL)
