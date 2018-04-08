#include "etudiant.h"

// ex29 & 30
void affiche_etudiant(etudiant et)
{
	printf("nom : %s\n", et.name);
	printf("identite : %ld\n", et.id);
	printf("note : %.2f\n", et.note);
	
	return;
}

etudiant *creer_etudiant()
{
	etudiant *ret=(etudiant*)malloc(sizeof(etudiant));
	
	ret->name=generer_nom();
	ret->id=(rand()%RAND_MAX)+MIN_ID;
	ret->note=((float)rand()/(float)RAND_MAX)*MAX_NOTE;
	
	return ret;
}

void creer_etudiant_no_return(etudiant *et)
{
	et->name=generer_nom();
	et->id=(rand()%RAND_MAX)+MIN_ID;
	et->note=((float)rand()/(float)RAND_MAX)*MAX_NOTE;
	
	return;
}

// ex32
char rot(char c, int shift)
{
	int res=(int)c+shift;
	char ret=(char)res;
	if( res>122 )
	{
		int reduce=res-122;
		ret=(char)(122-(NUM_ALPHABETS-reduce));
	}
	
	return ret;
}

// ex35
void creer_classe(int n)
{
	int i=0;
	etudiant *ets=(etudiant*)malloc(sizeof(etudiant)*n);
	memset(ets, 0, sizeof(ets));
	
	for( i=0; i<n; ++i )
	{
		creer_etudiant_no_return(&ets[i]);
	}
	
	for( i=0; i<n; ++i )
	{
		printf("\tetudiant numero %d\n", i+1);
		affiche_etudiant(ets[i]);
		printf("\n");
	}
	
	for( i=0; i<n; ++i )
	{
		free(ets[i].name);
	}
	
	free(ets);
	
	return;
}

// ex36
char *generer_nom()
{
	#define ASCII_START				97
	#define ASCII_END				122
	
	int len=(rand()%MAX_NAME_LEN)+MIN_NAME_LEN;
	char *nom=(char*)malloc(sizeof(char)*(len+1));
	int i=0, bytes_written=0;
	
	for( i=0, bytes_written=0; i<len; ++i, ++bytes_written )
	{
		int rand_val=(rand()%(ASCII_END-ASCII_START)+ASCII_START);
		char c=(char)rand_val;
		
		nom[bytes_written]=c;
	}
	nom[bytes_written]='\0';
	
	return nom;
}

// ex38
void free_etudiant(etudiant *e)
{
	if( e!=NULL )
	{
		if( e->name!=NULL )
		{
			free(e->name);
		}
		
		free(e);
	}
	
	return;
}

// ex39
char rot_back(char c, int shift)
{
	int res=(int)c-shift;
	char ret=(char)res;
	if( res<97 )
	{
		int reduce=res-97;
		ret=(char)(97+(NUM_ALPHABETS+reduce));
	}
	
	return ret;
}

