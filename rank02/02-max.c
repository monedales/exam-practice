/*
Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/

int	max(int* tab, unsigned int len)
{
	int count;
	int biggie;

	count = 0;
	biggie = tab[0];
	if (tab == 0)
		return (0);
	while (count < len)
	{
		if (tab[count] > biggie)
			biggie = tab[count];
		count++;
	}
	return (biggie);
}

#include <stdio.h>

int main()
{
	int int_tab[] = {1, 3, -2, 65, 65};
	printf("%d", max(int_tab, 5));
}