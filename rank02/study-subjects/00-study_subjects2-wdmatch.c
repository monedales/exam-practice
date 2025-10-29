/*
Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes two strings and displays, without doubles, the characters that appear in both strings, in the order they appear in the first one. Only print each character once.

If the number of arguments is not 2, print a newline.
*/
#include <unistd.h>
int main(int argc, char **argv)
{
    if (argc == 3)
    {
        char *s1 = argv[1], *s2 = argv[2];
        int chr = 0, ch2 = 0;
        while (s1[chr] && s2[ch2])
        {
            if (s1[chr] && s2[ch2] == s1[chr])
                chr++;
            ch2++;
        }
        if (s1[chr] == '\0')
        {
            write(1, s1, chr);
        }
    }
    write(1, "\n", 1);
    return (0);
}