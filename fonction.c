#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "pp1.h"
#include "background.h" 
#include <SDL/SDL_ttf.h>

void animate_walk(personnageP *luan,int action)
{
switch (action)
{
	case 1:
	if(luan->direction==0)
	{
luan->walk[0].x+=100;
if (luan->walk[0].x==400)
luan->walk[0].x=0;
SDL_Delay(30);
	}else if(luan->direction==1)
	{
		luan->walk[1].x-=100;
if (luan->walk[1].x==700)
luan->walk[1].x=1100;
SDL_Delay(30);
	}
	break;
}
}

void animation_perso(personnageP *caractere,int action,SDL_Surface *screen,background *backg)
{ 
int i;
SDL_Rect posimg;
switch(action)
{
case 1:
if(caractere->direction==0)
{	caractere->personnage=IMG_Load("assyl 1.png");
animate_walk(caractere,action);
posimg.x=caractere->walk[0].x;
posimg.y=caractere->walk[0].y;
posimg.h=caractere->walk[0].h;
posimg.w=caractere->walk[0].w;
	afficher_perso(screen,caractere,posimg,backg);
	caractere->position.x=caractere->position.x+10;
}
else if(caractere->direction==1)
{caractere->personnage=IMG_Load("assyl 2.png");
animate_walk(caractere,action);
posimg.x=caractere->walk[1].x;
posimg.y=caractere->walk[1].y;
posimg.h=caractere->walk[1].h;
posimg.w=caractere->walk[1].w;
	afficher_perso(screen,caractere,posimg,backg);
caractere->position.x=caractere->position.x-10;
}
break;
case 2:
for(i=0;i<10;i++)
{
if(caractere->direction==0)
{	
	caractere->personnage=IMG_Load("assyl 1.png");
posimg.x=(caractere->jump[0].x)+(100*i);
posimg.y=caractere->jump[0].y;
posimg.h=caractere->jump[0].h;
posimg.w=caractere->jump[0].w;
if((i==5)||(i==6))
{
		caractere->position.x=caractere->position.x+10;
	caractere->position.y=caractere->position.y-30;

}
else if((i==7)||(i==8)) 
	{caractere->position.x=caractere->position.x+10;
	caractere->position.y=caractere->position.y+30;

}else 
{caractere->position.y=540;
	caractere->position.x=caractere->position.x+10;}
	afficher_perso(screen,caractere,posimg,backg);
}
else if( caractere->direction==1)
{
caractere->personnage=IMG_Load("assyl 2.png");
posimg.x=(caractere->jump[1].x)-100*i;
posimg.y=caractere->jump[1].y;
posimg.h=caractere->jump[1].h;
posimg.w=caractere->jump[1].w;
	if((i==5)||(i==6))
{
		caractere->position.x=caractere->position.x-10;
	caractere->position.y=caractere->position.y-30;

}
else if((i==7)||(i==8))
{
		caractere->position.x=caractere->position.x-10;
	caractere->position.y=caractere->position.y+30;

}
else 
{caractere->position.y=540;
	caractere->position.x=caractere->position.x-10;}
	afficher_perso(screen,caractere,posimg,backg);
}
}
break;
case 3:

for(i=0;i<6;i++)
{
if(caractere->direction==0)
{	caractere->personnage=IMG_Load("assyl 1.png");
posimg.x=(caractere->squat[0].x)+100*i;
posimg.y=caractere->squat[0].y;
posimg.h=caractere->squat[0].h;
posimg.w=caractere->squat[0].w;
	afficher_perso(screen,caractere,posimg,backg);
	caractere->position.x=caractere->position.x+5;
}
else if( caractere->direction==1)
{caractere->personnage=IMG_Load("assyl 2.png");
posimg.x=(caractere->squat[1].x)-100*i;
posimg.y=caractere->squat[1].y;
posimg.h=caractere->squat[1].h;
posimg.w=caractere->squat[1].w;
	afficher_perso(screen,caractere,posimg,backg);
caractere->position.x=caractere->position.x-5;
}
}break;
case 4:
for(i=0;i<7;i++)
{
if(caractere->direction==0)
{	caractere->personnage=IMG_Load("assyl 1.png");
posimg.x=(caractere->attack1[0].x)+100*i;
posimg.y=caractere->attack1[0].y;
posimg.h=caractere->attack1[0].h;
posimg.w=caractere->attack1[0].w;
	afficher_perso(screen,caractere,posimg,backg);
	caractere->position.x=caractere->position.x+5;
}
else if( caractere->direction==1)
{caractere->personnage=IMG_Load("assyl 2.png");
posimg.x=(caractere->attack1[1].x)-100*i;
posimg.y=caractere->attack1[1].y;
posimg.h=caractere->attack1[1].h;
posimg.w=caractere->attack1[1].w;	
	afficher_perso(screen,caractere,posimg,backg);
caractere->position.x=caractere->position.x-5;
}
}
break;
case 5:
for(i=0;i<11;i++)
{
if(caractere->direction==0)
{	caractere->personnage=IMG_Load("assyl 1.png");
posimg.x=(caractere->attack2[0].x)+100*i;
posimg.y=caractere->attack2[0].y;
posimg.h=caractere->attack2[0].h;
posimg.w=caractere->attack2[0].w;	
	afficher_perso(screen,caractere,posimg,backg);
	caractere->position.x=caractere->position.x+30;
}
else if( caractere->direction==1)
{caractere->personnage=IMG_Load("assyl 2.png");
posimg.x=(caractere->attack2[1].x)-100*i;
posimg.y=caractere->attack2[1].y;
posimg.h=caractere->attack2[1].h;
posimg.w=caractere->attack2[1].w;	
	afficher_perso(screen,caractere,posimg,backg);
caractere->position.x=caractere->position.x-30;
}
}
break;
case 6:
for(i=0;i<4;i++)
{
if(caractere->direction==0)
{	caractere->personnage=IMG_Load("assyl 1.png");
posimg.x=(caractere->die[0].x)+100*i;
posimg.y=caractere->die[0].y;
posimg.h=caractere->die[0].h;
posimg.w=caractere->die[0].w;
	afficher_perso(screen,caractere,posimg,backg);
	caractere->position.x=caractere->position.x-5;
}
else if( caractere->direction==1)
{caractere->personnage=IMG_Load("assyl 2.png");
posimg.x=(caractere->die[1].x)-100*i;
posimg.y=caractere->die[1].y;
posimg.h=caractere->die[1].h;
posimg.w=caractere->die[1].w;
	afficher_perso(screen,caractere,posimg,backg);
	caractere->position.x=caractere->position.x+10;

}
}
break;
}//switch
}//void

  void afficher_perso(SDL_Surface *screen,personnageP *luan,SDL_Rect posimg,background *backg)
{
	afficher_background(screen,backg);
	 //displayvie(&(luan->persoVie),screen,luan->persoVie.val); 
SDL_BlitSurface(luan->personnage,&posimg,screen,&(luan->position));
        SDL_Flip(screen);
                SDL_Delay(80);
                SDL_FreeSurface(luan->personnage);

}

      personnageP inisialiser_perso (int level,SDL_Surface *screen)
{
personnageP luan;
luan.persoVie.val=5;
luan.persoScore.s=0;
//walk
luan.walk[0].x=0;
luan.walk[0].y=0;
luan.walk[0].h=200;
luan.walk[0].w=100;
luan.walk[1].x=1100;
luan.walk[1].y=0;
luan.walk[1].h=200;
luan.walk[1].w=100;
//Jump
luan.jump[0].x=0;
luan.jump[0].y=200;
luan.jump[0].h=200;
luan.jump[0].w=100;
luan.jump[1].x=1100;
luan.jump[1].y=200;
luan.jump[1].h=200;
luan.jump[1].w=100;
//squat
luan.squat[0].x=0;
luan.squat[0].y=400;
luan.squat[0].h=200;
luan.squat[0].w=100;
luan.squat[1].x=1100;
luan.squat[1].y=400;
luan.squat[1].h=200;
luan.squat[1].w=100;
//attack1
luan.attack1[0].x=0;
luan.attack1[0].y=610;
luan.attack1[0].h=200;
luan.attack1[0].w=100;
luan.attack1[1].x=1100;
luan.attack1[1].y=610;
luan.attack1[1].h=200;
luan.attack1[1].w=100;
//attack2
luan.attack2[0].x=0;
luan.attack2[0].y=800;
luan.attack2[0].h=200;
luan.attack2[0].w=100;
luan.attack2[1].x=1100;
luan.attack2[1].y=800;
luan.attack2[1].h=200;
luan.attack2[1].w=100;
//die
luan.die[0].x=0;
luan.die[0].y=1030;
luan.die[0].h=200;
luan.die[0].w=100;
luan.walk[1].x=1100;
luan.die[1].y=1300;
luan.die[1].h=200;
luan.die[1].w=100;

luan.direction=0;
luan.personnage=IMG_Load("assyl 1.png");
if(level==1)
{
	luan.position.x=60;
luan.position.y=540;
}
else if(level==2)
{
	luan.position.x=5040;
luan.position.y=540;
	 }
 else if(level==3)
{
	luan.position.x=13040;
luan.position.y=540;
 }
 SDL_BlitSurface(luan.personnage,&(luan.walk[0]),screen,&(luan.position));
SDL_Flip(screen);
     SDL_FreeSurface(luan.personnage);
          return luan;
}






void delpacement (SDL_Event event,personnageP *luan,SDL_Surface *screen,background *backg)
{int action;
	int done=1;
	
while(SDL_WaitEvent(&event))
{switch(event.type)
        {
            case SDL_QUIT:
                done = 0;
                break; 
case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP: 
action=2;
animation_perso(luan,action,screen,backg);
                        break;
                    /*case SDLK_z: 
                        posHero.y--;
                        break;*/
                    case SDLK_DOWN: 
action=3;
animation_perso(luan,action,screen,backg);
                        break;
                    /*case SDLK_s: 
                        posHero.y++;
                        break;*/
                    case SDLK_RIGHT: 
                    
luan->direction=0;
action=1;
animation_perso(luan,action,screen,backg);

                        break;
                    /*case SDLK_d: 
                        posHero.x++;
                        break;*/
                    case SDLK_LEFT: 
luan->direction=1;
action=1;
animation_perso(luan,action,screen,backg);
                        break;
                    /*case SDLK_q: 
                        posHero.x--;
                        break;*/
                }
                break;
        case SDL_MOUSEBUTTONUP:
             if(event.button.button==SDL_BUTTON_RIGHT)
              {
if( luan->position.x<event.button.x )       
while (luan->position.x<event.button.x)
             {action=1;
luan->direction=0 ;
animation_perso(luan,action,screen,backg);
 SDL_Flip(screen);
SDL_Delay(1);


        }
else if( luan->position.x>event.button.x )
while (luan->position.x>event.button.x)
             {action=1;
luan->direction=1 ;
animation_perso(luan,action,screen,backg);
 SDL_Flip(screen);
SDL_Delay(1);
         }}
else if (event.button.button==SDL_BUTTON_LEFT)
              {action=5;
animation_perso(luan,action,screen,backg);
 }

 }     }
   }

void init_vie(vie *v,SDL_Surface *screen) 
{
 (v->posvie.x)=0;
 (v->posvie.y)=0;
 (v->val)=5;
 (v->image[1])=IMG_Load("vie1.png") ;
 (v->image[2])=IMG_Load("vie2.png") ;
 (v->image[3])=IMG_Load("vie3.png") ;
 (v->image[4])=IMG_Load("vie4.png") ;
 (v->image[5])=IMG_Load("vie5.png") ;
 displayvie(v,screen,5); 

}

void displayvie(vie *v,SDL_Surface *screen,int x) 
{

SDL_BlitSurface(v->image[x],NULL,screen,&(v->posvie));
SDL_Flip(screen);
SDL_Delay(1000);
SDL_FreeSurface(v->image[x]);
}


void vie_freevie(vie *v ) 
{
SDL_FreeSurface(v->image[0]);
SDL_FreeSurface(v->image[1]);
SDL_FreeSurface(v->image[2]);
SDL_FreeSurface(v->image[3]);
SDL_FreeSurface(v->image[4]);
SDL_FreeSurface(v->image[5]);
}
void init_score(SDL_Surface *screen,points S)
 {S.s=0;

char Score[20];
 
 TTF_Font *police = NULL;
    S.poscore.x = 460;
    S.poscore.y = 0;
SDL_Color couleurNoire = {0,0,0};
police = TTF_OpenFont("angelina.ttf",30);
sprintf(Score,"score: %d",S.s);
S.score = TTF_RenderText_Blended(police,Score,couleurNoire);

SDL_BlitSurface(S.score,NULL,screen,&S.poscore);
SDL_Flip(screen);

} 




void display_score(SDL_Surface *screen,points *S,int collision)
{int x;
S->s=0; 
if(collision==1)
{S->s=S->s+10;
S->s=x;}
SDL_BlitSurface(S->score, NULL, screen, &S->poscore);
SDL_Flip(screen);
}

void free_score(points*S)   
  {
   SDL_FreeSurface(S->score);
}

