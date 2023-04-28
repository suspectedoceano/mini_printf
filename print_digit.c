#include <unistd.h>
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

#define N 255
#define BASE 2


int main()
{
	printf("\nThe number of chars written for %d in base %d is %d\n",
			N,
			BASE,
			print_digit(N, BASE));
}
