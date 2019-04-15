#include <stdio.h>
#include <math.h>
#include "graphics.h"

void debug(char matrix[6][7], int row){

int i;

for (i=0;i<row;i++){
	printf("%s\n",matrix[i]);
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

void affiche_grille(char matrix[6][7],int row,int col,int c,int margin){
int j,k;
printf("%d\n",c);
printf("%d\n",margin);
for (j = 0; j < row; j++)
{
	for (k = 0; k < col; k++)
	{
		/*printf("%d\n",matrix[j][k]);*/
		if ( matrix[j][k] == 98 ){
			gr_set_color(yellow);
        		gr_fill_rect(j*c+margin, k*c, c, c);
		}
		else
			gr_set_color(blue);
			gr_fill_rect(j*c+margin, k*c, c, c);
   		}

	}
}

int check_size(int wh[3]){
int i;
int whnew[2];
for(i = 0; i < 2; i++) {
      whnew[i] = wh[i];
   }
int c,margin,gr_w,gr_h;
while (1){
	gr_w=gr_size_x();
	gr_h=gr_size_y();
	if ( gr_w != whnew[0] | gr_h != whnew[1]){
		/*c=calcule_cote(gr_w,gr_h,6,6);
		margin=(gr_w-c*6)/2;
		printf("%x\n",wh[2]);
		whnew[0]=gr_w;
		whnew[1]=gr_h;*/
		return 0;
	}
/*printf("%d---%d\n",whnew[0],whnew[1]);*/
}
}
