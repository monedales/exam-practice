/*
Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/
#include <stdio.h>
#include <stdlib.h>
int abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int     *ft_rrange(int start, int end)
{
	int size = abs(start - end) + 1;
	int *range = (int *)malloc(sizeof(int) * size);
	if (!range)
		return (NULL);
	int i = 0;
	while (i < size)
	{
		if (end >= start)
			range[i] = end - i;
		else
			range[i] = end + i;
		i++;
	}
	return (range);
}

int	main(void)
{
	int	start[4] = {1, -1, 0, 0};
	int	end[4] = {3, 2, 0, -3};

	for (int i = 0; i < 4; i++)
	{
		int	*range = ft_rrange(start[i], end[i]);
		int	size = abs(start[i] - end[i]) + 1;
		for (int j = 0; j < size; j++)
			printf("%d, ", range[j]);
		printf("\n");
		free(range);
	}
} 