#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_ttf.h"
#include "fonctions.h"





/*










void initialiser_objet(objet *chouka) {
	chouka->afficher_objet=NULL;
	chouka->afficher_objet=IMG_Load("s1.png");

	chouka->pos_objet.x=1000;
	chouka->pos_objet.y=0;
}



void afficher_objet(objet *chouka,SDL_Surface *ecran,hero evan){

	if (chouka->pos_objet.x==0){
			srand(time(NULL)); 
		chouka->pos_objet.x=(rand()%900)+450;  
		chouka->pos_objet.y=0;
	}
	if ((chouka->pos_objet.y<600)&&(pos->x<=300)){
		if ((evan.heromoved==1)&&(pos->x==300)){
			chouka->pos_objet.x=chouka->pos_objet.x-5;
				

				}
			chouka->pos_objet.y++;
			if (/*heromoved*/==2){
				chouka->pos_objet.x=chouka->pos_objet.x+5;
			
			}


			
			
				chouka->pos_objet.y+=5;
	}

	else {
			srand(time(NULL)); 
		chouka->pos_objet.x=(rand()%900+300);  
		chouka->pos_objet.y=0;
	}
	if(pos->x>100)
		SDL_BlitSurface(chouka->afficher_objet,NULL,ecran,&(chouka->pos_objet));
	else if (pos->x>300)
		 chouka->afficher_objet=NULL;
}




*/












SDL_Surface * initEcran(char * titre, char * icone, int largeur, int hauteur)
{
    SDL_Surface *ecran = NULL;
    SDL_Init(SDL_INIT_VIDEO);

    SDL_WM_SetIcon(IMG_Load(icone), NULL);
    ecran = SDL_SetVideoMode(largeur, hauteur, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (ecran == NULL)
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_WM_SetCaption(titre, NULL);

    return ecran;
}

int attendreAvantDeQuitter(Uint8 typeEvenement)
{
    int continuer = 1 ;
    switch(typeEvenement)
    {
        case SDL_QUIT:
            continuer = 0;break;
        default : break;
    }
    return continuer;
}

void backgroundColorSurface(SDL_Surface * surface, Uint8 rouge, Uint8 vert, Uint8 bleu)
{
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, rouge, vert, bleu));
}
 
 
void blitImageSurSurface(SDL_Surface * surfaceBlit, char * fileImage, SDL_Rect *position)
{ 
    SDL_Surface* loadedImage = NULL;
    loadedImage = IMG_Load(fileImage);
    position->h = loadedImage->h;
    position->w = loadedImage->w;
    SDL_BlitSurface(loadedImage, NULL, surfaceBlit, position);
    SDL_FreeSurface(loadedImage);
}

 

 void attendreTemps(int millisecondes)
{
    int startTicks = SDL_GetTicks();

    while((SDL_GetTicks() - startTicks) < millisecondes)
    {
        SDL_Delay(1);
    }
}

void deplacement(SDL_Rect * pos, SDL_Event event, int vitesse_x, int vitesse_y)
{
    if(event.type == SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_UP: pos->y -= vitesse_y / 2; break;
            case SDLK_DOWN: pos->y += vitesse_y / 2; break;
            case SDLK_LEFT: pos->x -= vitesse_x / 2; break;
            case SDLK_RIGHT: pos->x += vitesse_x / 2; break;
            default: break;
        }
    }
}





int testCollision(SDL_Rect obj1, SDL_Rect obj2, int * typeCollision)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = obj1.x;
    rightA = obj1.x + obj1.w;
    topA = obj1.y;
    bottomA = obj1.y + obj1.h;

    leftB = obj2.x;
    rightB = obj2.x + obj2.w;
    topB = obj2.y;
    bottomB = obj2.y + obj2.h;

    if( bottomA <= topB )
    {
        *typeCollision = BOTTOM;return 1;
    }


    if( topA >= bottomB )
    {
        *typeCollision = TOP;return 1;
    }

    if( rightA <= leftB )
    {
        *typeCollision = RIGHT;return 1;
    }

    if( leftA >= rightB )
    {
        *typeCollision = LEFT;return 1;
    }
    return 0;
}











































void deplacementAutorise(int typeCol, SDL_Rect * pos1, SDL_Event event, int vit_x, int vit_y)
{
    switch(typeCol)
    {
        case BOTTOM :
                        switch(verifEtatToucheClavier())
                        {
                            case SDLK_UP : case SDLK_RIGHT : case SDLK_LEFT : deplacement(pos1, event, vit_x, vit_y);break;
                            default : break;
                        }break;
        case TOP :
                        switch(verifEtatToucheClavier())
                        {
                            case SDLK_DOWN : case SDLK_RIGHT : case SDLK_LEFT : deplacement(pos1, event, vit_x, vit_y);break;
                            default : break;
                        }break;
        case RIGHT :
                        switch(verifEtatToucheClavier())
                        {
                            case SDLK_UP : case SDLK_DOWN : case SDLK_LEFT : deplacement(pos1, event, vit_x, vit_y);break;
                            default : break;
                        }break;
        case LEFT :
                        switch(verifEtatToucheClavier())
                        {
                            case SDLK_UP : case SDLK_RIGHT : case SDLK_DOWN : deplacement(pos1, event, vit_x, vit_y);break;
                            default : break;
                        }break;
        default : break;
    }
}



















int verifEtatToucheClavier()
{
    Uint8 *keystates = SDL_GetKeyState(NULL);

    if( keystates[SDLK_UP] )
        return SDLK_UP;

    if( keystates[ SDLK_DOWN ] )
        return SDLK_DOWN;

    if( keystates[ SDLK_LEFT ] )
         return SDLK_LEFT;

    if( keystates[ SDLK_RIGHT ] )
        return SDLK_RIGHT;

    return RIEN;
}