/*
 * Author : Harry
 * Date : 22/09/2017
*/

#include <stdio.h>
#include <stdlib.h>

// ex17
typedef struct MATRICE33
{
	float mat[3][3];
}matrice33, *p_matrice33;

// ex18
typedef struct MATRICE_CARREE
{
	int rows, cols;
	float **data;
}matrice_carree, *p_matrice_carree;

void affiche_matrice(matrice33 mat);
void affiche_matrice_carree(matrice_carree mat);
void mul_matrice33(matrice33 mat1, matrice33 mat2, matrice33 *res);
matrice_carree *creer_matrice_nulle(int rows, int cols);
void supprimer_matrice_carree(matrice_carree *suppr);

int main()
{
	//ex17
	matrice33 m1, m2, m3_res;
	
	// m1
	m1.mat[0][0]=5.0;
	m1.mat[0][1]=5.0;
	m1.mat[0][2]=5.0;
	
	m1.mat[1][0]=5.0;
	m1.mat[1][1]=5.0;
	m1.mat[1][2]=5.0;
	
	m1.mat[2][0]=5.0;
	m1.mat[2][1]=5.0;
	m1.mat[2][2]=5.0;
	
	// m2
	m2.mat[0][0]=5.0;
	m2.mat[0][1]=5.0;
	m2.mat[0][2]=5.0;
	
	m2.mat[1][0]=5.0;
	m2.mat[1][1]=5.0;
	m2.mat[1][2]=5.0;
	
	m2.mat[2][0]=5.0;
	m2.mat[2][1]=5.0;
	m2.mat[2][2]=5.0;
	
	mul_matrice33(m1, m2, &m3_res);
	
	affiche_matrice(m3_res);
	
	// ex18 & ex19
	matrice_carree *mc1=creer_matrice_nulle(3, 4);
	affiche_matrice_carree(*mc1);\
	
	// ex20
	supprimer_matrice_carree(mc1);
	
	// partie_5.c
	
	return 0;
}

void affiche_matrice(matrice33 mat)
{
	int i=0, j=0;
	
	for( i=0; i<3; ++i )
	{
		printf("[");
		for( j=0; j<3; ++j )
		{
			printf(" %.2f ", mat.mat[i][j]);
		}
		printf("]");
		printf("\n");
	}
}

// ex17
void mul_matrice33(matrice33 mat1, matrice33 mat2, matrice33 *res)
{
	int i=0, j=0, k=0;
	float sum=0.0;
	
	for( i=0; i<3; ++i )
	{
		for( j=0; j<3; ++j )
		{
			sum=0.0;
			for( k=0; k<3; ++k )
			{
				sum+=mat1.mat[i][k]*mat2.mat[k][j];
			}
			(*res).mat[i][j]=sum;
		}
	}
}

void affiche_matrice_carree(matrice_carree mat)
{
	int i=0, j=0;
	
	for( i=0; i<mat.rows; ++i )
	{
		printf("[");
		for( j=0; j<mat.cols; ++j )
		{
			printf(" %.2f ", mat.data[i][j]);
		}
		printf("]");
		printf("\n");
	}
}

// ex18
matrice_carree *creer_matrice_nulle(int rows, int cols)
{
	matrice_carree *ret=(matrice_carree*)malloc(sizeof(matrice_carree));
	ret->rows=rows;
	ret->cols=cols;
	ret->data=(float**)malloc(sizeof(float*)*ret->rows);
	
	int i=0, j=0;
	
	for( i=0; i<ret->rows; ++i )
	{
		ret->data[i]=(float*)malloc(sizeof(float)*ret->cols);
	}
	
	for( i=0; i<ret->rows; ++i )
	{
		for( j=0; j<ret->cols; ++j )
		{
			ret->data[i][j]=0;
		}
	}
	
	return ret;
}

// ex20
void supprimer_matrice_carree(matrice_carree *suppr)
{
	int i=0;
	
	for( i=0; i<suppr->rows; ++i )
	{
		if( suppr->data[i]!=NULL )
		{
			free(suppr->data[i]);
		}
	}
	
	if( suppr->data!=NULL )
	{
		free(suppr->data);
	}
	
	if( suppr!=NULL )
	{
		free(suppr);
	}
}

