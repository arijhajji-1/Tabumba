#ifndef FIN_JEU_H_INCLUDED
#define FIN_JEU_H_INCLUDED
void main();
int fin_jeu(int enigem,int vie);
void gagne_jeu(SDL_Surface *screen,int point,int time,int nbvie);
void perdu_jeu(SDL_Surface *screen,int point,int time,int nbvie);
#endif