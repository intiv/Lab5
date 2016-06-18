#include "Pieza.h"
#include<string>
//#include<ncurses.h>

using std::string;

Pieza::Pieza(int x,int y){
	this->viva = false;
	this->x=x;
	this->y=y;
}

Pieza::Pieza(){
	this->viva=false;
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

bool Pieza::mover(int y,int x,Pieza** &matriz){
	// return matriz[x][y].estaViva();
	if(!viva){
		return false;
	}
//	mvprintw(30,45,"thisy: %d,thisx: %d,y: %d,x: %d,thisviva: %d,yxviva: %d",this->y,this->x,y,x,this->viva,matriz[y][x].viva);
//	mvprintw(31,45,"this negra: %d, xynegra: %d",this->Negra,matriz[y][x].Negra);
//	getch();
 	if(!Negra&&!General){
 		if(x>=8||y>=8||x<0||y<0){
 			return false;
 		}else if(this->x==x&&this->y==y){
 			return false;
 		}else if( (x + 1==this->x||x-1==this->x)&&(y-1==this->y)&&!matriz[y][x].estaViva()){
			matriz[y][x].setViva(true);
			matriz[y][x].CambiarColor(this->Negra);
			setViva(false);
 			return true;
 		}else if((x==this->x+2&&y==this->y+2&&matriz[this->y+1][this->x+1].esNegra()&&matriz[y-1][x-1].estaViva()&&!matriz[y][x].estaViva())){
 			matriz[y][x].setViva(true);
			matriz[y][x].CambiarColor(!Negra);
			matriz[y-1][x-1].setViva(false);
			setViva(false);
			return true;
	
 		}else if((x==this->x-2&&y==this->y+2&&matriz[this->y+1][this->x-1].esNegra()&&matriz[y-1][x+1].estaViva()&&!matriz[y][x].estaViva())){
 			matriz[y][x].setViva(true);
			matriz[y][x].CambiarColor(!Negra);
			matriz[y-1][x+1].setViva(false);
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
 		}else if( (x + 1==this->x||x-1==this->x)&&(y+1==this->y)&&!matriz[y][x].estaViva()){
			matriz[y][x].setViva(true);
			matriz[y][x].CambiarColor(this->Negra);
			setViva(false);
 		}else if((x==this->x+2&&y==this->y-2&&!matriz[this->y-1][this->x+1].esNegra()&&matriz[y+1][x-1].estaViva()&&!matriz[y][x].estaViva())){
 			 matriz[y][x].setViva(true);
		 	 matriz[y][x].CambiarColor(!Negra);
			 matriz[y+1][x-1].setViva(false);
			 setViva(false);
			 return true;
 		}else if((x==this->x-2&&y==this->y-2&&!matriz[this->y-1][this->x-1].esNegra()&&matriz[y+1][x+1].estaViva()&&!matriz[y][x].estaViva())){
 			 matriz[y][x].setViva(true);
			 matriz[y][x].CambiarColor(!Negra);
			 matriz[y+1][x+1].setViva(false);
			 setViva(false);
			 return true;
                }else{
                         return false;
                }

 	}
 }



void Pieza::CambiarColor(bool negra){
	this->Negra=negra;

}

