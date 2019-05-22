#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "graphics.h"
#include "grille.h"
void applique(char **grille, char **grille2){
int i,j,k,nb;
copie_grille(grille,grille2);
printf("%c", grille2[0][0]);
	for (j = 0; j < NBL; j++)
	{
		for (k = 0; k < NBC-1; k++)
		{
			printf("cellule [%d,%d]a %d voisins\n",j,k,compte_voisin(grille2,j,k));
   			nb=compte_voisin(grille2,j,k);
   			switch (nb){
			case 3 :
			grille[j][k]=NOIR;
			break;
			case 2 :
			break;
			default:
			grille[j][k]=BLANC;
			break;
			}

		}
	}
}

void copie_grille(char **grille, char **grille2){
int j,k;
for (j = 0; j < NBL; j++)
{
	for (k = 0; k < NBC; k++)
	{
		grille2[j][k] = grille[j][k];
	}
}
}

int compte_voisin(char **grille2,int j,int k){
	int voisins=0;
	printf("%c", grille2[j][k]);
    
   		if (j-1 >= 0 && k-1 >= 0){
		if (grille2[j-1][k-1] == 'n'){
			voisins++;
		}}

		if (j-1 >= 0){
		if (grille2[j-1][k] == 'n'){
			voisins++;
		}}

		if (j-1 >= 0 && k+1 <= NBC){
		if (grille2[j-1][k+1] == 'n'){
			voisins++;
		}}

		if (k-1 >= 0){
		if (grille2[j][k-1] == 'n'){
			voisins++;
		}}

		if ( k+1 <= NBC){
		if (grille2[j][k+1] == 'n'){
			voisins++;
		}}

		if (j < NBL-1 && k-1 >= 0){
		if (grille2[j+1][k-1] == 'n'){
			voisins++;
		}}

		if (j < NBL-1){
		if (grille2[j+1][k] == 'n'){
			voisins++;
		}}

		if (j < NBL-1 && k+1 <= NBC){
		if (grille2[j+1][k+1] == 'n'){
			voisins++;
		}}
	
return voisins;
}