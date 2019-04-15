#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
#include <graphics.h>
#include <unistd.h>
#define WIN " 500x530"
#define FOOTER 30
int main(void)
{
	int c,margin,nbc,nbl;
	char read;
	int wh[2];
    	char grille[6][7] = {
        "bbbbbb",
        "bbbbbb",
        "bbnnbb",
        "bbnnbb",
        "bbbbbb",
        "bbbbbb"
    };
	gr_open_graph(WIN);
        nbc=6;
        nbl=6;
	wh[0]=500;
	wh[1]=500;
	debug(grille,6);
	/*printf("%c\n",grille[0][6]);
	printf("%c\n",grille[5][5]);*/
	c=calcule_cote(wh[0],wh[1],nbc,nbl);
	margin=(wh[0]-c*6)/2;
	affiche_grille(grille,6,6,c,margin);
	do {
	read=gr_read_key();
	printf("%c\n",read);
	if ( read == 'r') {
		wh[0]=gr_size_x();
		wh[1]=gr_size_y();
		c=calcule_cote(wh[0],wh[1],nbc,nbl);
		margin=(wh[0]-c*6)/2;
		gr_clear_graph();
	        affiche_grille(grille,6,6,c,margin);
		}
	} while ( read != 'q' );
	return 0;
}
