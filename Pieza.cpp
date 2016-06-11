#include "Pieza.h"
#include<string>
#include "ncurses.h"

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

Pieza::Pieza(Pieza& nPieza){
	this->x=nPieza.getX();
	this->y=nPieza.getY();
	this->Negra=nPieza.esNegra();	
	this->viva=nPieza.estaViva();
}

bool Pieza::mover(int x,int y,Pieza** &matriz){
	// return matriz[x][y].estaViva();
 	if(!Negra&&!General){
		mvprintw(35,65,"Entro a !negra !general");
		mvprintw(36,65,"%d\t%d\t%d",x,y,matriz[x][y].estaViva());
 		if(x>=8||y>=8||x<0||y<0){
 			return false;
			mvprintw(36,65,"Entro a x>=8 y>=8 etc");
 		}else if(this->x==x&&this->y==y){
 			return false;
			mvprintw(36,65,"Entro a x=x y=y etc");
 		}else if((x==this->x+1||x==this->x-1)&&(y==this->y+1)/*&&!matriz[x][y].estaViva()*/){
			matriz[x][y]=Pieza(*this);
			mvprintw(36,65,"Entro a x=this x+1/x-1 y=this y-1  xy!viva");
			this->setViva(false);
 			return true;
 		}else if((x==this->x+2&&y==this->y+2&&!matriz[this->y+1][this->x+1].esNegra()&&!matriz[y][x].estaViva())||(x==this->x-2&&y==this->y+2&&!matriz[this->y-1][this->x+1].esNegra()&&!matriz[y][x].estaViva())){
 			matriz[x][y].setViva(true);
			mvprintw(36,65,"Entro a x=this x+2 y=this y+2  xy!viva");
			matriz[x][y].CambiarColor(this->Negra);
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
			matriz[x][y].setViva(true);
			matriz[x][y].CambiarColor(Negra);
			setViva(false);
                        return true;
                 }else if( (x==this->x+2&&y==this->y-2&&!matriz[this->y-1][this->x+1].esNegra()&&!matriz[y][x].viva)||(x==this->x-2&&y==this->y-2&&matriz[this->y-1][this->x+1].esNegra()&&!matriz[y][x].viva)){
			matriz[x][y].setViva(true);
			matriz[x][y].CambiarColor(Negra);
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

