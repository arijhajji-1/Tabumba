/** 
 *@file main.c 
 *@brief generation d une reponse aléatoire d enigme
 *@author mohamed yahya jday 
 *@version 0.1 
 *@date 10/06/2020 
*/

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h> 
#include "SDL/SDL_ttf.h"
#include <math.h>


int main() 
/** 
 *@struct solution
 *@brief struct solution

*/
{
typedef struct
{
    float s1;/*!<real.*/
    float s2;/*!<real.*/
    int cas;/*!<entier.*/
}solution;
solution T[3];

char chaine[40],chaine1[40],chaine2[40]; 
char pause; 
SDL_Event event ; 
int run;
SDL_Surface *screen; 
SDL_Surface *texte = NULL;  
SDL_Surface *texte1 = NULL; 
SDL_Surface *texte2 = NULL;
SDL_Rect position; 
SDL_Rect position1; 
SDL_Rect position2;
TTF_Init();
TTF_Font *police=NULL;
SDL_Color couleurNoire ={0,0,0},couleurBlanche={255,255,255}; 

SDL_Surface *background; 
SDL_Rect pos;
pos.x=0; 
pos.y=0; 

SDL_Surface *win; 
SDL_Rect pos1;
pos1.x=100; 
pos1.y=100;
  
SDL_Surface *lose; 
SDL_Rect pos2;
pos1.x=100; 
pos1.y=100;  


if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("Unable to initialize SDL:%s\n",SDL_GetError());
return 1;
}
screen=SDL_SetVideoMode(1000,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if(screen == NULL){
printf("Unable to set video mode: %s\n",SDL_GetError());
return 1;
} 
background=SDL_LoadBMP("33.bmp");
SDL_BlitSurface(background,NULL,screen,&pos);  
SDL_Flip(screen); 

police = TTF_OpenFont("Pacifico.ttf",65); 
position.x=100; 
position.y=20; 

 

int a,b,c,delta,i,k,done=1; 
float del; 
float x1,x2,rv1,rv2;
for(i=0;i<3;i++)
{
   T[i].cas=0;
}
i=0;
a=(rand()%10)+1;
b=(rand()%10);
c=(rand()%10);
printf("%dX²+%dX+%d \n",a,b,c);

sprintf(chaine,"%dX²+%dX+%d",a,b,c);
texte = TTF_RenderText_Shaded(police,chaine,couleurNoire,couleurBlanche); 

SDL_BlitSurface(texte,NULL,screen,&position);
SDL_Flip(screen);  


delta=(b*b)-(4*a*c);
if(delta>0)
{
    del=sqrt(delta);
    x1=((-b-del)/(2*a));
    x2=((-b+del)/(2*a));
    
    x1=round(x1);
    x2=round(x2); 
    
rv1=x1;
rv2=x2; 

do
{
  k=(rand()%3);
  if((T[k].cas==0) &&(done==1) )
  {
      T[k].s1=x1;
      T[k].s2=x2;
      done=0;
      i++;
      T[k].cas=1;
  }
  else if((T[k].cas==0)&&(done==0))
  {
     T[k].s1=x1+(rand()%10);
     T[k].s2=x2+(rand()%10);
     T[k].cas=1;
     i++;
  }
}while(i!=3); 
position.x=100; 
position.y=120; 
position1.x=100; 
position1.y=220;  
position2.x=100; 
position2.y=320; 

sprintf(chaine,"x1=%.2f x2=%.2f \n",T[1].s1,T[1].s2); 
texte = TTF_RenderText_Shaded(police,chaine,couleurNoire,couleurBlanche); 
SDL_BlitSurface(texte,NULL,screen,&position);
SDL_Flip(screen); 
sprintf(chaine1,"x1=%.2f x2=%.2f \n",T[1].s1,T[1].s2);
texte1 = TTF_RenderText_Shaded(police,chaine1,couleurNoire,couleurBlanche); 
SDL_BlitSurface(texte1,NULL,screen,&position1);
SDL_Flip(screen);
sprintf(chaine2,"x1=%.2f x2=%.2f \n",T[2].s1,T[2].s2);
texte2 = TTF_RenderText_Shaded(police,chaine2,couleurNoire,couleurBlanche); 
SDL_BlitSurface(texte2,NULL,screen,&position2);
SDL_Flip(screen);
}
else if(delta==0)
{
    x1=(-b/(2*a));
    x2=x1;
    rv1=x1;
    do
{
  k=(rand()%3);
  if((T[k].cas==0) &&(done==1) )
  {
      T[k].s1=x1;
      T[k].s2=x2;
      done=0;
      i++;
      T[k].cas=1;
       printf("%d",i);
  }
  else if((T[k].cas==0)&&(done==0))
  {
   T[k].s1=x1+(rand()%10);
    T[k].s2=T[k].s1;
     T[k].cas=1;
     i++;
     printf("%d",i);
  }
}while(i!=3);
sprintf(chaine,"x1=%.2f x2=%.2f \n",T[1].s1,T[1].s2); 
texte = TTF_RenderText_Shaded(police,chaine,couleurNoire,couleurBlanche); 
SDL_BlitSurface(texte,NULL,screen,&position);
SDL_Flip(screen); 
sprintf(chaine1,"x1=%.2f x2=%.2f \n",T[1].s1,T[1].s2);
texte1 = TTF_RenderText_Shaded(police,chaine1,couleurNoire,couleurBlanche); 
SDL_BlitSurface(texte1,NULL,screen,&position1);
SDL_Flip(screen);
sprintf(chaine2,"x1=%.2f x2=%.2f \n",T[2].s1,T[2].s2);
texte2 = TTF_RenderText_Shaded(police,chaine2,couleurNoire,couleurBlanche); 
SDL_BlitSurface(texte2,NULL,screen,&position2);
SDL_Flip(screen);
}
else
    main(); 
    
 
 while(run) 
 {
 SDL_WaitEvent(&event);
 //SDL_PollEvent(&event);
	switch(event.type)
	{
		  case SDL_QUIT:
			   
                run = 0;
				break ;

       case SDL_KEYDOWN :
            switch( event.key.keysym.sym )
                {
			   case  SDLK_a:
			   if((T[0].s1==rv1)&&(T[0].s2==rv2)) 
			   { 
			   win=IMG_Load("win.png");
			   SDL_BlitSurface(win,NULL,screen,&pos1);
                          SDL_Flip(screen);
			   } 
			   else 
			   { 
			   lose=IMG_Load("lose.png");
			   SDL_BlitSurface(lose,NULL,screen,&pos2);
                          SDL_Flip(screen);
			   }
			   
			   break ;
			   case  SDLK_z:
			   if((T[1].s1==rv1)&&(T[1].s2==rv2)) 
			   { 
			   win=IMG_Load("win.png");
			   SDL_BlitSurface(win,NULL,screen,&pos1);
                          SDL_Flip(screen);
			   } 
			   else 
			   {
			   lose=IMG_Load("lose.png");
			   SDL_BlitSurface(lose,NULL,screen,&pos2);
                          SDL_Flip(screen);
			   }
			   break;
			   case SDLK_e:
			   if((T[2].s1==rv1)&&(T[2].s2==rv2)) 
			   { 
			   win=IMG_Load("win.png");
			   SDL_BlitSurface(win,NULL,screen,&pos1);
                          SDL_Flip(screen);
			   } 
			   else 
			   { 
			   lose=IMG_Load("lose.png");
			   SDL_BlitSurface(lose,NULL,screen,&pos2);
                          SDL_Flip(screen);
			   }
			   break;

			    }
       break ;


	}
 
 }
 
 
 
 
 
 
 
 
 
    

pause=getchar();    
TTF_CloseFont(police);
TTF_Quit();  
SDL_FreeSurface(screen);
SDL_FreeSurface(texte);  
SDL_FreeSurface(texte1); 
SDL_FreeSurface(texte2);
SDL_FreeSurface(background);  
SDL_Quit(); 
    return 0;
}


