/*
 * Author : Harry
 * Date : 22/09/2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inverse_chaine(const char *str);

int main()
{
	// ex16
	const char *str="abcdef";
	char *backward=inverse_chaine(str);
	printf("backward= [%s]\n", backward);
	
	// fichier partie_4 pour matrices
	
	return 0;
}

char *inverse_chaine(const char *str)
{
	int i=0, bytes_written=0, len=strlen(str);
	char *ret=(char*)malloc(sizeof(char)*len);
	
	for( i=len-1, bytes_written=0; i>=0; --i, ++bytes_written )
	{
		ret[bytes_written]=str[i];
	}
	ret[bytes_written]='\0';
	
	return ret;
}

