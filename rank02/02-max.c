/*
Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/
#include <unistd.h>
int	max(int* tab, unsigned int len)
{
	int i = 0;
	int biggie = tab[0];

	if (len == 0)
		return (0);
	while (i < len)
	{
		if (tab[i] >= biggie)
			biggie = tab[i];
		i++;
	}
	
	return (biggie);
}

#include <stdio.h>

int main()
{
	int int_tab[] = {1, 3, 2, 80, 65};
	printf("%d", max(int_tab, 5));
}