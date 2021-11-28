CC = g++
CF = -g
CL = 

OUT = 

# Windows
ifeq ($(OS),Windows_NT)
	
else
	CL += -lm
endif


