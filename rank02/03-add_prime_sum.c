/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/
#include <unistd.h>
int	is_prime(long n)
{
	if (n < 2)
		return (0);
	int i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr(long n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int	ft_atoi(char *str)
{
	int r = 0;
	int sg = 1;

	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10 + (*str - '0');
		str++;
	}
	return (sg * r);
}

void	add_prime_sum(int n)
{
	int i = 0;
	int sum = 0;
	while (i <= n)
	{
		if (is_prime(i))
			sum += i;
		i++;
	}
	ft_putnbr(sum);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		long n = ft_atoi(av[1]);
		if (n >= 0)
			add_prime_sum(n);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}