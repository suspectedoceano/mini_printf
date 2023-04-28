
/*
 * The ellipsis tells the compiler that there will be an unknown number of additional arguments passed to the function,
 * and the C standard library provides a set of macros to process these arguments. 
 * These macros are:
 * 	~va_start
 * 	~va_arg
 * 	~va_copy
 * 	~va_end
*/

#include <stdarg.h>
#include <stdio.h>

// Easy peasy average function with variadic elements

float	average(int num, ...)
{
	int		total;
	va_list	ap;

	total = 0;
	va_start(ap, num);
	for (int i = 0; i < num; ++i)
		total += va_arg(ap, int);
	va_end(ap);
	return (float)total / num; 
}

int	main()
{
	printf("The average is %.2f\n",
					
			average(5,          3,4,5,6,78));
		
}
