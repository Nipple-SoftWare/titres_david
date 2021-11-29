CC = g++
CF = -g
CL = 

IN = src/main.cpp
ALL = $(IN)
OUT := build/titres

# Windows
ifeq ($(OS),Windows_NT)
	OUT := $(OUT).exe
else
	CL := -lm
	OUT := $(OUT).o
endif

$(OUT): $(ALL)
	$(CC) $(CF) -o $@ $(IN) $(CL)

#
##    #
    ####
   #####