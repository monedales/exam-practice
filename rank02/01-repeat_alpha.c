/*
Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.
'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...
Case remains unchanged.
If the number of arguments is not 1, just display a newline.
Examples:
$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/
#include <unistd.h>
int main(int argc, char **argv)
{
    int chr = 0;
    int repeat;

    if (argc == 2)
    {
        while (argv[1][chr])
        {
            repeat = 0;
            if ((argv[1][chr] >= 97 && argv[1][chr] <= 122))
                repeat = argv[1][chr] - 97 + 1;
            else if (argv[1][chr] >= 65 && argv[1][chr] <= 90)
                repeat = argv[1][chr] - 65 + 1;
            else
                repeat = 1;
            while (repeat > 0)
            {
                write(1, &argv[1][chr], 1);
                repeat--;
            }
            chr++;
        }
    }
    write(1, "\n",1);
    return (0);
}