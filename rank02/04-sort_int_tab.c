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
	unsigned int	i = 0, j, temp = 0;
	while (i + 1 < size)
	{
		j = i + 1;
		while (j < size)
		{
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
	int tab[6] = {5, 9, 3, 7, 1, 2};
	unsigned int i = 0;
	sort_int_tab(tab, 6);
	while (i < 6)
    {
        printf("%d", tab[i]);
        if (i + 1 < 6)
            printf(" ");
        i++;
    }
    printf("\n");
	
	return (0);
}