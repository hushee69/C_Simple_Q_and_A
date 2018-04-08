/*
 * Author : Harry
 * Date : 23/09/2017
*/

#include <stdio.h>
#include <stdlib.h>

int to_integer(char *s);
void dessiner_sapin(int n);

int main(int argc, char *argv[])
{
	// pour un seul argument
	/*
	if( argc!=2 )
	{
		fprintf(stderr, "usage: [%s arg]\n", argv[0]);
		exit(-1);
	}
	*/
	
	// plusieurs arguments
	if( argc<2 )
	{
		fprintf(stderr, "usage: [%s args]\n", argv[0]);
		exit(-1);
	}
	
	int i=0, num_arg=0;
	
	for( i=1; i<argc; ++i )
	{
		if( (num_arg=to_integer(argv[i]))<0 )
		{
			fprintf(stderr, "arguments doit etre ints\n");
			exit(-1);
		}
		printf("sapin numero %d\n", argc-1);
		dessiner_sapin(num_arg);
		printf("\n\n");
	}
	
	// fichier partie_3.c
	
	return 0;
}

int to_integer(char *s)
{
	int i=0, num=0;
	while( *s!='\0' )
	{
		if( *s>='0' && *s<='9' )
		{
			int c=(int)(*s-'0');
			num=(num*10)+c;
		}
		else
		{
			num=-1;
			break;
		}
		*s++;
	}
	
	return num;
}

// ex12
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
				printf(" ");
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
					printf(" ");
				}
			}
		}
	}
	printf("\n");
}

