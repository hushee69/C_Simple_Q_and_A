/*
 * Author : Harry
 * Date : 23/09/2017
*/

#include "etudiant.h"

int main()
{
	srand(time(NULL));
	
	// ex29 & 30
	etudiant *e1=creer_etudiant();
	
	affiche_etudiant(*e1);
	free(e1);
	
	// ex31 en variables.c
	
	// ex32 - 36
	char a=rot('a', 36);
	printf("a=%c\n", a);
	
	// ex34
	etudiant ets[10];
	memset(&ets, 0, sizeof(ets));
	
	creer_etudiant_no_return(&ets[0]);
	affiche_etudiant(ets[0]);
	free(ets[0].name);
	
	creer_classe(5);
	
	// ex39
	const char *str="mgoaybfaudpqxadxmdfoagxqpmzexqehquzqe";
	int len=strlen(str);
	char *decoded_fwd=(char*)malloc(sizeof(char)*(len+1));
	char *decoded_bck=(char*)malloc(sizeof(char)*(len+1));
	
	int i=0, bytes_written=0, val_entered=0;
	
	printf("Enter value to try decode: ");
	scanf("%d", &val_entered);
	for( i=0; i<len; ++i )
	{
		decoded_fwd[bytes_written]=rot(str[i], val_entered);
		decoded_bck[bytes_written]=rot_back(str[i], val_entered);
		bytes_written++;
	}
	decoded_fwd[bytes_written]='\0';
	decoded_bck[bytes_written]='\0';
	
	printf("%s\n", decoded_fwd);
	printf("%s\n", decoded_bck);
	
	// decoded_bck with 12
	// aucomptoirdelorlartcouledanslesveines
	
	// decoded_fwd with 14
	// aucomptoirdelorlartcouledanslesveines
	
	return 0;
}

