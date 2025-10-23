/*
Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.
'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.
The output will be followed by a \n.
If the number of arguments is not 1, the program displays \n.
Example:
$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
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
            if ((str[chr] >= 97 && str[chr] <= 121) 
                || (str[chr] >= 65 && str[chr] <= 89))
                str[chr] = str[chr] + 1;
            else if (str[chr] == 122 || str[chr] == 90)
                str[chr] = str[chr] - 25;
            write(1, &str[chr], 1);
            chr++;
        }
    }
    write(1, "\n", 1);
    return (0);
}