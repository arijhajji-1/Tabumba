#ifndef DECLARATION_H_INCLUDED
#define DECLARATION_H_INCLUDED

typedef struct 
{
SDL_Surface  *personnage;
SDL_Rect position;
int direction;
SDL_Rect sprite_sheet[];
}personnageP;

void inisialiser_perso (personnageP caractere);
void afficher_perso(personnageP caractere,SDL_Surface *screen,SDL_Rect pos_perso);
void animation_perso(personnageP caractere);
void update_perso(personnageP caractere,SDL_Surface *screen);

#endif
