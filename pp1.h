#ifndef PP1_H_INCLUDED
#define PP1_H_INCLUDED
#include "background.h" 
#define BACKGROUND_H_INCLUDED

typedef struct vie 
{
SDL_Rect posvie ;  
int val ;
SDL_Surface *image[6]; 
}vie ; 
typedef struct{
SDL_Surface *score;
SDL_Rect poscore;
int s;

}points;
typedef struct 
{
	char nom[30];
	char prenom[30];
SDL_Surface  *personnage;
SDL_Rect position;
int direction;
int collision_RIGHT,collision_DOWN,collision_UP,collision_LEFT;
SDL_Rect walk[2],jump[2],attack1[2],attack2[2],die[2],squat[2];
vie persoVie;
points persoScore;
}personnageP;



void init_score(SDL_Surface *screen,points S);
//void display_score(SDL_Surface *screen,points *S,background *backg,personnageP *luan);
void free_score(points *S);
void init_vie(vie *v,SDL_Surface *screen); 
void displayvie(vie *v,SDL_Surface *screen,int x); 
void vie_freevie(vie *v) ;
personnageP inisialiser_perso (int level,SDL_Surface *screen);
void afficher_perso(SDL_Surface *screen,personnageP *luan,SDL_Rect posimg,background *backg);
void animation_perso(personnageP *caractere,int action,SDL_Surface *screen,background *backg);
void animate_walk(personnageP *luan,int action);
void delpacement (SDL_Event event,personnageP *luan,SDL_Surface *screen,background *backg);
int Collision(background *backg,personnageP *luan);
SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y);

int enigmee(SDL_Surface *screen) ;
#endif

