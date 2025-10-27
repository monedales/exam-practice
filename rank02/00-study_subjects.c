/*
====================
Level 1: fizzbuzz
====================
Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that prints the numbers from 1 to 100, each separated by a newline.
If the number is a multiple of 3, it prints 'fizz' instead.
If the number is a multiple of 5, it prints 'buzz' instead.
If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.
*/
#include <unistd.h>
// void    putnbr(int n)
// {
//     char c;
//     if (n >= 10)
//         putnbr(n / 10);
//     c = (n % 10) + '0';
//     write(1, &c, 1);
// }
// int main(void)
// {
//     int num = 1;

//     //mult 3 -> if (num % 3 == 0)
//     //mult 5 -> if (num % 5 == 0)
//     //mult 3; 5 -> if (num % 3 == 0 && num % 5 == 0)
//     while (num <= 100)
//     {
//         if (num % 3 == 0 && num % 5 == 0)
//             write(1, "fizzbuzz\n", 9);
//         else if (num % 3 == 0)
//             write(1, "fizz\n", 5);
//         else if (num % 5 == 0)
//             write(1, "buzz\n", 5);
//         else
//         {
//             putnbr(num);
//             write(1, "\n", 1);
//         }
//         num++;
//     }
//     return (0);
// }


/*
==================== 
Level 2: alpha_mirror
====================
Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical character, followed by a newline.
'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'
and so on.
Case is not changed.
If the number of arguments is not 1, display only a newline.
Examples:
$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>
*/
#include <stdio.h>
// int main(int argc, char **argv)
// {
//     char *str = argv[1];
//     int chr = 0, i = 25;
//     char *alpha ="abcdefghijklmnopqrstuvwxyz";
//     char *mirror ="zyxwvutsrqponmlkjihgfedcba";
//     if (argc == 2)
//     {
//         // abcdefghijklmnopqrstuvwxyz
//         // zyxwvutsrqponmlkjihgfedcba
//         while (str[chr])
//         {
//             printf("\nBEFORE chr: %d char: (%c) ascii: %d\n", chr, str[chr], str[chr]);
//             if ((str[chr] >= 97 && str[chr] <= 122)) 
//                 str[chr] =  97 + 122 - str[chr];
//             else if ((str[chr] >= 65 && str[chr] <= 90)) 
//                 str[chr] =  65 + 90 - str[chr];
//             printf("\nAFTER chr: %d char: (%c) ascii: %d\n", chr, str[chr], str[chr]);
//             write(1, &str[chr], 1);
//             chr++;
//         }
//     }
//     write(1, "\n", 1);
//     return (0);
// }

// // Alternative alpha_mirror solution using lookup arrays
// #include <unistd.h>
// int main_lookup(int argc, char **argv)
// {
//     char *str = argv[1];
//     int chr = 0;
//     char *mirror_lower = "zyxwvutsrqponmlkjihgfedcba";
//     char *mirror_upper = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
//     if (argc == 2)
//     {
//         while (str[chr])
//         {
//             if (str[chr] >= 'a' && str[chr] <= 'z')
//                 write(1, &mirror_lower[str[chr] - 'a'], 1);
//             else if (str[chr] >= 'A' && str[chr] <= 'Z')
//                 write(1, &mirror_upper[str[chr] - 'A'], 1);
//             else
//                 write(1, &str[chr], 1);
//             chr++;
//         }
//     }
//     write(1, "\n", 1);
//     return (0);
// }

/*
====================
Level 3: ft_range
====================
Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive values that begin at start and end at end (Including start and end !), then return a pointer to the first value of the array.

Examples:
- ft_range(0, -3) returns the array {0, -1, -2, -3}
- ft_range(1, 1) returns the array {1}
- ft_range(-1, 2) returns the array {-1, 0, 1, 2}
*/
#include <stdlib.h>
int abs(int n)
{
    if(n < 0)
        n = -n;
    return (n);
}
int     *ft_range(int start, int end)
{
    int len = abs(end - start) + 1;
    int *range;
    int i = 0; 
    range = malloc(sizeof(int) * len);
    if (!range)
        return (NULL);
    while (i < len)
    {
        if(start <= end)
            range[i] = start + i;
        else
            range[i] = start - i;
        i++;
    }
    return(range);
}
int main(void)
{
    int start = 0;
    int end = 2;
    int *arr = ft_range(start, end);
    int i = 0;
    int size;
    if (start <= end)
        size = end - start + 1;
    else
        size = start - end + 1;
    while (i < size)
    {
        printf("%d", arr[i]); 
        i++;
    }
    printf("\n");
    free(arr);
    return (0);
}

/*
====================
Level 4: flood_fill
====================
Assignment name  : flood_fill
Expected files   : *.c, *.h
Allowed functions: -
--------------------------------------------------------------------------------
Write a function that takes a char ** as a 2-dimensional array of char, a t_point as the dimensions of this array and a t_point as the starting point.
Starting from the given 'begin' t_point, this function fills an entire zone by replacing characters inside with the character 'F'. A zone is a group of the same character delimitated horizontally and vertically by other characters.

The function must be declared as follows:

void  flood_fill(char **tab, t_point size, t_point begin);

The t_point structure is as follows:

typedef struct  s_point
{
  int           x;
  int           y;
}               t_point;
Example:
$> cat test_main.c
#include "test_functions.h"
#include "flood_fill.h"
int main(void)
{
	char **area;
	t_point size = {8, 5};
	t_point begin = {2, 2};
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	}
	area = make_area(zone);
	print_tab(area);
	flood_fill(area, size, begin);
	putc('\n');
	print_tab(area);
	return (0);
}
*/
typedef struct  s_point
{
  int           x;
  int           y;
}               t_point;

//condições - row < 0; col < 0; -> está pra trás do mapa
	// target == F; target == 1? -> já pintou e é parede 
	//row >= size.y?; col >= size.x? -> passou pra fora do mapa
	//marcar alguma coisa no mapa como F
	//recursiva 4 vezes - 1 + 1 pra row e col
void fill(char **tab, t_point size, char target, int row, int col)
{
    if (row < 0 || col < 0 || row >= size.y || col >= size.x)
        return ;
    if (tab[row][col] == 'F' || tab[row][col] != target)
        return ;
    tab[row][col] = 'F';

    fill(tab, size, target, row + 1, col);
    fill(tab, size, target, row - 1, col);
    fill(tab, size, target, row, col + 1);
    fill(tab, size, target, row, col - 1);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
    char target = tab[begin.y][begin.x];
    fill(tab, size, target, begin.y, begin.x);
}