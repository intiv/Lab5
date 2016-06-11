#include <ncurses.h>
#include "Pieza.h"
void imprimirTavlero(Pieza**);
int caracterAEntero(char);
void iniciarMatriz(Pieza**);

int main(int argc, char const *argv[]){
	initscr();
	Pieza** matriz = new Pieza*[7];
	start_color();
	iniciarMatriz(matriz);
	int cont1=0, cont2=0;
	for(int i=0;i<8;i++){
		for(int j=65;j<73;j++){
			mvprintw(i,j,"%d",matriz[cont1][cont2].estaViva());
			cont2++;
		}
		cont1++;
	}

	init_pair(1,COLOR_WHITE,COLOR_RED);
	init_pair(3,COLOR_BLACK,COLOR_RED);
	init_pair(2,COLOR_WHITE,COLOR_GREEN);
	move(2, 60);
	printw("%d", matriz[2][2].mover(1,3 , matriz));
	do{
		imprimirTavlero(matriz);
		getch();
		refresh();
	}while(true);
	return 0;
}
void imprimirTavlero(Pieza** matriz){
	for(int FILA = 0; FILA < 8; FILA++){
		for(int COLUMNA = 0; COLUMNA < 8; COLUMNA++){
			int x = COLUMNA * 5;
			for(int i = 0; i < 5; i++){
				move(FILA * 5 + i, COLUMNA * 7);
				if((COLUMNA + FILA) % 2 == 0){
					attrset (COLOR_PAIR(1));
				}else{
					attrset (COLOR_PAIR(2));
				}
				if(matriz[FILA][COLUMNA].estaViva()){
					if(matriz[FILA][COLUMNA].esNegra()){
						attrset (COLOR_PAIR(3));
					}
					printw(" ***** ");
				}else{					
					printw("       ");
				}
			}
		}
	}
	mvprintw(2,57,"a");
	mvprintw(7,57,"b");
	mvprintw(12,57,"c");
	mvprintw(17,57,"d");
	mvprintw(22,57,"e");
	mvprintw(27,57,"f");
	mvprintw(32,57,"g");
	mvprintw(37,57,"h");
	mvprintw(41,2,"0");
	mvprintw(41,10,"1");
	mvprintw(41,17,"2");
	mvprintw(41,24,"3");
	mvprintw(41,31,"4");
	mvprintw(41,38,"5");
	mvprintw(41,45,"6");
	mvprintw(41,52,"7");
	
}
void iniciarMatriz(Pieza** matriz){
	
/*	for(int FILA = 0; FILA < 8; FILA++){
		matriz[FILA] = new Pieza[8];
		for(int COLUMNA = 0; COLUMNA < 8; COLUMNA++){
			if(FILA < 3 || FILA > 4){
				if((COLUMNA + FILA) % 2 == 0){
					matriz[FILA][COLUMNA] = Pieza(COLUMNA, FILA, FILA < 3 ? 0 : 1);
				}else{
					matriz[FILA][COLUMNA] = Pieza();
				}
			}else{
					matriz[FILA][COLUMNA] = Pieza();
				if(FILA == 3 && COLUMNA == 1){
					move(FILA + 5, COLUMNA + 60);
					printw("%d", matriz[FILA][COLUMNA].estaViva());
				}
			}
		}
	}*/
	
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
