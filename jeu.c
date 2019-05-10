#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "grille.h"
#include <graphics.h>
#include <getopt.h>
#include <time.h>
#include <unistd.h>
#define WIN " 500x530"
#define FOOTER 30
int  wait_char(int * c){
	char read;
	do {
		read=gr_read_key();
	}
	while (read != 's');
	*c = 1;
	return 0;	
}
int main(int argc, char* argv[])
{
	int c,margin;
	int next_option;
	double total_time;
	clock_t start, end;
	XInitThreads();
	const char* const short_options ="h";
	const struct option long_options[] = {
	{"help", 0, NULL, 'h' },
	{ NULL, 0, NULL, 0}
	};
	char read,read2;
	int wh[2];

    	char grille[NBL][NBC+1] = {
  "bbbbbbbbbbbbbbbbbbbbbbbbnbbbbbbbbbbb",
  "bbbbbbbbbbbbbbbbbbbbbbnbnbbbbbbbbbbb",
  "bbbbbbbbbbbbnnbbbbbbnnbbbbbbbbbbbbnn",
  "bbbbbbbbbbbnbbbnbbbbnnbbbbbbbbbbbbnn",
  "nnbbbbbbbbnbbbbbnbbbnnbbbbbbbbbbbbbb",
  "nnbbbbbbbbnbbbnbnnbbbbnbnbbbbbbbbbbb",
  "bbbbbbbbbbnbbbbbnbbbbbbbnbbbbbbbbbbb",
  "bbbbbbbbbbbnbbbnbbbbbbbbbbbbbbbbbbbb",
  "bbbbbbbbbbbbnnbbbbbbbbbbbbbbbbbbbbbb",
  "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
  "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
  "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
  "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
  "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
  "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
  "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
  "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
  "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
  "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
  "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
  "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
  "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
  };
    	do {
	next_option = getopt_long(argc,argv, short_options, long_options,NULL);

		switch(next_option)
			{
			case 'h':
			printf("help\n\n");
			case -1:
			break;
			case '?':
			printf("bro t'a merdé\n");
			default:
			abort();
			}
		}
	while (next_option != -1);
	gr_open_graph(WIN);
	wh[0]=500;
	wh[1]=500;
	debug(grille,NBC);
	/*printf("%c\n",grille[0][6]);
	printf("%c\n",grille[5][5]);*/
	c=calcule_cote(wh[0],wh[1],NBC,NBL);
	margin=calcule_margin(wh[0],c);
	affiche_grille(grille,NBL,NBC,c,margin);
	do {
	read=gr_read_key();
	/*printf("%c\n",read);*/
	if ( read == 'n'){
		applique(grille);
		wh[0]=gr_size_x();
		wh[1]=gr_size_y();
		c=calcule_cote(wh[0],wh[1],NBC,NBL);
		margin=calcule_margin(wh[0],c);
		gr_clear_graph();
	    affiche_grille(grille,NBL,NBC,c,margin);
		}

	if ( read == 's'){
		pthread_t thread;
		int s=0;
		if(pthread_create(&thread, NULL, wait_char, &s)) {

		fprintf(stderr, "Error creating thread\n");
		return 1;

		}
		while (s == 0){
		start = clock();	
		applique(grille);
		wh[0]=gr_size_x();
		wh[1]=gr_size_y();
		c=calcule_cote(wh[0],wh[1],NBC,NBL);
		margin=calcule_margin(wh[0],c);
		usleep(80000);
		gr_clear_graph();
	    affiche_grille(grille,NBL,NBC,c,margin);
	    end = clock();
	    total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	    printf("\nTook %fs to render\n", total_time);
		}		

	}

	if ( read == 'r') {
		wh[0]=gr_size_x();
		wh[1]=gr_size_y();
		c=calcule_cote(wh[0],wh[1],NBC,NBL);
		margin=calcule_margin(wh[0],c);
		gr_clear_graph();
	    affiche_grille(grille,NBL,NBC,c,margin);
		}
	} while ( read != 'q' );
	return 0;
}
