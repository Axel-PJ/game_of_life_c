#ifndef H_GL_GRAPH
#define H_GL_GRAPH
int NBL;
int NBC;
#define BLANC ' '
#define NOIR 'n'
#define FOOTER 30
void debug(char **grille, int row,int col);
void print_help();
int calcule_cote(int w,int h,int nbc,int nbl);
void affiche_grille(char **grille,int row,int col,int c,int margin);
void applique(char **grille, char **grille2);
int calcule_margin(int w,int c);
void copie_grille(char **grille, char **grille2);
int compte_voisin(char **grille,int i,int j);
#endif
