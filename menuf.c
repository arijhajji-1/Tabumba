
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

#include "menuf.h"



void menu (SDL_Surface *screen)
{
	 

SDL_Surface *background=NULL;
background =IMG_Load("tabumba 2.1.png");
SDL_Rect background_pos,frame,ani[4];
SDL_Rect posng,poslg,posop,poscr,posq;
background_pos.x=0;
background_pos.y=0;
posng.x=640/2.6;
posng.y=740/8.2;
poslg.x=640/2.6;
poslg.y=740/3.7;
posop.x=640/2.6;
posop.y=740/2.39;
poscr.x=640/2.6;
poscr.y=740/1.76;
posq.x=640/2.6;
posq.y=740/1.39;
ani[0].x=500;
ani[0].y=160;
ani[1].x=450;
ani[1].y=160;
ani[2].x=400;
ani[2].y=160;
ani[3].x=350;
ani[3].y=160;
ani[4].x=300;
ani[4].y=160;
ani[5].x=250;
ani[5].y=160;
ani[6].x=200;
ani[6].y=160;
ani[7].x=150;
ani[7].y=160;
frame.w=50;
frame.h=50;
frame.x=0;
frame.y=0;


int action=0,i=0;

int ng=0,op=0,ex=0,lg=0,cr=0,c=0,r=0,p=1;

SDL_Surface *newgame[3],*loadgame[3],*option[3],*exit[3],*credits[3],*animation;

	SDL_Rect pos;
	pos.x=0;
	pos.y=0;
    
char a[30];
	SDL_Event event;
	int t,save;
	//chargement d'image
    loadgame[0]=IMG_Load("playbuttons/mainmenu/lg1.png");
    loadgame[1]=IMG_Load("playbuttons/mainmenu/lg2.png");
    loadgame[2]=IMG_Load("playbuttons/mainmenu/lg3.png");
    
    newgame[0]=IMG_Load("playbuttons/mainmenu/play1.png");
    newgame[1]=IMG_Load("playbuttons/mainmenu/play2.png");
    newgame[2]=IMG_Load("playbuttons/mainmenu/play3.png");

    option[0]=IMG_Load("playbuttons/mainmenu/options1.png");
    option[1]=IMG_Load("playbuttons/mainmenu/options2.png");
    option[2]=IMG_Load("playbuttons/mainmenu/options3.png");

    credits[0]=IMG_Load("playbuttons/mainmenu/credits1.png");
    credits[1]=IMG_Load("playbuttons/mainmenu/credits2.png");
    credits[2]=IMG_Load("playbuttons/mainmenu/credits3.png");

    exit[0]=IMG_Load("playbuttons/mainmenu/quit1.png");
    exit[1]=IMG_Load("playbuttons/mainmenu/quit2.png");
    exit[2]=IMG_Load("playbuttons/mainmenu/quit3.png");
Uint32 start;
const int FPS=30;
        animation=IMG_Load("animation/animation3.png");
  
int curframe=0;
int maxframe=7,j=0;

Mix_Chunk *stone ;

 stone = Mix_LoadWAV( "SOUND/bref.wav" );


 
 
 
   //Mix_VolumeChunk(stone, MIX_MAX_VOLUME/8);
    int done=1;
    
    while (done)
    {
        start=SDL_GetTicks();
    
        
   if (j==7)
        j=0;
  
 
    //affichage des images
	SDL_BlitSurface(background,NULL,screen,&pos);
   
   
     SDL_BlitSurface(animation,&frame,screen,&ani[j]);
    if(5000/FPS > SDL_GetTicks()-start) {
                        SDL_Delay(5000/FPS-(SDL_GetTicks()-start));
                }
                 SDL_BlitSurface(newgame[ng],NULL,screen,&posng);
    SDL_BlitSurface(loadgame[lg],NULL,screen,&poslg);
    SDL_BlitSurface(option[op],NULL,screen,&posop);
    
    SDL_BlitSurface(credits[cr],NULL,screen,&poscr);
    SDL_BlitSurface(exit[ex],NULL,screen,&posq);
  SDL_Flip(screen);
     curframe++;
     if(curframe>maxframe)
    { curframe=0;}
 frame.x= curframe*frame.w;
     
     j++;	
  
while (SDL_PollEvent(&event))
{            
if (t==1)
 Mix_PlayChannel( -1,stone, 0 );
t=0;

     switch(event.type)
     {case SDL_QUIT:
     done = 0;
  case SDL_KEYDOWN:
    switch(event.key.keysym.sym)
{case SDLK_ESCAPE:
             done = 0;
     break;

                    case SDLK_UP:
    
                    
                    if (ng==0 && op==0 && ex==0 && lg==0 && cr==0)
                    {ex=1;
                        t=1;}
                        if (ex==1 && t==0){
                            ng=0;
                            ex=0;
                            op=0;
                            cr=1;
                            lg=0;
                            t=1;
                            
                        }
                        else if(cr==1 && t==0)
                        {
                                ng=0;
                                lg=0;
                                op=1;
                                ex=0;
                                cr=0;
                                t=1;
                            }
                            else if(op==1 && t==0){
                                ng=0;
                                lg=1;
                                ex=0;
                                cr=0;
                                t=1;
                                op=0;
                            }
     
                        else if (ng==1 && t==0)
                        {
                            op=0;
                            cr=0;
                            op=0;
                            ex=1;
                            t=1;
                            ng=0;
                        }

                        else if (lg==1 && t==0)
                        {
                            ng=1;
                            lg=0;
                            op=0;
                            ex=0;
                            t=1;
                        }
                    break;

                    case SDLK_DOWN:
                  
                    if (ng==0 && op==0 && ex==0 && lg==0 && cr==0)
                    {ng=1;
                      t=1;}
                        if (ng==1 && t==0)
                            {
                                ng=0;
                                lg=1;
                                op=0;
                                ex=0;
                                t=1;
                                cr=0;
                            }
                            else if(lg==1 && t==0){
                                ng=0;
                                op=1;
                                ex=0;
                                
                                cr=0;
                                lg=0;
                                t=1;
                            }
                        
                        else if(op==1 && t==0){
                            ng=0;
                            op=0;
                            cr=1;
                            lg=0;
                            t=1;
                        }
                        else if (cr==1 && t==0){
                            op=0;
                            ex=1;
                            ng=0;
                            cr=0;
                            lg=0;
                            t=1;
                        }
                        else if (ex==1 && t==0)
                        {
                            ng=1;
                            lg=0;
                            op=0;
                            ex=0;
                            cr=0;
                            t=1;
                        }
                    break;
                    case SDLK_RETURN:
                        if (ng==1)
                        {
                            SDL_BlitSurface(newgame[2],NULL,screen,&posng);
                            SDL_Flip(screen);
                            SDL_Delay(100);
                        (action)=1;
                           c=0;
                           play(screen);
                        }
                                         else if (lg==1)
                                        {

                          SDL_BlitSurface(loadgame[2],NULL,screen,&poslg);
                            SDL_Flip(screen);
                            SDL_Delay(100);
                      (action)=2;
                                  c=0;  }
                        else if (op==1)
                        {
                            SDL_BlitSurface(option[2],NULL,screen,&posop);
                            SDL_Flip(screen);
                            SDL_Delay(100);
r=options(screen, action);

                        action=3;
                            c=0;
                        }
                                        else if (cr==1)
                                        {

                          SDL_BlitSurface(credits[2],NULL,screen,&poscr);
                            SDL_Flip(screen);
                            SDL_Delay(100);
                      (action)=4;
r=credit(screen);
                                  c=0;  }
                                else if (ex==1)
                        {
                    ex=2;
                        SDL_Delay (100);
quit(screen);
        
                        }
                       
                    break;
                
            }break;

//avec souris
            case SDL_MOUSEMOTION:{
                ng=0;
                lg=0;
                op=0;
                cr=0;
                ex=0;
            Mix_PlayChannel( -1, stone, 0 );

                    
if(event.motion.x >= posng.x && event.motion.x <= (posng.x + 150) && event.motion.y >= posng.y && event.motion.y <= (posng.y + 100))
                {
                ng=1;
                }
 else if            
(event.motion.x >= poslg.x && event.motion.x <= (poslg.x + 150) && event.motion.y >= poslg.y && event.motion.y <= (poslg.y + 100))
                {
                    lg=1;
                    

                }
else if 
(event.motion.x >= posop.x && event.motion.x <= (posop.x + 150) && event.motion.y >= posop.y && event.motion.y <= (posop.y + 100))
                {
                op=1;
                
}


else if                 
(event.motion.x >= poscr.x && event.motion.x <= (poscr.x + 150) && event.motion.y >= poscr.y && event.motion.y <= (poscr.y + 100))
                {
                    cr=1;
                    

                }
else if                 
(event.motion.x >= posq.x && event.motion.x <= (posq.x + 150) && event.motion.y >= posq.y && event.motion.y <= (posq.y + 100))
                {
                ex=1;
                

                }


            }break;

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button==SDL_BUTTON_LEFT)
                {
                    if (ng==1)
                    {
                        ng=2;
                        SDL_Delay (100);
                (action)=1;
                play(screen);
                    c=0;
                    }

                           else if (lg==1)
                    {
                    lg=2;
                    SDL_Delay (100);
                (action)=2;        c=0;
                    }
                    else if (op==1)
                    {
                    op=2;
                    SDL_Delay (100);
                (action)=3;
                    c=0;
                    r=options(screen, action);
                    }
                            else if (cr==1)
                    {
                    cr=2;
                    SDL_Delay (100);
                (action)=4;
                    c=0;
                    r=credit(screen);
                    }
                    
            
                    else if (ex==1)
                    {
                
                    ex=2;
                    SDL_Delay (100);
                    (action)=5;
                    quit(screen);

}
                    
                      break;}}


            
}

}
if (done==0)
    {SDL_FreeSurface(background);
    SDL_FreeSurface(newgame[0]);
        SDL_FreeSurface(newgame[1]);
        SDL_FreeSurface(newgame[2]);
        SDL_FreeSurface(loadgame[0]);
        SDL_FreeSurface(loadgame[1]);
        SDL_FreeSurface(loadgame[2]);
        SDL_FreeSurface(option[0]);
        SDL_FreeSurface(option[1]);
        SDL_FreeSurface(option[2]);
        SDL_FreeSurface(credits[0]);
        SDL_FreeSurface(credits[1]);
        SDL_FreeSurface(credits[2]);
        SDL_FreeSurface(exit[0]);
        SDL_FreeSurface(exit[1]);
        SDL_FreeSurface(exit[2]);

        Mix_CloseAudio();
SDL_Quit();}
}
     int  options(SDL_Surface * screen,int actiono)
{

Mix_Chunk *stone ;

 stone = Mix_LoadWAV( "SOUND/bref.wav" );
SDL_Surface *background=NULL;
background =IMG_Load("tabumba 2.1.png");
SDL_Rect background_pos;
SDL_Rect poson,posgr,posco,posre;
background_pos.x=0;
background_pos.y=0;
poson.x=640/2.6;
poson.y=740/3.7;
posgr.x=640/2.6;
posgr.y=740/2.39;
posco.x=640/2.6;
posco.y= 740/1.76;

int son=0,gr=0,co=0,cr=0,c=0,i=0,j=0,R=0,re=0;

SDL_Surface *sound[3],*graphics[3],*commands[3];

    SDL_Rect pos;
    pos.x=0;
    pos.y=0;

posre.x=640/1.42;
posre.y=740/1.4;
SDL_Surface *back[3];
    SDL_Event event;
    int t,save;
    sound[0]=IMG_Load("playbuttons/options/son1.png");
    sound[1]=IMG_Load("playbuttons/options/son2.png");
    sound[2]=IMG_Load("playbuttons/options/son3.png");
    
    graphics[0]=IMG_Load("playbuttons/options/graphics1.png");
    graphics[1]=IMG_Load("playbuttons/options/graphics2.png");
    graphics[2]=IMG_Load("playbuttons/options/graphics3.png");

    commands[0]=IMG_Load("playbuttons/options/commands1.png");
    commands[1]=IMG_Load("playbuttons/options/commands2.png");
    commands[2]=IMG_Load("playbuttons/options/commands3.png");
    back[0]=IMG_Load("playbuttons/options/return1.png");
    back[1]=IMG_Load("playbuttons/options/return2.png");
    back[2]=IMG_Load("playbuttons/options/return3.png");

    


    while (R==0)
    {

    //affichage des images
    SDL_BlitSurface(background,NULL,screen,&pos);
    SDL_BlitSurface(sound[son],NULL,screen,&poson);
    SDL_BlitSurface(graphics[gr],NULL,screen,&posgr);
    SDL_BlitSurface(commands[co],NULL,screen,&posco);
    SDL_BlitSurface(back[re],NULL,screen,&posre);
    
    
    SDL_Flip(screen);
   
        
   

while (SDL_PollEvent(&event)){
if (t==1)
 Mix_PlayChannel( -1,stone, 0 );
t=0;
     switch(event.type)
     {
  case SDL_KEYDOWN:
    switch(event.key.keysym.sym)
{case SDLK_ESCAPE:
             R=1;
     break;

                    case SDLK_UP:
                    if (son==0 && gr==0 && co==0)
                    {co=1;}
                        if (co==1 && t==0){
                            son=0;
                            gr=1;
                            co=0;
                            t=1;
                            re=0;
                        }
                        else if(gr==1 && t==0)
                        {
                                son=1;
                                gr=0;
                                co=0;
                                t=1;
                                re=0;
                            }
                            else if(son==1 && t==0){
                            son=0;
                            gr=0;
                            co=1;
                            t=1;
                            re=0;
                            }
     
                        
                    break;
                     case SDLK_RIGHT:
                            
                            re=1;
                             son=0;
                            gr=0;
                            co=0;
                            t=1;
                            break;

                    case SDLK_DOWN:
                    if (son==0 && gr==0 && co==0)
                    {son=1;
                      t=1;}
                        if (son==1 && t==0)
                            {
                                son=0;
                                gr=1;
                                co=0;
                                t=1;
                                re=0;
                            }
                            else if(gr==1 && t==0){
                                  son=0;
                                gr=0;
                                co=1;
                                t=1;
                                re=0;
                            }
                        
                        else if(co==1 && t==0){
                                son=1;
                                gr=0;
                                co=0;
                                t=1;
                                re=0;
                        }
                       
                    break;
                    case SDLK_RETURN:
                        if (son==1)
                        {
                            SDL_BlitSurface(sound[2],NULL,screen,&poson);
                            SDL_Flip(screen);
                            SDL_Delay(100);
                        (actiono)=1;
                        volume(screen);
                           c=0;
                        }
                                         else if (gr==1)
                                        {

                          SDL_BlitSurface(graphics[2],NULL,screen,&posgr);
                            SDL_Flip(screen);
                            SDL_Delay(100);
                      (actiono)=3;
                      graphique(screen);
                                  c=0;  }
                        else if (co==1)
                        {
                            SDL_BlitSurface(commands[2],NULL,screen,&posco);
                            SDL_Flip(screen);
                            SDL_Delay(100);
commandes(screen);
                        (actiono)=2;
                            c=0;
                        }
                        if (re==1)
                                        {

                          SDL_BlitSurface(back[2],NULL,screen,&posre);
                            SDL_Flip(screen);
                            SDL_Delay(100);
                      (R)=1;
                      menu (screen);
                                    }                  
                  
                       
                    break;
                   

                
            }break;

//avec souris
            case SDL_MOUSEMOTION:{
                son=0;
                gr=0;
                co=0;
            son=0;
                                gr=0;
                                co=0;
                            
                                re=0;

 Mix_PlayChannel( -1,stone, 0 );
                    
if(event.motion.x >= poson.x && event.motion.x <= (poson.x + 150) && event.motion.y >= poson.y && event.motion.y <= (poson.y + 100))
                {
               son=1;
                }
 else if            
(event.motion.x >= posgr.x && event.motion.x <= (posgr.x + 150) && event.motion.y >= posgr.y && event.motion.y <= (posgr.y + 100))
                {
                    gr=1;
                    

                }
else if 
(event.motion.x >= posco.x && event.motion.x <= (posco.x + 150) && event.motion.y >= posco.y && event.motion.y <= (posco.y + 100))
                {
               co=1;
                
}
else if
(event.motion.x >= posre.x && event.motion.x <= (posre.x + 150) && event.motion.y >= posre.y && event.motion.y <= (posre.y + 100))
                {
                re=1;
                }

            }break;

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button==SDL_BUTTON_LEFT)
                {
                    if (son==1)
                    {
                        son=2;
                        SDL_Delay (100);
                (actiono)=1;
                    c=0;
                    volume(screen);
                    }

                           else if (gr==1)
                    {
                    gr=2;
                    SDL_Delay (100);
                (actiono)=2;        c=0;
                graphique(screen);
                    }
                    else if (co==1)
                    {
                    co=2;
                    commandes(screen);
                    SDL_Delay (100);
                (actiono)=3;
                    c=0;
                    }
                     if (re==1)
                    {
                    re=2;
                    SDL_Delay (100);
                (R)=1;
                  menu (screen);  
                    }
                           
                    
                      break;}}


            

}
}
if (R==1)
    SDL_FreeSurface(background);
    SDL_FreeSurface(sound[0]);
        SDL_FreeSurface(sound[1]);
        SDL_FreeSurface(sound[2]);
        SDL_FreeSurface(graphics[0]);
        SDL_FreeSurface(graphics[1]);
        SDL_FreeSurface(graphics[2]);
        SDL_FreeSurface(commands[0]);
        SDL_FreeSurface(commands[1]);
        SDL_FreeSurface(commands[2]);
       

SDL_Quit();
return actiono;}
    		//avec clavier

 int back(SDL_Surface *screen,int x)
{Mix_Chunk *stone ;

 stone = Mix_LoadWAV( "SOUND/bref.wav" );
SDL_Rect posre;
int screenx=640,screeny=740,R=0;
posre.x=screenx/1.42;
posre.y=screeny/1.4;
SDL_Surface *back[3];
SDL_Event event;


int re=0,t=0,done=1;
back[0]=IMG_Load("playbuttons/options/return1.png");
    back[1]=IMG_Load("playbuttons/options/return2.png");
    back[2]=IMG_Load("playbuttons/options/return3.png");
    while (R==0)
    {SDL_BlitSurface(back[re],NULL,screen,&posre);
SDL_Flip(screen);
     
SDL_WaitEvent(&event);

     switch(event.type)
     {
  case SDL_KEYDOWN:
    switch(event.key.keysym.sym)
{case SDLK_ESCAPE:
             R=1;
     break;

                
                     case SDLK_RIGHT:
 Mix_PlayChannel( -1,stone, 0 );
                            
                            re=1; break; 
                            case SDLK_RETURN:
                            if (re==1)
                                        {

                          SDL_BlitSurface(back[2],NULL,screen,&posre);
                            SDL_Flip(screen);
                            SDL_Delay(100);
                      (R)=1;
                                    }  
         }break;
         case SDL_MOUSEMOTION:

 Mix_PlayChannel( -1,stone, 0 );
         if 
(event.motion.x >= posre.x && event.motion.x <= (posre.x + 150) && event.motion.y >= posre.y && event.motion.y <= (posre.y + 100))
                {
                re=1;
                }break;

case SDL_MOUSEBUTTONDOWN:
  if (re==1)
                    {
                    re=2;
                    SDL_Delay (100);
                (R)=1;
                    
                    }


break;

            break;

                               }}
if (R==0)
 SDL_FreeSurface(back[0]);
        SDL_FreeSurface(back[1]);
        SDL_FreeSurface(back[2]);
        if (x==1) 
menu (screen);
else if (x==2)
                             R=options(screen,t);


        return R;
    }

int credit(SDL_Surface *screen)
{Mix_Chunk *stone ;

 stone = Mix_LoadWAV( "SOUND/bref.wav" );
    SDL_Surface *background=NULL,*texte1,*texte2,*texte3,*texte4,*game;
SDL_Rect background_pos;
int r=0;

TTF_Font *police = NULL;
SDL_Rect positiont2,positiont1,positiont3,positiont4,poslogo;
int done=0;
background_pos.x=0;
background_pos.y=0;
poslogo.x=500;
poslogo.y=40;
positiont1.x=10;
positiont1.y=10; 
positiont2.x=10;
positiont2.y=40;
positiont3.x=10;
positiont3.y=80;
positiont4.x=10;


 SDL_Color couleurNoire ={139,0,0};
 SDL_Color couleurNoire2 ={230,230,250};
 police = TTF_OpenFont("playbuttons/credits/Headlight.ttf", 15);
texte1 = TTF_RenderText_Shaded(police,"Hello World! we are CodeBrewers",couleurNoire,couleurNoire2);
texte2 = TTF_RenderText_Shaded(police,"our team is composed of 6 futur engineers  ",couleurNoire,couleurNoire2);
texte3 = TTF_RenderText_Shaded(police,"Fourat,Sejir,Yahya,Arij,Chiheb and Assyl",couleurNoire,couleurNoire2);
texte4 = TTF_RenderText_Shaded(police,"Hope you enjoy our game",couleurNoire,couleurNoire2);
game = IMG_Load("playbuttons/credits/logo.png");
background =IMG_Load("tabumba 2.1.png");



while(done==0)
{


SDL_BlitSurface(background,NULL,screen,&background_pos);
SDL_BlitSurface(game,NULL,screen,&poslogo); 

SDL_BlitSurface(texte1,NULL,screen,&positiont1);
SDL_BlitSurface(texte2,NULL,screen,&positiont2);
SDL_BlitSurface(texte3,NULL,screen,&positiont3);
SDL_BlitSurface(texte4,NULL,screen,&positiont4);
done=back(screen,1);
SDL_Flip(screen);}
return r;}


void quit(SDL_Surface *screen)
{Mix_Chunk *stone ;

 stone = Mix_LoadWAV( "SOUND/bref.wav" );
    SDL_Surface *background=NULL,*yes[3],*no[3],*rys;
    int ye,na,r=0;
SDL_Rect background_pos;
SDL_Rect posyes,posno,posrys;
int screenx=640;
int screeny=740;
TTF_Font *police = NULL;
background_pos.x=0;
background_pos.y=0;
SDL_Event event;
posrys.x=screenx/6.4;
posrys.y=screeny/5.69;
posyes.x=screenx/1.73;
posyes.y=screeny/2;
posno.x=640/12.8;
posno.y=screeny/2;
SDL_Color couleurNoire ={139,0,0};
 SDL_Color couleurNoire2 ={230,230,250};
 police = TTF_OpenFont("playbuttons/credits/Headlight.ttf",30);
rys = TTF_RenderText_Shaded(police,"Are you sure ?",couleurNoire,couleurNoire2);
yes[0] = IMG_Load("playbuttons/quit/yes1.png");
yes[1] = IMG_Load("playbuttons/quit/yes2.png");
yes[2] = IMG_Load("playbuttons/quit/yes3.png");
no[0] = IMG_Load("playbuttons/quit/no1.png");
no[1] = IMG_Load("playbuttons/quit/no2.png");
no[2] = IMG_Load("playbuttons/quit/no3.png");
background =IMG_Load("tabumba 2.1.png");
int x=0;
int done=1;
    while (done==1)
    {

    //affichage des images
SDL_BlitSurface(background,NULL,screen,&background_pos);
SDL_BlitSurface(yes[ye],NULL,screen,&posyes);
SDL_BlitSurface(no[na],NULL,screen,&posno);
SDL_BlitSurface(rys,NULL,screen,&posrys);
    SDL_Flip(screen);
      
     int t;
   

while (SDL_PollEvent(&event)){
if (t==1)
 Mix_PlayChannel( -1,stone, 0 );
t=0;
     switch(event.type)
     {case SDL_QUIT:
     done = 0;
     break;
  case SDL_KEYDOWN:
    switch(event.key.keysym.sym)
{case SDLK_ESCAPE:
             done = 0;
     break;
     case SDLK_RIGHT:
     
        ye=1;
        na=0;
        t=1 ;               
     break;
     case SDLK_LEFT:
    
     na=1;
     ye=0;
     t=1;
                   

     break;
     case SDLK_RETURN:
     if (ye==1)
      {ye=2;
                        SDL_Delay (100);
                done=0;
                x=2;}
                if (na==1)
    { na=2;
        SDL_Delay (100);
                   
done=0;
x=1;}








}break;
case SDL_MOUSEMOTION:{
               ye=0;
                na=0;           

 Mix_PlayChannel( -1,stone, 0 );
                    
if(event.motion.x >= posyes.x && event.motion.x <= (posyes.x + 150) && event.motion.y >= posyes.y && event.motion.y <= (posyes.y + 100))
                {
               ye=1;
                }
 else if            
(event.motion.x >= posno.x && event.motion.x <= (posno.x + 150) && event.motion.y >= posno.y && event.motion.y <= (posno.y + 100))
                {
                    na=1;
                    

                }
}break;

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button==SDL_BUTTON_LEFT)
                {
                    if (ye==1)
                    {
                        ye=2;
                        done=0;
                        SDL_Delay (100);
                x=2;
                    }

                           else if (na==1)
                    {done=0;
                    na=2;
                   x=1;
menu (screen);
}}
                    
break;
}}}
if (x==1){menu(screen);}
if (x==2)
{
   SDL_FreeSurface(yes[0]);
        SDL_FreeSurface(yes[1]);
        SDL_FreeSurface(yes[2]);
         SDL_FreeSurface(no[0]);
        SDL_FreeSurface(no[1]);
        SDL_FreeSurface(no[2]);
SDL_Quit();
}
}
void graphique(SDL_Surface *screen)
{Mix_Chunk *stone ;

 stone = Mix_LoadWAV( "SOUND/bref.wav" );
    SDL_Surface *background=NULL;
   int screenx=640,screeny=740;
background =IMG_Load("tabumba 2.1.png");
SDL_Rect background_pos;
SDL_Rect poson,posgr,posco,posre;
background_pos.x=0;
background_pos.y=0;
poson.x=640/2.6;
poson.y=740/3.7;
posgr.x=640/2.6;
posgr.y=740/2.39;
posco.x=640/2.6;
posco.y= 740/1.76;

int son=0,gr=0,co=0,cr=0,c=0,i=0,j=0,R=0,re=0;

SDL_Surface *window[3],*fullscreen[3];

    SDL_Rect pos;
    pos.x=0;
    pos.y=0;

posre.x=640/1.42;
posre.y=740/1.4;
SDL_Surface *back[3];
    SDL_Event event;
    int t,save;
    fullscreen[0]=IMG_Load("playbuttons/options/fullscreen1.png");
    fullscreen[1]=IMG_Load("playbuttons/options/fullscreen2.png");
    fullscreen[2]=IMG_Load("playbuttons/options/fullscreen3.png");
    
    window[0]=IMG_Load("playbuttons/options/windowed1.png");
    window[1]=IMG_Load("playbuttons/options/windowed2.png");
    window[2]=IMG_Load("playbuttons/options/windowed3.png");


    back[0]=IMG_Load("playbuttons/options/return1.png");
    back[1]=IMG_Load("playbuttons/options/return2.png");
    back[2]=IMG_Load("playbuttons/options/return3.png");

    


    while (R==0)
    {

    //affichage des images
    SDL_BlitSurface(background,NULL,screen,&pos);
    SDL_BlitSurface(fullscreen[son],NULL,screen,&poson);
    SDL_BlitSurface(window[gr],NULL,screen,&posgr);
  
    SDL_BlitSurface(back[re],NULL,screen,&posre);
    
    
    SDL_Flip(screen);
        
        
   

while (SDL_PollEvent(&event)){
if (t==1)
 Mix_PlayChannel( -1,stone, 0 );
t=0;
     switch(event.type)
     {
  case SDL_KEYDOWN:
    switch(event.key.keysym.sym)
{case SDLK_ESCAPE:
             R=1;
     break;

                    case SDLK_UP:
                    if (son==0 && gr==0 && co==0)
                    {gr=1;
                        re=0;}
                        if (gr==1 && t==0){
                            son=1;
                            gr=0;
                            co=0;
                            t=1;
                            re=0;
                        }
                        else if(son==1 && t==0)
                        {
                                son=0;
                                gr=1;
                                co=0;
                                t=1;
                                re=0;
                            }

     
                        
                    break;
                     case SDLK_RIGHT:
                            
                            re=1;
                            son=0;
                                gr=0;
                                co=0;
                                t=1;
                                break;

                    case SDLK_DOWN:
                    if (son==0 && gr==0 && co==0)
                    {son=1;
                      t=1;
                      re=0;}
                        if (son==1 && t==0)
                            {
                                son=0;
                                gr=1;
                                co=0;
                                t=1;
                                re=0;
                            }
                            else if(gr==1 && t==0){
                                  son=1;
                                gr=0;
                              
                                t=1;
                                re=0;
                            }
                        

                       
                    break;
                    case SDLK_RETURN:
                        if (son==1)
                        {
                            SDL_BlitSurface(fullscreen[2],NULL,screen,&poson);
                            SDL_Flip(screen);
                            SDL_Delay(100);
                        screen = SDL_SetVideoMode(screenx,screeny,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN); 
                           c=0;
                        }
                                         else if (gr==1)
                                        {

                          SDL_BlitSurface(window[2],NULL,screen,&posgr);
                            SDL_Flip(screen);
                            SDL_Delay(100);
                      screen = SDL_SetVideoMode(screenx,screeny,32,SDL_HWSURFACE|SDL_DOUBLEBUF); 
                                  c=0;  }
           
                       
                        if (re==1)
                                        {

                          SDL_BlitSurface(back[2],NULL,screen,&posre);
                            SDL_Flip(screen);
                            SDL_Delay(100);
                      (R)=1;
                             R=options(screen,t);  
                                    }                  
                  
                       
                    break;
                   

                
            }break;

//avec souris
            case SDL_MOUSEMOTION:{
             gr=0;
                                son=0;
                            
                                re=0;

 Mix_PlayChannel( -1,stone, 0 );
                    
if(event.motion.x >= poson.x && event.motion.x <= (poson.x + 150) && event.motion.y >= poson.y && event.motion.y <= (poson.y + 100))
                {
               son=1;
                }
 else if            
(event.motion.x >= posgr.x && event.motion.x <= (posgr.x + 150) && event.motion.y >= posgr.y && event.motion.y <= (posgr.y + 100))
                {
                    gr=1;
                    

                }

else if
(event.motion.x >= posre.x && event.motion.x <= (posre.x + 150) && event.motion.y >= posre.y && event.motion.y <= (posre.y + 100))
                {
                re=1;
                }

            }break;

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button==SDL_BUTTON_LEFT)
                {
                    if (son==1)
                    {
                        son=2;
                        SDL_Delay (100);
               
                    c=0;
                    }

                           else if (gr==1)
                    {
                    gr=2;
                    SDL_Delay (100);
                      c=0;
                    }
               
                     if (re==1)
                    {
                    re=2;
                    SDL_Delay (100);
                (R)=1;
                  R=options(screen,t);  
                    }
                           
                    
                      break;}}


            


}}
if (R==1)
    SDL_FreeSurface(background);
    SDL_FreeSurface(fullscreen[0]);
        SDL_FreeSurface(fullscreen[1]);
        SDL_FreeSurface(fullscreen[2]);
        SDL_FreeSurface(window[0]);
        SDL_FreeSurface(window[1]);
        SDL_FreeSurface(window[2]);
        SDL_FreeSurface(back[0]);
        SDL_FreeSurface(back[1]);
        SDL_FreeSurface(back[2]);
       

SDL_Quit();
}
void volume(SDL_Surface * screen)
{

Mix_Chunk *stone ;

 stone = Mix_LoadWAV( "SOUND/bref.wav" );
int b=128;
SDL_Surface *background=NULL;
background =IMG_Load("tabumba 2.1.png");
SDL_Rect background_pos;
SDL_Rect poson,posgr,posco,posre;
background_pos.x=0;
background_pos.y=0;
poson.x=640/2.6;
poson.y=740/3.7;
posgr.x=640/2.6;
posgr.y=740/2.39;
posco.x=640/2.6;
posco.y= 740/1.76;

int son=0,gr=0,co=0,cr=0,c=0,i=0,j=0,R=0,re=0,M=0;

SDL_Surface *vup[3],*vdown[3],*mute[3];

    SDL_Rect pos;
    pos.x=0;
    pos.y=0;

posre.x=640/1.42;
posre.y=740/1.4;
SDL_Surface *back[3];
    SDL_Event event;
    int t,save;
    vup[0]=IMG_Load("playbuttons/options/v++1.png");
    vup[1]=IMG_Load("playbuttons/options/v++2.png");
    vup[2]=IMG_Load("playbuttons/options/v++3.png");
    
    vdown[0]=IMG_Load("playbuttons/options/v--1.png");
    vdown[1]=IMG_Load("playbuttons/options/v--2.png");
    vdown[2]=IMG_Load("playbuttons/options/v--3.png");

    mute[0]=IMG_Load("playbuttons/options/mute1.png");
    mute[1]=IMG_Load("playbuttons/options/mute2.png");
    mute[2]=IMG_Load("playbuttons/options/mute3.png");
    back[0]=IMG_Load("playbuttons/options/return1.png");
    back[1]=IMG_Load("playbuttons/options/return2.png");
    back[2]=IMG_Load("playbuttons/options/return3.png");
int actiono=0;
    


    while (R==0)
    {

    //affichage des images
    SDL_BlitSurface(background,NULL,screen,&pos);
    SDL_BlitSurface(vup[son],NULL,screen,&poson);
    SDL_BlitSurface(vdown[gr],NULL,screen,&posgr);
    SDL_BlitSurface(mute[co],NULL,screen,&posco);
    SDL_BlitSurface(back[re],NULL,screen,&posre);
    
    
    SDL_Flip(screen);
       
        
   

while (SDL_PollEvent(&event)){
if (t==1)
 Mix_PlayChannel( -1,stone, 0 );
t=0;
     switch(event.type)
     {
  case SDL_KEYDOWN:
    switch(event.key.keysym.sym)
{case SDLK_ESCAPE:
             R=1;
     break;

                    case SDLK_UP:
                    if (son==0 && gr==0 && co==0)
                    {co=1;
                        re=0;}
                        if (co==1 && t==0){
                            son=0;
                            gr=1;
                            co=0;
                            t=1;
                            re=0;
                        }
                        else if(gr==1 && t==0)
                        {
                                son=1;
                                gr=0;
                                co=0;
                                t=1;
                                re=0;
                            }
                            else if(son==1 && t==0){
                            son=0;
                            gr=0;
                            co=1;
                            t=1;
                            re=0;
                            }
     
                        
                    break;
                     case SDLK_RIGHT:
                            
                          son=0;
 gr=0;
co=0;  re=1; break;

                    case SDLK_DOWN:
                    if (son==0 && gr==0 && co==0)
                    {son=1;
                        re=0;
                      t=1;}
                        if (son==1 && t==0)
                            {
                                son=0;
                                gr=1;
                                co=0;
                                t=1;
                                re=0;
                            }
                            else if(gr==1 && t==0){
                                  son=0;
                                gr=0;
                                co=1;
                                t=1;
                                re=0;
                            }
                        
                        else if(co==1 && t==0){
                                son=1;
                                gr=0;
                                co=0;
                                t=1;
                                re=0;
                        }
                       
                    break;
                    case SDLK_RETURN:
                        if (son==1)
                        {
                            SDL_BlitSurface(vup[2],NULL,screen,&poson);
                            SDL_Flip(screen);
                            SDL_Delay(100);
                       b=b+32;
Mix_VolumeMusic(b);
                           c=0;
                        }
                                         else if (gr==1)
                                        {

                          SDL_BlitSurface(vdown[2],NULL,screen,&posgr);
                            SDL_Flip(screen);
                            SDL_Delay(100);
                     b=b-32;
Mix_VolumeMusic(b-32);
                      
                                  c=0;  }
                        else if (co==1)
                        {
                            SDL_BlitSurface(mute[2],NULL,screen,&posco);
                            SDL_Flip(screen);
       
                            SDL_Delay(100);
switch(M)
{case 0:
Mix_PauseMusic();
M=1;           
break;
case 1:
                Mix_ResumeMusic();
                M=0;        
                            c=0;
                       break; }}
                        if (re==1)
                                        {

                          SDL_BlitSurface(back[2],NULL,screen,&posre);
                            SDL_Flip(screen);
                            SDL_Delay(100);
                      (R)=1;
                       
                                    }                  
                  
                       
                    break;
                   

                
            }break;

//avec souris
            case SDL_MOUSEMOTION:{
                son=0;
                gr=0;
                co=0;
            son=0;
                                gr=0;
                                co=0;
                            
                                re=0;

 Mix_PlayChannel( -1,stone, 0 );
                    
if(event.motion.x >= poson.x && event.motion.x <= (poson.x + 150) && event.motion.y >= poson.y && event.motion.y <= (poson.y + 100))
                {
               son=1;
                }
 else if            
(event.motion.x >= posgr.x && event.motion.x <= (posgr.x + 150) && event.motion.y >= posgr.y && event.motion.y <= (posgr.y + 100))
                {
                    gr=1;
                    

                }
else if 
(event.motion.x >= posco.x && event.motion.x <= (posco.x + 150) && event.motion.y >= posco.y && event.motion.y <= (posco.y + 100))
                {
               co=1;
                
}
else if
(event.motion.x >= posre.x && event.motion.x <= (posre.x + 150) && event.motion.y >= posre.y && event.motion.y <= (posre.y + 100))
                {
                re=1;
                }

            }break;

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button==SDL_BUTTON_LEFT)
                {
                    if (son==1)
                    {
                        son=2;
                        SDL_Delay (100);
                                               b=b+32;
Mix_VolumeMusic(b);
                
                    c=0;

                    }

                           else if (gr==1)
                    {
                    gr=2;
                    SDL_Delay (100);
                    b=b-32;
Mix_VolumeMusic(b-32);
    c=0;
                
                    }
                    else if (co==1)
                    {
                    co=2;
                    SDL_Delay (100);
                   switch(M)
{case 0:
Mix_PauseMusic();
M=1;           
break;
case 1:
                Mix_ResumeMusic();
                M=0;        
                            c=0;
                       break; }
                    }
                     if (re==1)
                    {
                    re=2;
                    SDL_Delay (100);
                (R)=1;

                
  
                    }
                           
                    
                      break;}}


            

}
}
if (R==1)
     R=options(screen,actiono);
    SDL_FreeSurface(background);
    SDL_FreeSurface(vdown[0]);
        SDL_FreeSurface(vdown[1]);
        SDL_FreeSurface(vdown[2]);
        SDL_FreeSurface(vup[0]);
        SDL_FreeSurface(vup[1]);
        SDL_FreeSurface(vup[2]);
        SDL_FreeSurface(back[0]);
        SDL_FreeSurface(back[1]);
        SDL_FreeSurface(back[2]);
        SDL_FreeSurface(mute[0]);
        SDL_FreeSurface(mute[1]);
        SDL_FreeSurface(mute[2]);
       

SDL_Quit();
}

void play(SDL_Surface *screen)
{

Mix_Chunk *stone ;

 stone = Mix_LoadWAV( "SOUND/bref.wav" );


SDL_Surface *background=NULL,*single[3],*multi[3],*back[3];
    int sin=0,na=0,re=0,r=0;
SDL_Rect background_pos;
SDL_Rect possin,posno,posrys,posre;
int screenx=640;
int screeny=740;
TTF_Font *police = NULL;
background_pos.x=0;
background_pos.y=0;
SDL_Event event;
posrys.x=screenx/6.4;
posrys.y=screeny/5.69;
possin.x=screenx/1.73;
possin.y=screeny/2;
posno.x=640/12.8;
posno.y=screeny/2;

posre.x=640/1.42;
posre.y=740/1.4;
SDL_Color couleurNoire ={139,0,0};
back[0]=IMG_Load("playbuttons/options/return1.png");
    back[1]=IMG_Load("playbuttons/options/return2.png");
    back[2]=IMG_Load("playbuttons/options/return3.png");
single[0] = IMG_Load("playbuttons/play/single1.png");
single[1] = IMG_Load("playbuttons/play/single2.png");
single[2] = IMG_Load("playbuttons/play/single3.png");
multi[0] = IMG_Load("playbuttons/play/multi1.png");
multi[1] = IMG_Load("playbuttons/play/multi2.png");
multi[2] = IMG_Load("playbuttons/play/multi3.png");
background =IMG_Load("tabumba 2.1.png");

int done=1;
    while (done)
    {

    //affichage des images
SDL_BlitSurface(background,NULL,screen,&background_pos);
SDL_BlitSurface(single[sin],NULL,screen,&possin);
SDL_BlitSurface(multi[na],NULL,screen,&posno);
SDL_BlitSurface(back[re],NULL,screen,&posre);
    SDL_Flip(screen);
      
     int t;
   

while (SDL_PollEvent(&event)){
    if (t==1)
 Mix_PlayChannel( -1,stone, 0 );
t=0;

     switch(event.type)
     {case SDL_QUIT:
     done = 0;break;
  case SDL_KEYDOWN:
    switch(event.key.keysym.sym)
{case SDLK_ESCAPE:
             done = 0;
     break;
     case SDLK_LEFT:
     if (sin==0 && na==0 && re==0)
                    {na=1;
                        }
                        else if (na==1 && t==0){
                            sin=0;
                            na=0;
                           
                            t=1;
                            re=1;
                        }
                        else if(re==1 && t==0)
                        {
                                sin=1;
                                na=0;
                               
                                t=1;
                                re=0;
                            }
                            else if(sin==1 && t==0)
                            {
                            sin=0;
                            na=1;
                            
                            t=1;
                            re=0;
                            }
              

                              
     break;
     case SDLK_RIGHT:
   if (sin==0 && na==0 && re==0)
                    {sin=1;
                    }
                        else if (sin==1 && t==0){
                            sin=0;
                            na=0;
                           
                            t=1;
                            re=1;
                        }
                        else if(re==1 && t==0)
                        {
                                sin=0;
                                na=1;
                               
                                t=1;
                                re=0;
                            }
                            else if(na==1 && t==0)
                            {
                            sin=1;
                            na=0;
                            
                            t=1;
                            re=0;
                            }
              
     break;
     case SDLK_RETURN:
     if (sin==1)
      {sin=2;     
        SDL_Delay (100);
                }

                if (na==1)
    { na=2;
        SDL_Delay (100);
                   
}

if(re==1)
{re=2;
SDL_Delay(100);
done=0;}

break;



}break;
case SDL_MOUSEMOTION:{
               sin=0;
                na=0;

 Mix_PlayChannel( -1,stone, 0 );           
re=0;
                    
if(event.motion.x >= possin.x && event.motion.x <= (possin.x + 150) && event.motion.y >= possin.y && event.motion.y <= (possin.y + 100))
                {
               sin=1;
                }
 else if            
(event.motion.x >= posno.x && event.motion.x <= (posno.x + 150) && event.motion.y >= posno.y && event.motion.y <= (posno.y + 100))
                {
                    na=1;
                    

                }
                 else if            
(event.motion.x >= posre.x && event.motion.x <= (posre.x + 150) && event.motion.y >= posre.y && event.motion.y <= (posre.y + 100))
                {
                    re=1;
                    

                }
}break;

            case SDL_MOUSEBUTTONDOWN:
                  if (sin==1)
      {sin=2;
                        SDL_Delay (100);
                }

                if (na==1)
    { na=2;
        SDL_Delay (100);
                   
}

if(re==1)
{re=2;
SDL_Delay(100);
done=0;}

                    
break;
}}}
if (done==0)
{menu(screen);
   SDL_FreeSurface(single[0]);
        SDL_FreeSurface(single[1]);
        SDL_FreeSurface(single[2]);
         SDL_FreeSurface(multi[0]);
        SDL_FreeSurface(multi[1]);
        SDL_FreeSurface(multi[2]);
        SDL_FreeSurface(back[2]);
        SDL_FreeSurface(back[0]);
        SDL_FreeSurface(back[1]);

}
}
void commandes(SDL_Surface *screen)
{


    SDL_Surface *background=NULL,*texte1,*texte2,*texte3,*texte4,*texte5,*texte6;
  SDL_Surface *leftclick,*rightclick,*skey,*wkey,*akey,*dkey,*xkey,*ckey,*movement,*action;   
SDL_Rect posrc,poslc,posleft,posright,posdown,posup,pospunch,posweapons,positiona,positionm ;
int r=0;

TTF_Font *police = NULL;
SDL_Rect positiont2,positiont1,positiont3,positiont4,positiont5,positiont6,poslogo,background_pos;
int done=0,i=0;
background_pos.x=0;
background_pos.y=0;
positiont1.x=110;
positiont1.y=200;
posup.y=200;
posup.x=10; 
positiont2.x=110;
positiont2.y=280;
posleft.y=280;
posleft.x=10;
positiont3.x=110;
positiont3.y=360;
posright.y=360;
posright.x=10;
positiont4.x=110;
positiont4.y=420;
posdown.y=420;
posdown.x=10;
positiont5.x=450;
positiont5.y=250;
pospunch.y=200;
pospunch.x=310;
posrc.y=260;
posrc.x=310;
positiont6.x=450;
positiont6.y=400;
posweapons.y=380;
posweapons.x=310;
poslc.y=450;
poslc.x=310;
positiona.y=70;
positiona.x=310;
positionm.y=70;
positionm.x=10;



 SDL_Color couleurNoire ={139,250,0};
 SDL_Color couleurNoire2 ={230,230,250};
 police = TTF_OpenFont("playbuttons/credits/Headlight.ttf",30);
texte1 = TTF_RenderText_Blended(police,"Jump",couleurNoire);
texte2 = TTF_RenderText_Blended(police,"Left ",couleurNoire);
texte3 = TTF_RenderText_Blended(police,"Right",couleurNoire);
texte4 = TTF_RenderText_Blended(police,"Crouch",couleurNoire);
texte5 = TTF_RenderText_Blended(police,"Attack",couleurNoire);
texte6 =TTF_RenderText_Blended(police,"Swap Weapons",couleurNoire);
movement = IMG_Load("playbuttons/commands/movement.png");
action = IMG_Load("playbuttons/commands/action.png");
wkey = IMG_Load("playbuttons/commands/W.png");
skey = IMG_Load("playbuttons/commands/S.png");
akey = IMG_Load("playbuttons/commands/A.png");
dkey = IMG_Load("playbuttons/commands/D.png");
xkey = IMG_Load("playbuttons/commands/X.png");
ckey = IMG_Load("playbuttons/commands/C.png");
rightclick = IMG_Load("playbuttons/commands/RC.png");
leftclick = IMG_Load("playbuttons/commands/LC.png");
background =IMG_Load("tabumba 2.1.png");



while(done==0)
{


SDL_BlitSurface(background,NULL,screen,&background_pos);
 

SDL_BlitSurface(texte1,NULL,screen,&positiont1);
SDL_BlitSurface(texte2,NULL,screen,&positiont2);
SDL_BlitSurface(texte3,NULL,screen,&positiont3);
SDL_BlitSurface(texte4,NULL,screen,&positiont4);
SDL_BlitSurface(texte5,NULL,screen,&positiont5);
SDL_BlitSurface(texte6,NULL,screen,&positiont6);
SDL_BlitSurface(action,NULL,screen,&positiona);
SDL_BlitSurface(movement,NULL,screen,&positionm);

SDL_BlitSurface(leftclick,NULL,screen,&poslc);

SDL_BlitSurface(rightclick,NULL,screen,&posrc);

SDL_BlitSurface(skey,NULL,screen,&posdown);

SDL_BlitSurface(wkey,NULL,screen,&posup);

SDL_BlitSurface(akey,NULL,screen,&posleft);

SDL_BlitSurface(dkey,NULL,screen,&posright);

SDL_BlitSurface(xkey,NULL,screen,&pospunch);

SDL_BlitSurface(ckey,NULL,screen,&posweapons);

done=back(screen,2);
SDL_Flip(screen);}
}






