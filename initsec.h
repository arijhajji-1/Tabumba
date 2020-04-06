typedef struct 
{
SDL_Surface *image ; 
SDL_Rect positionAnimation ; 
SDL_Rect positionAbsolute;
int direction;
int moving;
int health;
} character ; 
void inisialiser_character (character *t, int x ,int y);
void afficher_character (character *t,SDL_Surface *screen,SDL_Rect pos);
void animation (character *t);

