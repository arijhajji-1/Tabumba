#ifndef INITSEC_H_INCLUDED
#define INITSEC_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "background.h"
/**
* @struct Enemy
* @brief struct for Enemy
*/
typedef struct Enemy
{
  SDL_Surface *image[3];/* !< Surface. */
  SDL_Surface *image2[3];/* !< Surface. */
  SDL_Surface *Hit;/* !< Surface. */
  SDL_Surface *imageActuel;/* !< Surface. */
  SDL_Rect position; /* !< Rectangle */
  SDL_Rect positionO;/* !< Rectangle */
  int frame;
  int direction;
  int died;
}Enemy;
void inisialiser_character (Enemy *t,SDL_Surface *screen);
void afficher_character (Enemy *t,SDL_Surface *screen);
Enemy AnimateEnemy(Enemy Ennemie, int stat);
Enemy MoveEnemy(Enemy Ennemie, SDL_Rect personnage, int *stat, int mouvment);
Enemy diedennemie(Enemy Ennemie,int coe);
#endif
