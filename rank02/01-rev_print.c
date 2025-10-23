/*
Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$
*/
int	strleny(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return (len);
}
#include <unistd.h>
int	main(int argc, char **argv)
{
	int len = strleny(argv[1]) - 1;
	if (argc == 2)
	{
		while (len >= 0)
		{
			write(1, &argv[1][len], 1);
			len--;
		}
	}
	write(1, "\n", 1);
	return(0);
}