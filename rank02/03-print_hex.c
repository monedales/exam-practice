/*
Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/
#include <stdio.h>
#include <unistd.h>
void	print_hex(unsigned int number)
{
	// char *base = "0123456789abcdef";
	char chr = 0;
	unsigned int quo = number / 16;

	if (number >= 16)
		print_hex(quo);
	if ((number % 16) < 10)
		chr = '0' + (number % 16);
	else if ((number % 16) >= 10)
		chr = 'a' + ((number % 16) - 10);
	// number = base[number % 16];
	write(1, &chr, 1);
}
int ft_atoi(char *str)
{
	int signal;
	int result;

	signal = 1;
	result = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (str[0] == '-')
			signal = -signal;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	return (result * signal);	
}


int main(int argc, char **argv)
{
	int nb = 0;
	if (argc == 2)
	{
		nb = ft_atoi(argv[1]);
		print_hex(nb);
	}
	write(1, "\n", 1);
	return (0);
}