/*
Write the following function:
void sort_int_tab(int *tab, unsigned int size);
It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.
Doubles must be preserved.
Input is always coherent.
*/
void sort_int_tab(int *tab, unsigned int size)
{
	int	i = 0, j, temp = 0;
	while (tab[i])
	{
		while (tab[j])
		{
			j = 0;
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}
#include <stdio.h>
int main(void)
{
	int tab[5] = {5, 9, 7, 3, 1};
	int i = 0;
	sort_int_tab(tab, 5);
	while (tab[i])
	{
		printf("%d\n", tab[i]);
		i++;
	}
	
	return (0);
}