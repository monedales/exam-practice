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
#include <unistd.h>
int	main(int argc, char **argv)
{
    char *str = argv[1];
    int chr = 0, start, end;
    if (argc > 1)
    {
        // Skip leading spaces/tabs
        while (str[chr] && (str[chr] == ' ' || str[chr] == '\t'))
            chr++;
        start = chr;
        // Find end of first word
        while (str[chr] && (str[chr] != ' ' && str[chr] != '\t'))
            chr++;
        end = chr;
        // Print remaining words
        int printed = 0;
        while (str[chr])
        {
            // Skip spaces/tabs
            while (str[chr] && (str[chr] == ' ' || str[chr] == '\t'))
                chr++;
            // Print word if found
            if (str[chr] && (str[chr] != ' ' && str[chr] != '\t'))
            {
                if (printed)
                    write(1, " ", 1);
                while (str[chr] && (str[chr] != ' ' && str[chr] != '\t'))
                {
                    write(1, &str[chr], 1);
                    chr++;
                }
                printed = 1;
            }
        }
        // Print space only if other words were printed
        if (printed)
            write(1, " ", 1);
        write(1, &str[start], end - start);
    }
    write(1, "\n", 1);
    return (0);
}
