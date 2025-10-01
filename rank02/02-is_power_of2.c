/*
Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);
*/

int	is_power_of_2(unsigned int n)
{
	unsigned int num = 1;

	while (num <= n)
	{
		if (num == n)
			return (1);
		num = num * 2;
	}
	return (0);
}
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int idx = 1;
	if (argc < 2)
		printf("Write a positive number in the parameter!\n");
	else if (argc >= 2)
		printf("%d\n", is_power_of_2((unsigned int)atoi(argv[idx])));
	return (0);
}