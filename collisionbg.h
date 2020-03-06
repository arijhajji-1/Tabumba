SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y);
void update_collision(personnage* perso);
void dep(SDL_Rect *pos,SDL_Surface *perso,SDL_Surface *ecran);
int collision_player_map(SDL_Surface *ecran , personnage* perso);
