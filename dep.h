typedef struct
{SDL_Rect poshero;
int direction;
SDL_surface *image;
score scorehero;
vie viehero;
}luan,aaron;
void inithero();
int deplacement_souris(event event,*image,*ecran) ;
int deplacement_clavier(event event,*image,*ecran);
