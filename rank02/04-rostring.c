/*
Write a program that takes a string and displays this string after rotating it
one word to the left.
Thus, the first word becomes the last, and others stay in the same order.
A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.
Words will be separated by only one space in the output.
If there's less than one argument, the program displays \n.
Example:
$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/
int	main(int argc, char **argv)
{
	char *str = argv[1];
	int chr = 0, chr2;
	if (argc > 1)
	{
		while (str[chr] && str[chr] == ' ' && str[chr] == '\t')
			chr++;
		chr2 = chr; 
		
	}
	write(1, "\n", 1);
	return (0);
}
/*
// ...existing code...
#include <unistd.h>

void	rostring(char *str)
{
    int	i;
    int	start;
    int	end;

    i = 0;
    /* skip leading spaces/tabs */
    while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        i++;
    start = i;               /* index of first word start */
    /* if no word, nothing to do */
    if (!str[i])
        return ;
    /* find end of first word */
    while (str[i] && str[i] != ' ' && str[i] != '\t')
        i++;
    end = i;                 /* end is exclusive index of first word */

    /* print every word that comes after the first one,
       each followed by a single space (if any exist) */
    while (str[i])
    {
        /* skip spaces between words */
        while (str[i] && (str[i] == ' ' || str[i] == '\t'))
            i++;
        /* if a next word exists, print it and a space */
        if (str[i])
        {
            while (str[i] && str[i] != ' ' && str[i] != '\t')
                write(1, &str[i++], 1);
            write(1, " ", 1);
        }
    }

    /* finally print the first word */
    i = start;
    while (i < end)
        write(1, &str[i++], 1);
}

int	main(int argc, char **argv)
{
    if (argc > 1)
        rostring(argv[1]);
    write(1, "\n", 1);
    return (0);
}

*/