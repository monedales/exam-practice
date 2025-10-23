/*
Assignment name  : snake_to_camel
Expected files   : snake_to_camel.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------
Write a program that takes a single string in snake_case format
and converts it into a string in lowerCamelCase format.
A snake_case string is a string where each word is in lower case, separated by
an underscore "_".
A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.
Examples:
$>./snake_to_camel "here_is_a_snake_case_word"
hereIsASnakeCaseWord
$>./snake_to_camel "hello_world" | cat -e
helloWorld$
$>./snake_to_camel | cat -e
$
*/
#include <unistd.h>
int	toUpper(int chr)
{
	if (chr >= 97 && chr <= 122)
	{
		chr = chr - 32;
	}
	return (chr);
}
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
int main(int argc, char **argv)
{
	char *str = argv[1];
	int chr = 0;
	if (argc == 2)
	{
		while (str[chr])
		{
			if (str[chr] == 95)
			{
				chr += 1;
				if (str[chr] >= 97 && str[chr] <= 122)
					ft_putchar(toUpper(str[chr]));
			}
			else
				write(1, &str[chr], 1);
			chr++;
		}
	}
	write(1, "\n", 1);
	return (0);
}