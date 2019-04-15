#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <unistd.h>
#include <pthread.h>
#define WIN " 500x500"
int main(void)
{
	int c,margin,w,h,nbc,nbl;
	int wh[2];
	pthread_t thread_id;
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
	printf("grille = %x\n",&grille);
	debug(&grille,6);
	/*printf("%c\n",grille[0][6]);
	printf("%c\n",grille[5][5]);*/
	c=calcule_cote(wh[0],wh[1],nbc,nbl);
	margin=(wh[0]-c*6)/2;
	affiche_grille(&grille,6,6,c,margin);
thread:
	pthread_create(&thread_id, NULL, check_size, &wh);
	if(!pthread_join(thread_id, NULL)) {
	wh[0]=gr_size_x();
        wh[1]=gr_size_y();
	c=calcule_cote(wh[0],wh[1],nbc,nbl);
        margin=(wh[0]-c*6)/2;
	gr_clear_graph();
        affiche_grille(&grille,6,6,c,margin);
}
	goto thread;
	/*(void) gr_wait_event(KEY_PRESSED);*/
return 0;
}
