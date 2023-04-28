#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	print_char(int c) 
{
	return write(1, &c, 1);
}

int	print_digit(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return print_digit(-n, base) + 1;
	}
	else if (n < base)
		return print_char(symbols[n]);
	else
	{
		count = print_digit(n / base, base);
		return count + print_digit(n % base, base);
	}
}

int	print_str(char *s)
{
	int	count;

	count = 0;
	while (*s)
		count += write(1, s++, 1);
	return count;
}	

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = print_char(va_arg(ap, int));
	else if (specifier == 's')
		count = print_str(va_arg(ap, char *));
	else if (specifier == 'd')
		count = print_digit((long)va_arg(ap, int), 10);
	else if (specifier == 'x')
		count = print_digit((long)va_arg(ap, unsigned int), 16);
	else
		count += write(1, &specifier, 1);
	return count;
}


int	my_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += print_format(*++format, ap);
		else 
			count += write(STDOUT_FILENO, format, 1);
		++format;
	}
	va_end(ap);
	return count;
}



int	main()
{
	int	count;

	
	count = my_printf("Hello %s\n", "John");
	printf("%d chars\n", count);//, fflush(stdout);
	count = my_printf("Char-> %c\n", 'a');
	printf("%d chars\n", count);//, fflush(stdout);
	count =my_printf("Nbr-> %d\n", -42);
	printf("%d chars\n", count);//, fflush(stdout);
	count = my_printf("Hex-> %x\n", -1);
	printf("%d chars\n", count);//, fflush(stdout);

	//REAL 
	printf("\n\n");
	puts("REAL PRINTF");
	count = printf("Hello %s\n", "John");
	printf("%d chars\n", count);//, fflush(stdout);
	count = printf("Char-> %c\n", 'a');
	printf("%d chars\n", count);//, fflush(stdout);
	count = printf("Nbr-> %d\n", -42);
	printf("%d chars\n", count);//, fflush(stdout);
	count = printf("Hex-> %x\n", -1);
	printf("%d chars\n", count);//, fflush(stdout);

}
