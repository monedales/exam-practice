/*
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);
*/
char    *ft_strcpy(char *s1, char *s2)
{
   unsigned int count = 0;

    while (s1[count])
    {
        s2[count] = s1[count];
        count++;
    }
    s2[count] = '\0';
    return (s2);
}
#include <stdio.h>
int main(void)
{
    char *s1, *s2;
    s1 = "olar";
    printf("%s", ft_strcpy(s1, s2));
    return (0);
}