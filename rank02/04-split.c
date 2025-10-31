/*
Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/
#include <cstddef>

char	**ft_split(char const *s, char c)
{
	int i = 0, j, k, word = 0, star, end;
	char **arr;

	//count words
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') //skip spaces
			i++;
		if (str[i]) \\count if 
			word++;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;	
	}
	//allocate
	arr = malloc(sizeof(char *) * (word + 1));
	if (!arr)
		return (NULL);

	//extract words
	i = 0; k = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') //skip spaces
			i++;
		start = i;
		while(str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
		end = i;
		if (end > start)
		{
			arr[k] = malloc(end - start + 1);
			if (!arr)
				return (NULL);
			for (j = 0; j < end - start; j++)
                arr[k][j] = str[start + j];
            arr[k][j] = '\0';
            k++;
		}
	}
	arr[k][j] = '\0';
	return (arr);
}