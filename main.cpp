#include <ncurses.h>
#include "Pieza.h"
void imprimirTavlero(Pieza**);
int caracterAEntero(char);
void iniciarMatriz(Pieza**);
void clearS();

int main(int argc, char const *argv[]){
	initscr();
	Pieza** matriz = new Pieza*[8];
	start_color();
	iniciarMatriz(matriz);/*
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			mvprintw(20+i,60+j,"%d ",matriz[i][j].estaViva());
		}
	}
	getch();*/
	init_pair(1,COLOR_WHITE,COLOR_RED);
	init_pair(3,COLOR_BLACK,COLOR_RED);
	init_pair(2,COLOR_WHITE,COLOR_GREEN);
	int turno=1,y,x,y1,x1;
	noecho();
	bool play=true;
	while(play){
		clearS();
		imprimirTavlero(matriz);
		refresh();
		if(turno){
			mvprintw(2,60,"Turno jugador 1");
			mvprintw(3,60,"Pieza a mover:");
			mvprintw(5,60,"Ingrese 	Y: ");
			bool valid=false;
			while(!valid){
				y=getch();
				if(y==97||y==98||y==99||y==100||y==101||y==102||y==103||y==104){
					mvprintw(5,76,"%c",y);
					valid=true;
				}
				
			}
			valid=false;
			mvprintw(6,60,"Ingrese X: ");
			while(!valid){
                                x=getch();
                                if(x==49||x==50||x==51||x==52||x==53||x==54||x==55||x==48){
                                        mvprintw(6,76,"%c",x);
                                        valid=true;
                                }
                                
                        }
			mvprintw(7,60,"Posicion hacia donde mover la pieza:");
			mvprintw(8,60,"Ingrese Y: ");
			valid=false;
			while(!valid){
                                y1=getch();
                                if(y1==97||y1==98||y1==99||y1==100||y1==101||y1==102||y1==103||y1==104){
                                        mvprintw(8,76,"%c",y1);
                                        valid=true;
                                }
                                
                        }
                        valid=false;
                        mvprintw(9,60,"Ingrese X: ");
                        while(!valid){
                                x1=getch();
                                if(x1==49||x1==50||x1==51||x1==52||x1==53||x1==54||x1==55||x1==48){
                                        mvprintw(10,76,"%c",x1);
                                        valid=true;
                                }
                                
                        }

			char t1,t2,t3,t4;
			t1=y;
			t2=y1;
			t3=x;
			t4=x1;
			int ny,ny1,nx,nx1;
			ny=caracterAEntero(t1);
			ny1=caracterAEntero(t2);
			nx=t3-'0';
			nx1=t4-'0';
			//mvprintw(18,60,"originales %d,%d;%d,%d",y,x,y1,x1);
			//mvprintw(19,60,"caracteres %c , %c; %c, %c",t1,t3,t2,t4);
			//mvprintw(20,60,"indices %d , %d ; %d, %d",ny,nx,ny1,nx1);
			//getch();
			if(matriz[ny][nx].mover(ny1,nx1,matriz)){
			}else{
				mvprintw(15,60,"MOVIMIENTO INVALIDO");
				
			}
			clearS();	
			/*for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				mvprintw(20+i,60+j,"%d ",matriz[i][j].estaViva());
			}}
			getch();*/
			turno=0;
		}else{
			
			mvprintw(2,60,"Turno jugador 2");
			mvprintw(3,60,"Pieza a mover:");
			mvprintw(5,60,"Ingrese Y: ");
			bool valid=false;
			while(!valid){
				y=getch();
				if(y==97||y==98||y==99||y==100||y==101||y==102||y==103||y==104){
					mvprintw(5,76,"%c",y);
					valid=true;
				}
				
			}
			valid=false;
                        mvprintw(6,60,"Ingrese X: ");
                        while(!valid){
                                x=getch();
                                if(x==49||x==50||x==51||x==52||x==53||x==54||x==55||x==48){
                                        mvprintw(6,76,"%c",x);
                                        valid=true;
                                }

                        }
                        mvprintw(7,60,"Posicion hacia donde mover la pieza:");
			mvprintw(8,60,"Ingrese Y: ");
                        valid=false;
                        while(!valid){
                                y1=getch();
                                if(y1==97||y1==98||y1==99||y1==100||y1==101||y1==102||y1==103||y1==104){
                                        mvprintw(8,76,"%c",y1);
                                        valid=true;
                                }

                        }
                        valid=false;
                        mvprintw(9,60,"Ingrese X: ");
                        while(!valid){
                                x1=getch();
                                if(x1==49||x1==50||x1==51||x1==52||x1==53||x1==54||x1==55||x1==48){
                                        mvprintw(9,76,"%c",x1);
                                        valid=true;
                                }

                        }
			char t1,t2,t3,t4;
			t1=y;
			t2=y1;
			t3=x;
			t4=x1;
			int ny,ny1,nx,nx1;
			ny=caracterAEntero(t1);
			ny1=caracterAEntero(t2);
			nx=t3-'0';
			nx1=t4-'0';
			//mvprintw(20,60,"indices %d , %d ; %d, %d",ny,nx,ny1,nx1);
			if(matriz[ny][nx].mover(ny1,nx1,matriz)){
			}else{
				mvprintw(15,60,"MOVIMIENTO INVALIDO");
			}
			/*for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				mvprintw(20+i,60+j,"%d ",matriz[i][j].estaViva());
			}}
			getch();*/
			turno=1;
		}
		int cont1=0,cont2=0;
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				if(matriz[i][j].esNegra()&&matriz[i][j].estaViva()){
					cont1++;
				}
				
				if(!matriz[i][j].esNegra()&&matriz[i][j].estaViva()){
					cont2++;
				}
			}	
		}
		if(cont1==0||cont2==0){
			play=false;
		}
	}
	for(int i=0;i<7;i++){
		delete[] matriz[i];
	}
	return 0;
}
void imprimirTavlero(Pieza** matriz){
	for(int FILA = 0; FILA < 8; FILA++){
		for(int COLUMNA = 0; COLUMNA < 8; COLUMNA++){
			int x = COLUMNA * 5;
			for(int i = 0; i < 5; i++){
				move(FILA * 5 + i, COLUMNA * 7);
				if((COLUMNA + FILA) % 2 == 0){
					attron (COLOR_PAIR(1));
				}else{
					attron (COLOR_PAIR(2));
				}
				if(matriz[FILA][COLUMNA].estaViva()){
					if(matriz[FILA][COLUMNA].esNegra()){
						attron (COLOR_PAIR(3));
					}
					printw(" ***** ");
					if(matriz[FILA][COLUMNA].esNegra()){
                                                attroff (COLOR_PAIR(3));
                                        }

				}else{					
					printw("       ");
				}
				if((COLUMNA + FILA) % 2 == 0){
                                        attroff (COLOR_PAIR(1));
                                }else{
                                        attroff (COLOR_PAIR(2));
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
	for(int FILA = 0; FILA < 8; FILA++){
		matriz[FILA] = new Pieza[8];
		for(int COLUMNA = 0; COLUMNA < 8; COLUMNA++){
			if(FILA < 3 || FILA > 4){
				if((COLUMNA + FILA) % 2 == 0){
					matriz[FILA][COLUMNA] = Pieza(COLUMNA, FILA, FILA < 3 ? 0 : 1);
				}else{
					matriz[FILA][COLUMNA] = Pieza(COLUMNA,FILA);
				}
			}else{
					matriz[FILA][COLUMNA] = Pieza(COLUMNA,FILA);
			}
		}
	}
	
}

void clearS(){
	int y,x;
	getmaxyx(stdscr,y,x);
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			mvprintw(i,j," ");
		}
	}
}
int caracterAEntero(char x){
	char letras[9] = "abcdefgh";
	int temp=x-'0';
	for(int LETRA = 0; LETRA < 8; LETRA++){
		if(letras[LETRA] == x){
			return LETRA;
		}

	}
	return -1;
}
