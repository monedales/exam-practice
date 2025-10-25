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
	if (number >= 16)
		print_hex(number / 16);
	write(1, &"0123456789abcdef"[number%16], 1);
}

int ft_atoi(char *str)
{
	int result = 0, i = 0, signal = 1;

	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			signal = -signal;
			i++;
		}
		
		return (signal);
	}
	
	while (str[i])
	{
		if (str[i] >= 0 && str[i] <= 9)
		{
			result = result * 10 + (str[i] - '0');
		}
		i++;
	}
	return (signal * result);
	
}
#include <stdlib.h>

int main(int argc, char **argv)
{
	// int nb = 0;
	if (argc == 2)
	{
		// nb = ft_atoi(argv[1]);
		print_hex(atoi(argv[1]));
	}
	write(1, "\n", 1);
	return (0);
}