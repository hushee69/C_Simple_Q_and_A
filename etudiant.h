#ifndef _ETUDIANT_H
#define _ETUDIANT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_NAME_LEN			3
#define MAX_NAME_LEN			10
#define MIN_ID				10000
#define MAX_NOTE			20.0
#define NUM_ALPHABETS		26

// ex28 & 33
typedef struct ETUDIANT
{
	char *name;
	unsigned long id;
	float note;
}etudiant, *p_etudiant;

void affiche_etudiant(etudiant et);
etudiant *creer_etudiant();
void creer_etudiant_no_return(etudiant *et);
char rot(char, int);
void creer_classe(int n);
char *generer_nom();
void free_etudiant(etudiant *e);
char rot_back(char c, int shift);

#endif
