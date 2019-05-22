#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <graphics.h>
#include <getopt.h>
#include <time.h>
#include "grille.h"
#include <unistd.h>

int check_file(char * filename){
	FILE *file;
    if (file = fopen(filename, "r")){
        fclose(file);
        return 1;
    }
    return 0;
}

int count_lines(char *filename)
{
  /* count the number of lines in the file called filename   */                                 
 FILE *file;
 char c;
 int count;
    if (file = fopen(filename, "r")){
       for (c = getc(file); c != EOF; c = getc(file)) 
        if (c == '\n') 
            count = count + 1; 
  

    fclose(file); 
    printf("The file %s has %d lines\n ", filename, count); 
  
    return count; 
	}
}

int save_to_file(char *filename, char **grille){
FILE *f = fopen(filename, "w");
int i,j;
char str[NBC+1];
for (i=0; i < NBL; i++){
    for (j=0; j < NBC; j++){
    fputc(grille[i][j],f);
    }
}
fclose(f);
}