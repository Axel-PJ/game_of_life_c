#ifndef H_GL_GRAPH
#define H_GL_GRAPH

#define KEY_PRESSED  0x00000004

void debug(char matrix[6][7], int row);
int calcul_cote(int w,int h,int nbc,int nbl);
void affiche_grille(char matrix[6][7],int row,int col,int c,int margin);
int check_size(void);
#endif
