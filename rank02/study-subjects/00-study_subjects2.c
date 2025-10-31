/*
====================
Level 1: search_and_replace
====================
Write a program called search_and_replace that takes 3 arguments, the first
arguments is a string in which to replace a letter (2nd argument) by
another one (3rd argument).

If the number of arguments is not 3, just display a newline.

If the second argument is not contained in the first one (the string)
then the program simply rewrites the string followed by a newline.

Examples:
$>./search_and_replace "Papache est un sabre" "a" "o"
Popoche est un sobre
$>./search_and_replace "zaz" "art" "zul" | cat -e
$
$>./search_and_replace "zaz" "r" "u" | cat -e
zaz$
$>./search_and_replace "jacob" "a" "b" "c" "e" | cat -e
$
$>./search_and_replace "ZoZ eT Dovid oiME le METol." "o" "a" | cat -e
*/
#include <unistd.h>
int main(int argc, char **argv)
{
    char *str = argv[1];
    char *s2 = argv[2];
    char *s3 = argv[3];
    int chr = 0;
    if (argc == 4 && s2[1] == '\0' && s3[1] == '\0')
    {
        while (str[chr])
        {
            if (str[chr] == s2[0])
                write(1, s3, 1);
            else
                write(1, &str[chr], 1);
            chr++;
        }
           
    }
    
    write(1, "\n", 1);
    return(0);
}


/*
====================
Level 2: reverse_bits
====================
Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);
Example:

  1 byte
_____________
 0010  0110
     ||
     \/
 0110  0100
*/
unsigned char	reverse_bits(unsigned char octet)
{
    unsigned char res = 0;
    unsigned int i = 8;

    while (i--)
    {
        res = (res << 1) | (octet & 1);
        octet = octet >> 1;
    }
    return(res);
}



/*
====================
Level 3: tab_mult
====================
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
*/
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

/*
====================
Level 4: rev_wstr
====================
Write a program that takes a string as a parameter, and prints its words in
reverse order.
A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.
If the number of parameters is different from 1, the program will display
'\n'.
In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).
Examples:
$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
*/
int main(int argc, char **argv)
{
    char *str = argv[1];
    int chr = 0, chr2, first_word;
    if (argc == 2)
    {
        /* code */
    }
    write(1, "\n", 1);
    return (0);
}