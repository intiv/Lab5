#include "Pieza.h"
#include<string>

using std::string;

Pieza::Pieza(){
	this->viva = false;
}

Pieza::Pieza(int x,int y,bool color){
	this->x=x;
	this->y=y;
	this->General=false;
	this->Negra=color;
	this->viva = true;
}
bool Pieza::esGeneral(){
	return this->General;
}

void Pieza::setViva(bool vida){
	this->viva=vida;
}

bool Pieza::esNegra(){
	return this->Negra;
}
bool Pieza::estaViva(){
	return this->viva;
}

int Pieza::getX(){
	return this->x;
}

int Pieza::getY(){
	return this->y;
}

void Pieza::setX(int x){
	this->x=x;
}

void Pieza::setY(int y){
	this->y=y;
}

bool Pieza::mover(int x,int y,Pieza** &matriz){
 	if(!Negra&&!General){
 		if(x>=8||y>=8||x<0||y<0){
 			return false;
				if(matriz[FILA][COLUMNA].estaViva()){
					printw("       ");
				}else{					
					printw("       ");
				}
 		}else if(this->x==x&&this->y==y){
 			return false;
 		}else if( (x==this->x+1||x==this->x-1)&&(y==this->y+1)&&!matriz[y][x].viva){
			matriz[y][x].setViva(true);
			matriz[y][x].setX(x);
			matriz[y][x].setY(y);
			matriz[y][x].CambiarColor();
			setViva(false);
 			return true;
 		}else if( (x==this->x+2&&y==this->y+2&&!matriz[this->y+1][this->x+1].esNegra()&&!matriz[y][x].viva)||(x==this->x-2&&y==this->y+2&&!matriz[this->y-1][this->x+1].esNegra()&&!matriz[y][x].viva)){
 			matriz[y][x].setViva(true);
			matriz[y][x].CambiarColor();
			matriz[y][x].setX(x);
			matriz[y][x].setY(y);
			setViva(false);
			return true;
 		}else{
 			return false;
 		}
 	}else if(Negra&&!General){
 		if(x>=8||y>=8||x<0||y<0){
                         return false;
                 }else if(this->x==x&&this->y==y){
                         return false;
                 }else if( (x==this->x+1||x==this->x-1)&&(y==this->y-1)&&!matriz[y][x].viva){
			matriz[y][x].setViva(true);
			matriz[y][x].CambiarColor();
			matriz[y][x].setX(x);
			matriz[y][x].setY(y);
			setViva(false);
                        return true;
                 }else if( (x==this->x+2&&y==this->y-2&&!matriz[this->y-1][this->x+1].esNegra()&&!matriz[y][x].viva)||(x==this->x-2&&y==this->y-2&&matriz[this->y-1][this->x+1].esNegra()&&!matriz[y][x].viva)){
			matriz[y][x].setViva(true);
			matriz[y][x].CambiarColor();
			matriz[y][x].setX(x);
			matriz[y][x].setY(y);
			setViva(false);
                 	return true;
                 }else{
                        return false;
                 }

 	}
 }

void Pieza::CambiarColor(){
	this->Negra==!Negra;

}

