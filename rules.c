#include <stdio.h>
#include <math.h>
#include "graphics.h"
#include "grille.h"
void applique(char grille[NBL][NBC+1]){
int j,k,nb;
char grille2[NBL][NBC+1];
copie_grille(grille,grille2);
	for (j = 0; j < NBL; j++)
	{
		for (k = 0; k < NBC; k++)
		{
			/*printf("cellule [%d,%d]a %d voisins\n",j,k,compte_voisin(grille2,j,k));*/
   			nb=compte_voisin(grille2,j,k);
   			switch (nb){
			case 3 :
			grille[j][k]='n';
			break;
			case 2 :
			break;
			default:
			grille[j][k]='b';
			break;
			}

		}
	}
}

void copie_grille(char grille[NBL][NBC+1], char grille2[NBL][NBC+1]){
int j,k;
for (j = 0; j < NBL; j++)
{
	for (k = 0; k < NBC; k++)
	{
		grille2[j][k] = grille[j][k];

	}
}
}

int compte_voisin(char grille2[NBL][NBC+1],int j,int k){
	int voisins=0;
   		
		if (grille2[j-1][k-1] == 'n'){
			voisins++;
		}

		if (grille2[j-1][k] == 'n'){
			voisins++;
		}

		if (grille2[j-1][k+1] == 'n'){
			voisins++;
		}

		if (grille2[j][k-1] == 'n'){
			voisins++;
		}

		if (grille2[j][k+1] == 'n'){
			voisins++;
		}

		if (grille2[j+1][k-1] == 'n'){
			voisins++;
		}

		if (grille2[j+1][k] == 'n'){
			voisins++;
		}

		if (grille2[j+1][k+1] == 'n'){
			voisins++;
		}
	
return voisins;
}