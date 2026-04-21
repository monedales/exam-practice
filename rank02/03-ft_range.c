/*
Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

#include <stdio.h>
#include <stdlib.h>
int ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int     *ft_range(int start, int end)
{
	int size = ft_abs(start - end) + 1;
	int *range = (int *)malloc(size * sizeof(int));
	if (!range)
		return (NULL);
	int i = 0;
	while (i < size)
	{
		if (start <= end)
			range[i] = start + i;
		else if (start > end)
			range[i] = start - i;
		i++;
	}
	return(range);
}

int	main(void)
{
	int	start[4] = {1, -1, 0, 0};
	int	end[4] = {3, 2, 0, -3};

	for (int i = 0; i < 4; i++)
	{
		int	*range = ft_range(start[i], end[i]);
		int	size = ft_abs(start[i] - end[i]) + 1;
		for (int j = 0; j < size; j++)
			printf("%d, ", range[j]);
		printf("\n");
		free(range);
	}
} 