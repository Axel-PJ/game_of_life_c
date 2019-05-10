#ifndef H_GL_GRAPH
#define H_GL_GRAPH
#define NBL 22
#define NBC 36
#define FOOTER 30
#define KEY_PRESSED  0x00000004
#define DARK_BLUE 0x061229
void debug(char grille[NBL][NBC+1], int row);
void print_help();
int calcule_cote(int w,int h,int nbc,int nbl);
void affiche_grille(char grille[NBL][NBC+1],int row,int col,int c,int margin);
void applique(char grille[NBL][NBC+1]);
int calcule_margin(int w,int c);
void copie_grille(char grille[NBL][NBC+1], char grille2[NBL][NBC+1]);
int compte_voisin(char grille[NBL][NBC+1],int i,int j);
#endif
