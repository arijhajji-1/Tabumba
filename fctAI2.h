#ifndef FCT_H_INCLUDED
#define FCT_H_INCLUDED

typedef struct 
{
int nb_de_fois;
SDL_Surface *image; 
}joueur;

typedef struct 
{
int nb_de_fois;
SDL_Surface *image;
}ordinateur;

typedef struct 
{
	SDL_Rect pos;
	int cas;
}ctableau;
int main();
void afficher_background(SDL_Surface *screen);
ctableau initialisation_tab(int i,int j);
joueur initialisation_xjoueur();
ordinateur initialisation_ojoueur();
joueur joueurX(joueur player,ctableau Tab[3][3],SDL_Surface *screen);
ordinateur ordinateurO(ordinateur player,ctableau Tab[3][3],SDL_Surface *screen);
int fin_jeu(joueur playerx,ordinateur playero,ctableau Tab[3][3],SDL_Surface *screen);
#endif
