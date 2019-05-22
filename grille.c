#include <stdio.h>
#include <math.h>
#include "graphics.h"
#include "grille.h"
#define dark_blue 0x061229
void debug(char **grille, int row, int col){
int i,j;
for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%c", grille[i][j]); 
    }
    printf("\n");
}
/*for (i=0;i<row;i++){
	for (j=0;j<3;j++){
	printf("%c\n",((grille+i)+j));
		}
	}*/
}

void print_help(){

	/* TBA */
}
int calcule_margin(int w,int c){
	if (NBC > NBL){
		return (w-c*NBL)/2;
	}
	else{
		return (w-c*NBC)/2;
	}
}
int calcule_cote(int w,int h,int nbc,int nbl){
int c1,c2;
c1=w/nbc;
c2=h/nbl;
	if (c1 > c2){
		printf("coté = %d\n",c2);
	return c2;
	}
	return c1;
		printf("coté = %d\n",c1);
}

void affiche_grille(char **grille,int row,int col,int c,int margin){
/*--Var Init--*/
int j,k;
/*char *text="r: Refresh | q: Quit";*/
/*--Debug Help--*/
/*printf("%d\n",c);
printf("%d\n",margin);
--Drawing tiles--*/
for (j = 0; j < row; j++)
{
	for (k = 0; k < col-1; k++)
	{
		/*printf("%d\n",matrix[j][k]);*/
		if ( grille[j][k] == BLANC ){
				
		}
		else{
				gr_set_color(black);
				gr_fill_rect(j*c+margin, k*c+FOOTER, c, c);
   		}

	}
}
}

void default_grille(char **grille, char **grille2){
			int len;
			char *ptr;
			int i,j;
}


void draw_footer(){
	char *text="r: Refresh | q: Quit";
gr_moveto(0,0);
gr_set_color(dark_blue);
gr_fill_rect(0,0,gr_size_x(),FOOTER);
gr_set_color(white);
gr_draw_string(text);
}