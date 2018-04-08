/*
 * Author : Harry
 * Date : 22/09/2017
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct LISTE_CHAINEE_INT
{
	int data;
	struct LISTE_CHAINEE_INT *next;
}liste_chainee_int, *p_liste_chainee_int;

void ajouter_element(liste_chainee_int **liste, int elem);
void afficher_liste(liste_chainee_int *l);
void tableau_vers_liste(int tab[], int tab_len, liste_chainee_int **out_list);
int *chercher(liste_chainee_int *l, int needle);
void affiche_tableau(int *tab, int tab_len);
void tableau_au_carre(int *tab, int tab_len);
void affiche_taille();
void free_liste(liste_chainee_int *list);

int main()
{
	// ex21 - 23
	liste_chainee_int *list=NULL;
	
	ajouter_element(&list, 5);
	ajouter_element(&list, 19);
	
	afficher_liste(list);
	
	// ex24
	liste_chainee_int *from_tab=NULL;
	int tab[]={3, 14, 16, 8, 12};
	
	printf("tableau vers liste\n");
	tableau_vers_liste(tab, 5, &from_tab);
	
	afficher_liste(from_tab);
	
	// ex25
	printf("address de valeur %d=%p\n", 16, chercher(from_tab, 16));
	
	// ex26
	printf("valeurs de tableau au carree\n");
	printf("avant\n");
	
	affiche_tableau(tab, 5);
	
	printf("apres\n");
	
	tableau_au_carre(tab, 5);
	affiche_tableau(tab, 5);
	
	// ex27
	affiche_taille();
	
	free_liste(list);
	free_liste(from_tab);

	// etudiant_main.c
	
	return 0;
}

// ex21
void ajouter_element(liste_chainee_int **liste, int elem)
{
	liste_chainee_int *new_list=(liste_chainee_int*)malloc(sizeof(liste_chainee_int));
	new_list->data=elem;
	new_list->next=NULL;
	
	if( *liste==NULL )
	{
		*liste=new_list;
		
		return;
	}
	
	liste_chainee_int *cur=*liste;
	while( cur->next!=NULL )
	{
		cur=cur->next;
	}
	cur->next=new_list;
}

void afficher_liste(liste_chainee_int *l)
{
	while( l!=NULL )
	{
		printf("data=%d\n", l->data);
		l=l->next;
	}
	
	return;
}

// ex22
void free_liste(liste_chainee_int *liste)
{
	if( liste!=NULL )
	{
		free(liste);
	}
}

// ex24
void tableau_vers_liste(int *tab, int tab_len, liste_chainee_int **out_list)
{
	int i=0;
	
	for( i=0; i<tab_len; ++i )
	{
		ajouter_element(out_list, tab[i]);
	}
}

// ex25
int *chercher(liste_chainee_int *l, int needle)
{
	int *address=NULL;
	
	while( l!=NULL )
	{
		if( l->data==needle )
		{
			address=&needle;
			
			return address;
		}
		l=l->next;
	}
	
	return address;
}

void affiche_tableau(int *tab, int tab_len)
{
	int i=0;
	
	printf("[");
	for( i=0; i<tab_len; ++i )
	{
		printf("%d, ", tab[i]);
	}
	printf("]\n");
	
	return;
}

// ex26
void tableau_au_carre(int *tab, int tab_len)
{
	int i=0;
	
	for( i=0; i<tab_len; ++i )
	{
		tab[i]*=tab[i];
	}
}

// ex27
void affiche_taille()
{
	printf("sizeof char=%d\nsizeof short=%d\nsizeof int=%d\nsizeof long=%d\nsizeof float=%d\nsizeof double=%d\n", sizeof(char), sizeof(short), sizeof(int), sizeof(long), sizeof(float), sizeof(double));
	
	return;
}

