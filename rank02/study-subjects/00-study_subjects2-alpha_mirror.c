/*
Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes a string and displays it after replacing each alphabetical character by its opposite in the alphabet (a <-> z, b <-> y, etc). Other characters remain unchanged.

If the number of arguments is not 1, print a newline.
*/
#include <unistd.h>
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        char *str = argv[1];
        int chr = 0;
        while (str[chr])
        {
            if (str[chr] >= 'a' && str[chr] <= 'z')
                str[chr] = 'a' + 'z' - str[chr];
            else if (str[chr] >= 'A' && str[chr] <= 'Z')
                str[chr] = 'A' + 'Z' - str[chr];
            write(1, &str[chr], 1);
            chr++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
/**********************/
int fstrlen(char *s)
{
    int i = 0;
    while (s[i])
    {
        i++;
    }
    return (i);
}
char *ft_strdup(char *src)
{
    char *dest;
    int i = 0;
    dest = malloc(sizeof(char) * (fstrlen(src) + 1));
    if (!dest)
        return (NULL);
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);    
}