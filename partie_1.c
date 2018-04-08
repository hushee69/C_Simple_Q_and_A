/*
 * Author : Harry
 * Date : 22/09/2017
*/

#include <stdio.h>
#include <stdlib.h>

void hello();
void hello_n(int n);
int longeur_str(const char *str);
void multiplier(float num1, float num2, float *res);
int string_to_int(const char *str);
int string_2_int(const char *str);
int string_2_int_refait(const char *str);

int main()
{
	// ex1
	printf("hello world\n");
	
	// ex2
	hello();
	
	// ex3
	hello_n(5);
	
	// ex4
	printf("len=%d\n", longeur_str("hello there"));
	
	// ex5
	float result=0.0;
	multiplier(5.0, 3.0, &result);
	printf("result=%.3f\n", result);
	
	// ex6
	int val=string_to_int("999999");
	printf("val=%d\n", val);
	
	// ex7 & 8
	int isValid=string_2_int("123");
	printf("isValid=%d\n", isValid);
	printf("isValid=%d\n", string_2_int("abc"));
	printf("isValid=%d\n", string_2_int("12356489798756431321312654897"));
	printf("isValid=%d\n", string_2_int("12a"));
	printf("isValid=%d\n", string_2_int("a12"));
	printf("isValid=%d\n", string_2_int("000"));
	printf("isValid=%d\n", string_2_int("001"));
	
	// ex 7 & 8 avec atoi
	printf("isValidAvec_atoi=%d\n", string_2_int_refait("abc"));
	printf("isValidAvec_atoi=%d\n", string_2_int_refait("12356489798756431321312654897"));
	printf("isValidAvec_atoi=%d\n", string_2_int_refait("12a"));
	
	// fichier liste_argument
	
	return 0;
}

// ex2
void hello()
{
	printf("hello world\n");
	
	return;
}

// ex3
void hello_n(int n)
{
	int i=0;
	for( i=0; i<n; ++i )
	{
		hello();
	}
	
	return;
}

//ex4
int longeur_str(const char *str)
{
	int ret_val=0;
	char *c=(char*)str;
	
	while( *c!='\0' )
	{
		ret_val++;
		*c++;
	}
	
	return ret_val;
}

// ex5
void multiplier(float num1, float num2, float *res)
{
	*res=num1*num2;
	
	return;
}

// ex6
int string_to_int(const char *str)
{
	int res=0;
	
	while( *str!='\0' )
	{
		if( *str>='0' && *str<='9' )
		{
			int val=*str-'0';
			res=(res*10)+val;
		}
		else
		{
			res=-1;
			break;
		}
		*str++;
	}
	
	return res;
}

// ex7
int string_2_int(const char *str)
{
	return (string_to_int(str)!=-1) ? 0 : 1;
}

// ex7 & 8 avec atoi
int string_2_int_refait(const char *str)
{
	return atoi(str)!=0;
}

