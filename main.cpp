#include <ncurses.h>
#include "Pieza.h"
void imprimirTavlero(Pieza**);
int caracterAEntero(char);
int main(int argc, char const *argv[]){
	initscr();
	Pieza** matriz = new Pieza*[7];
	start_color();
	init_pair(1,COLOR_WHITE,COLOR_RED);
	init_pair(2,COLOR_WHITE,COLOR_GREEN);
	do{
		imprimirTavlero(matriz);
		refresh();
	}while(true);
	return 0;
}
void imprimirTavlero(Pieza** matriz){
	for(int FILA = 0; FILA < 8; FILA++){
		matriz[FILA] = new Pieza[7];
		for(int COLUMNA = 0; COLUMNA < 8; COLUMNA++){
			int x = COLUMNA * 5;
			Pieza matriz[FILA][COLUMNA];
			for(int i = 0; i < 5; i++){
				move(FILA * 5 + i, COLUMNA * 7);
				if((COLUMNA + FILA) % 2 == 0){
					attrset (COLOR_PAIR(1));
				}else{
					attrset (COLOR_PAIR(2));
				}
				if(matriz[FILA][COLUMNA].estaViva()){
					printw("       ");
				}else{					
					printw("       ");
				}
			}
		}
	}
}
int caracterAEntero(char x){
	char letras[9] = "abcdefgh";
	for(int LETRA = 0; LETRA < 8; LETRA++){
		if(letras[LETRA] == x){
			return LETRA;
		}
	} 
	return -1;
}
