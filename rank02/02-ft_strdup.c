/*
Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);
*/
#include <stdlib.h>
int	strlen(char *s)
{
	int count;

	while (s[count])
	{
		count++;
	}
	return (count);
}
char	*ft_strdup(char *src)
{
	char *dup;
	int count;

	if (!src)
		return (NULL);
	dup = malloc(strlen(src + 1) * sizeof(char *));
	if (!dup)
		return (NULL);
	while (src[count])
	{
		dup[count] = src[count];
		count++;
	}
	dup[count] = '\0';
	return (dup);
}
