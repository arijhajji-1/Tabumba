#ifndef PP_H_INCLUDED
#define PP_H_INCLUDED
#include "background.h" 
#define background_H_INCLUDED
/**
*
@struct vie
@brief structure du vie du joueur
*/
typedef struct vie 
{
SDL_Rect posvie ;  
int val ;
SDL_Surface *image[6]; 
}vie ; 
/**
*
@struct score
@brief structure du score du joueur
*/
typedef struct{
SDL_Surface *score;
SDL_Rect poscore;
int s;

}points;
/**
*
@struct personnage principal
@brief structure du personnage principal
*/
typedef struct 
{
SDL_Surface  *personnage;
SDL_Rect position;
int direction;
SDL_Rect walk[2],jump[2],attack1[2],attack2[2],die[2],squat[2];
vie persoVie;
points persoScore;
}personnageP;



void init_score(SDL_Surface *screen,points S);
void display_score(SDL_Surface *screen,points *S,int collision);
void free_score(points *S);
void init_vie(vie *v,SDL_Surface *screen); 
void displayvie(vie *v,SDL_Surface *screen,int x); 
void vie_freevie(vie *v) ;
personnageP inisialiser_perso (int level,SDL_Surface *screen);
void afficher_perso(SDL_Surface *screen,personnageP *luan,SDL_Rect posimg,background *backg);
void animation_perso(personnageP *caractere,int action,SDL_Surface *screen,background *backg);
void animate_walk(personnageP *luan,int action);
void delpacement (SDL_Event event,personnageP *luan,SDL_Surface *screen,background *backg);

#endif

