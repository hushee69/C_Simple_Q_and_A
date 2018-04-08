/*
 * Author : Harry
 * Date : 22/09/2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dessiner_sapin(int n);
char *hexamaj(const char *str);

int main()
{
	// ex10
	dessiner_sapin(7);
	
	// fichier sapin.c programme avec arguments
	
	// ex11
	const char *str="hello world";
	char *upper_val=hexamaj(str);
	printf("hexamaj_str= [%s]\n", upper_val);
	
	return 0;
}

// ex10
void dessiner_sapin(int n)
{
	int i=0, j=0, k=0, l=0, height=(n%2==0) ? (n-1) : n, length=(n%2==0) ? (n+1) : (n+2), star_count=1, dot_count=length, middle=length/2, tree_bark=length/2, tree_wideness=1;
	
	for( i=0; i<height-1; ++i )
	{
		for( j=0; j<dot_count; ++j )
		{
			if( star_count<=length && j==middle )
			{
				for( k=0; k<star_count; ++k )
				{
					printf("*");
				}
			}
			else
			{
				printf(".");
			}
		}
		
		star_count+=2;
		dot_count-=2;
		middle--;
		printf("\n");
		
		if( star_count>length )
		{
			for( l=0; l<length; ++l )
			{
				if( l>=tree_bark-1 && l<=tree_bark+1 )
				{
					printf("*");
				}
				else
				{
					printf(".");
				}
			}
		}
	}
	printf("\n");
}

// ex11
char *hexamaj(const char *str)
{
	int i=0, bytes_written=0;
	int len=strlen(str);
	char *ret=(char*)malloc(sizeof(char)*len);
	if( ret!=NULL )
	{
		for( i=0, bytes_written=0; i<len; ++i, ++bytes_written )
		{
			if( str[i]>=97 && str[i]<=122 )
			{
				ret[bytes_written]=(char)(str[i]-32);
			}
			else
			{
				ret[bytes_written]=str[i];
			}
		}
	}
	ret[bytes_written]='\0';
	
	return ret;
}

