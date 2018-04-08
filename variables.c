/*
 * Author : Harry
 * Date : 23/09/2017
*/

#include <stdio.h>

#define GLOBAL				25
#define IN_FUNCTION			50
#define IN_BLOCK			75

// ex31
int var=GLOBAL;

void func();

int main()
{
	func();
	
	printf("%d\n", var);
	
	func();
	
	if( 1 )
	{
		int var=IN_BLOCK;
		
		printf("%d\n", var);
	}
	
	printf("%d\n", var);
	
	return 0;
}

void func()
{
	int var=IN_FUNCTION;
	
	printf("%d\n", var);
	
	return;
}

