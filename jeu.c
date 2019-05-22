#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "grille.h"
#include <string.h>
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
	while (read != 'p');
	*c = 1;
	return 0;	
}

int main(int argc, char* argv[])
{
	int c,margin;
	int out_flag;
	int in_flag;
	int n_flag;
	int ntimes;
	char * input_file_name;
	char output_file_name[150];
	int nb_it;
	int i,j;
	int len;
	int next_option;
	double total_time;
	clock_t start, end;
	XInitThreads();
	const char* const short_options ="i:o:n:h:";
	const struct option long_options[] = {
	{"help", 0, NULL, 'h' },
	{"input", 1, NULL, 'i' },
	{"output", 1, NULL, 'o' },
	{"ntimes", 1, NULL, 'n' },
	{ NULL, 0, NULL, 0}
	};
	char read,read2;
	int wh[2];
	char **grille,**grille2;
	char *ptr;
    	do {
	next_option = getopt_long(argc,argv, short_options, long_options,NULL);

		switch(next_option)
			{
			case 'i' :
			if (check_file(optarg) == 1){
				FILE *file;
				int i,line_size,j,k;
				printf("input file : %s exist\n",optarg);
				file = fopen(optarg, "r");
				char* line[150];
				fgets(line,150,file);
				NBC=strlen(line);
				fclose(file);
				NBL=count_lines(optarg);
				printf("%d,%d",NBL,NBC);
				printf("a\n");
				file = fopen(optarg, "r");
				char * line_final;
				printf("aze\n");
				line_final=(char *)malloc(sizeof(char)*NBC+1);
				len = sizeof(char*) * NBL + sizeof(char) * NBC * NBL; 
    			grille = (char **)malloc(len);
    			ptr = (char *)(grille + NBL);
    			for(i = 0; i < NBL; i++) 
    			grille[i] = (ptr + NBC * i);
    			grille2 = (char **)malloc(len);
				ptr = (char *)(grille2 + NBL);
				for(i = 0; i < NBL; i++) 
    			grille2[i] = (ptr + NBC * i);
    			

    			printf("azeaze\n");
				
				for (i = 0; i < NBL; ++i)
				{
					for (j = 0; j < NBC; j++) 
						grille[i][j] = fgetc(file);
					}
				}
					
			else{
				printf("input file : %s doesn't exists",optarg);
			}
			in_flag=1;
			break;
			case 'o' :
			if (check_file(optarg) == 1){
				printf("output file exists");
				strcpy(output_file_name,optarg);
				out_flag=1;
			}
			break;
			case 'n' :
			ntimes=atoi(optarg);
			n_flag=1;
			break;
			case 'h' :
			printf("help\n\n");
			break;

			case -1 :
			break;

			case '?' :
			printf("bro t'a merdé\n");
			default:
			abort();
			}
		}
	while (next_option != -1);
	if (in_flag != 1){
			NBL=2;
			NBC=3;
			len = sizeof(char*) * NBL + sizeof(char) * NBC * NBL;
			ptr = (char *)(grille + NBL);
			grille = (char **)malloc(len);
    		for(i = 0; i < NBL; i++) 
    		grille[i] = (ptr + NBC * i);
    		grille2 = (char **)malloc(len);
			ptr = (char *)(grille2 + NBL);
			for(i = 0; i < NBL; i++) 
    		grille2[i] = (ptr + NBC * i);
    		for (i = 0; i < NBL; ++i)
				{
					for (j = 0; j < NBC; j++) {
						grille[i][j] = 'n';
					
					}
				}
	}
	gr_open_graph(WIN);
	wh[0]=500;
	wh[1]=500;
	debug(grille,NBL,NBC);
	c=calcule_cote(wh[0],wh[1],NBC,NBL);
	printf("%d",c);
	margin=calcule_margin(wh[0],c);
	affiche_grille(grille,NBL,NBC,c,margin);
	if (n_flag == 1){
		if ( out_flag == 0){
			printf("Output file option isn't present");
			exit(1);
		}
		printf("%d",ntimes);
		for (i=0; i < ntimes; i++){
			applique(grille,grille2);
			printf("%d",i);
		}
	save_to_file(output_file_name,grille);
	exit(0);
	}
	do {
	read=gr_read_key();
	if ( read == 'n'){
		applique(grille,grille2);
		wh[0]=gr_size_x();
		wh[1]=gr_size_y();
		c=calcule_cote(wh[0],wh[1],NBC,NBL);
		margin=calcule_margin(wh[0],c);
		gr_clear_graph();
	    affiche_grille(grille,NBL,NBC,c,margin);
		}
	if ( read == 'p'){
		pthread_t thread;
		int s=0;
		if(pthread_create(&thread, NULL, wait_char, &s)) {

		fprintf(stderr, "Error creating thread\n");
		return 1;

		}
		while (s == 0){
		start = clock();	
		applique(grille,grille);
		wh[0]=gr_size_x();
		wh[1]=gr_size_y();
		c=calcule_cote(wh[0],wh[1],NBC,NBL);
		margin=calcule_margin(wh[0],c);
		gr_clear_graph();
	    affiche_grille(grille,NBL,NBC,c,margin);
	    end = clock();
	    total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	    printf("\nTook %fs to render\n", total_time);
	    usleep(1500000);
		}		

	}

	if ( read == 's') {
		save_to_file(output_file_name,grille);
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
	if (out_flag=1){
		save_to_file(output_file_name,grille);
	}
	return 0;
}
