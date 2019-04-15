#ifndef H_GL_GRAPH
#define H_GL_GRAPH

#define KEY_PRESSED  0x00000004
#define DARK_BLUE 0x061229
void debug(char matrix[6][7], int row);
int calcule_cote(int w,int h,int nbc,int nbl);
void affiche_grille(char matrix[6][7],int row,int col,int c,int margin);
#endif
