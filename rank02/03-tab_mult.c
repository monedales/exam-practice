/*
Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>
*/
#include <unistd.h>
int fatoi(char *s)
{
    int res = 0, i = 0;
    while (s[i] && (s[i] >= '0'&& s[i] <= '9'))
    {
        res = res * 10 + (s[i] - '0');
        i++;
    }
    return(res);
}
void putnbr(int n)
{
    if (n > 9)
        putnbr(n / 10);
    write(1, &"0123456789"[n % 10], 1);
}
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    int num = fatoi(argv[1]), i = 1;
    while (i < 10)
    {
        putnbr(i);
        write(1, " x ", 3);
        putnbr(num);
        write(1, " = ", 3);
        putnbr(num * i);
        write(1, "\n", 1);
        i++;
    }
    
    return (0);
}