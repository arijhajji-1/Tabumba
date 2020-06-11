#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "pp1.h"
/**
* @struct sauvegarde
* @brief struct for sauvegarde
*/
typedef struct 
{
	SDL_Surface *sauvegarder,*oui,*non,*yedd;/* !< Surface. */
		SDL_Rect sauvegarderPos,ouiPos,nonPos,yeddPos;/* !< Rectangle. */
		int pos;
		int etat;
}sauvegarde;

void SaveGame(personnageP luan);
void loadGame(personnageP *luan);
int update (sauvegarde *s,SDL_Surface *screen,personnageP luan, int *done);
void validationSauvegarde(SDL_Surface* screen,sauvegarde *s);
void afficherSauvegarde(SDL_Surface *screen,sauvegarde *sauvegarde);
void freem(sauvegarde *sauvegarde);
