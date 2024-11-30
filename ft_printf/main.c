#include "ft_printf.h"
#include <libc.h>

int main()
{
	// char *str = "1younes";
	 int i = -14;
	int  p = ft_printf("|%-22.10x|\n", UINT16_MAX, INT_MAX);
	int  m =    printf("|%-22.10x|\n", UINT16_MAX, INT_MAX);
	m = printf("\n%d \n%d\n", p,m);



	//  m =    printf("1|%#x|%#x|%#x|%#x|%#x|%#x|%#x|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	//  p = ft_printf("1|%#x|%#x|%#x|%#x|%#x|%#x|%#x|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	//  m = printf("\n%d \n%d\n", p,m);

 	// m = printf("2|%#X|%#X|%#X|%#X|%#X|%#X|%#X|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	//  p = ft_printf("2|%#X|%#X|%#X|%#X|%#X|%#X|%#X|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	//  m = printf("\n%d \n%d\n", p,m);

	//  m =    printf("|%%%%%%%%%%%%%%|%#X|%#X|%#X|%#X|%#X|%#X|%#X|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	//  p = ft_printf("|%%%%%%%%%%%%%%|%#X|%#X|%#X|%#X|%#X|%#X|%#X|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	//  m = printf("\n%d \n%d\n", p,m);

}






