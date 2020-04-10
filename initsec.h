typedef struct Enemy
{
  SDL_Surface *image[3];
  SDL_Surface *image2[3];
  SDL_Surface *Hit;
  SDL_Surface *imageActuel;
  SDL_Rect position;
  SDL_Rect positionO;
  int frame;
  int direction;
  int died;

}Enemy; 
void inisialiser_character (Enemy *t, int x ,int y);
void afficher_character (Enemy *t,SDL_Surface *screen,SDL_Rect pos);
void animation (Enemy *t);

