/*
Allowed functions: malloc, realloc, write
--------------------------------------------------------------------------------
Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.
A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.
A snake_case string is a string where each word is in lower case, separated by
an underscore "_".
Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$
*/
#include <unistd.h>
int main(int argc, char **argv)
{
	int chr = 0;
	char *str = argv[1];
	if (argc == 2)
	{
		while (str[chr])
		{
			if (str[chr] >= 65 && str[chr] <= 90)
			{
				str[chr] += 32;
				write(1, "_", 1);
			}
			write(1, &str[chr], 1);
			chr++;
		}
	}
	
	write(1, "\n", 1);
	return (0);
}