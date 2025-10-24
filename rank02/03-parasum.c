/*
Write a program that displays the number of arguments passed to it, 
followed by a newline.
If there are no arguments, just display a 0 followed by a newline.
Example:
$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>
*/
//fazer putnbr simples?
#include <unistd.h>
void putnbr(int num)
{
	if (num >= 10)
		putnbr(num / 10);
	char c = num % 10 + '0';
	write(1, &c, 1);
}
int main(int argc, char **argv)
{
	if (argc > 1)
		putnbr(argc -1);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}