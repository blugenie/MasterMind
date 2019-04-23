#Makefile of Mastermind.exe
.PHONY: all clean

all: mastermind.exe

mastermind.exe: main.cpp
	g++ -std=c11 -Wall main.cpp -o mastermind.exe
	
clean:
	del mastermind.exe





