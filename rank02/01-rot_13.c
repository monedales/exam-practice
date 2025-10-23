/*
Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.
'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.
The output will be followed by a newline.
If the number of arguments is not 1, the program displays a newline.
Example:
$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>
*/
#include <unistd.h>
int main(int argc, char **argv)
{
	char *str = argv[1];
	int chr = 0;
	if (argc == 2)
	{
		while (str[chr])
		{
			if ((str[chr] >= 97 && str[chr] <= 109) 
			|| (str[chr] >= 65 && str[chr] <= 77))
				str[chr] += 13;
			else if ((str[chr] >= 110 && str[chr] <= 122) 
			|| (str[chr] >= 78 && str[chr] <= 90))
				str[chr] -= 13;
			write(1, &str[chr], 1);
			chr++;
		}
		
	}
	write(1, "\n", 1);
	return (0);
}