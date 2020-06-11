#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_ttf.h"
#define LARGEURECRAN 640
#define HAUTEURECRAN 480
#define TITREECRAN "test te3 L COL"
#define ICONE "icon.png"

int main(int argc, char *argv[])
{

    int etat=0;
    SDL_Surface *ecran = NULL;
    SDL_Rect positionImg1={240,240},positionImg2={320,240};
    int typeCollision;
    int continuer = 1;
    float vitX=2, vitY=2;
    SDL_Event event;

    ecran = initEcran(TITREECRAN, ICONE,LARGEURECRAN , HAUTEURECRAN);

    while(continuer)
    {
        SDL_PollEvent(&event);
        continuer = attendreAvantDeQuitter(event.type);
        backgroundColorSurface(ecran, 0, 0, 0);

        blitImageSurSurface(ecran, "icon.png", &positionImg2);
        blitImageSurSurface(ecran, "icon.png", &positionImg1);

        if(testCollision(positionImg1, positionImg2, &typeCollision))
        {
        
            deplacement(&positionImg1, event, vitX, vitY);
        }
        
        else
        {
        
            deplacementAutorise(typeCollision, &positionImg1, event, vitX, vitY);
        }
       
             
       
  
                    if ((positionImg1.x+80<positionImg2.x)&&etat==0) 
                     {
                               
 
 while(positionImg2.x<350 )
{

positionImg2.x++;
 blitImageSurSurface(ecran, "icon.png", &positionImg2);
        blitImageSurSurface(ecran, "icon.png", &positionImg1);
SDL_Flip(ecran);
}
while(positionImg2.x>310 )
{

positionImg2.x--;
 blitImageSurSurface(ecran, "icon.png", &positionImg2);
        blitImageSurSurface(ecran, "icon.png", &positionImg1);
SDL_Flip(ecran);
}  
blitImageSurSurface(ecran, "icon.png", &positionImg2);
        blitImageSurSurface(ecran, "icon.png", &positionImg1);
SDL_Flip(ecran);



                                printf("patrol\n");
                     }
                          
                      /*  if (positionImg1.x+100<=positionImg2.x )
            {           
                    //positionImg2.x=positionImg2.x+50;
                     printf("inrange\n");
                     etat==1;
                 }  */
                         
                   
                        if ( positionImg1.x+80>positionImg2.x)
                            {printf("attack\n");
                        /*while(positionImg2.x>positionImg1.x )
{

positionImg2.x--;
 blitImageSurSurface(ecran, "icon.png", &positionImg2);
        blitImageSurSurface(ecran, "icon.png", &positionImg1);
                         
                    }*/
}
                   
            





        attendreTemps(5);

        SDL_Flip(ecran);
    }
    SDL_Quit();
    return 0;
}


