typedef struct character
	{

	SDL_Surface *character;
	SDL_Rect rect;
	SDL_Rect rects[];
	int direction;
	}character;
void inisialiser_character (character *t);
void afficher_character (character *t,SDL_Surface *screen,SDL_Rect pos);
void animation (character *t);
void update_character(character *t ,SDL_Surface *screen);
