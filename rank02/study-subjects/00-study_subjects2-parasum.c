/*
Assignment name  : parasum
Expected files   : parasum.c
Allowed functions: write
--------------------------------------------------------------------------------
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
void putnbr(int n)
{
    if (n >= 10)
        putnbr(n / 10);
    write(1, &"0123456789"[n % 10], 1);
}
int main(int argc, char **argv)
{
    if (argc > 1)
    {
        putnbr(argc - 1);
    }
    else
        write(1, "0\n", 2);
    return (0);
}