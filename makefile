damero:	main.o Pieza.o
	g++ main.o Pieza.o -lncurses -o damero

main.o:	main.cpp Pieza.h
	g++ -c main.cpp

pieza.o:	Pieza.cpp Pieza.h
	g++ -c Pieza.cpp
