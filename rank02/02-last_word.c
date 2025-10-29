/*
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.
A word is a section of string delimited by spaces/tabs or by the start/end of
the string.
If the number of parameters is not 1, or there are no words, display a newline.
Example:
$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/
#include <unistd.h>
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *str = argv[1];
		int end = 0;
		// Find end of string
		while (str[end])
			end++;
		end--;
		// Skip trailing spaces/tabs
		while (end >= 0 && (str[end] == ' ' || str[end] == '\t'))
			end--;
		if (end < 0)
		{
			write(1, "\n", 1);
			return (0);
		}
		// Find start of last word
		int start = end;
		while (start >= 0 && str[start] != ' ' && str[start] != '\t')
			start--;
		start++;
		// Print last word
		while (start <= end)
		{
			write(1, &str[start], 1);
			start++;
		}
	}
	write(1, "\n", 1);
	return (0);
}