#include <stdio.h>
#include <math.h>
#include "graphics.h"
#include "grille.h"
#define dark_blue 0x061229
void debug(char grille[NBL][NBC+1], int row){

int i;

for (i=0;i<row;i++){
	printf("%s\n",grille[i]);
	}
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
	return c2;
	}
	return c1;
}

void affiche_grille(char grille[NBL][NBC+1],int row,int col,int c,int margin){
/*--Var Init--*/
int j,k;
char *text="r: Refresh | q: Quit";
/*--Debug Help--*/
printf("%d\n",c);
printf("%d\n",margin);
/*--Drawing tiles--*/
for (j = 0; j < row; j++)
{
	for (k = 0; k < col; k++)
	{
		/*printf("%d\n",matrix[j][k]);*/
		if ( grille[j][k] == 98 ){
				/*gr_set_color(white);
        		gr_fill_rect(j*c+margin, k*c+FOOTER, c, c);*/
		}
		else{
			gr_set_color(black);
			gr_fill_rect(j*c+margin, k*c+FOOTER, c, c);
   		}

	}
}

/*--Drawing grid--*/
/*gr_set_color(white);
gr_set_line_width(1);
for (j = 0; j < row; j++){
	gr_moveto(j*c,k);
	gr_lineto((500-j*c),(k));
	gr_moveto(j*c+margin,0);
	gr_lineto(j*c+margin,c*row+FOOTER);
}
for (j = 0; j < row; j++){
        gr_moveto(j*c,k);
        gr_lineto((500-j*c),(k));
        gr_moveto(margin,j*c+FOOTER);
        gr_lineto(c*row+margin,c*j+FOOTER);
}*/
/*--Drawing footer--*/

}

void draw_footer(){
	char *text="r: Refresh | q: Quit";
gr_moveto(0,0);
gr_set_color(dark_blue);
gr_fill_rect(0,0,gr_size_x(),FOOTER);
gr_set_color(white);
gr_draw_string(text);
}