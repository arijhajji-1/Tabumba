#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED




struct Ennemi{
        SDL_Rect positionAbsolue;
	SDL_Rect positionAnimation;
	SDL_Surface * image;
	int direction;
	int moving;
STATE STATE;
};

typedef struct Ennemi Ennemi;

void AnnimateEnnemiRight(Ennemi *E);
void AnnimateEnnemiLeft(Ennemi *E);
void AnnimateEnnemiBackward(Ennemi *E);
void AnnimateEnnemiForward(Ennemi *E);
void MoveEnnemiBackward(Ennemi *E, Hero hero);
void MoveEnnemiForward(Ennemi *E, Hero hero);


#endif // ANIMATION_H_INCLUDED
