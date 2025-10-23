/*
Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

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
#include <unistd.h>
int main (int argc, char **argv)
{
    int chr = 0;
    char *str = argv[1];
    if (argc == 2)
    {
        while (str[chr])
        {
            if (str[chr] >= 'a' && str[chr] <= 'z')
            {
                str[chr] = 'a' + 'z' - str[chr];
            }
            else if (str[chr] >= 'A' && str[chr] <= 'Z')
            {
                str[chr] = 'A' + 'Z' - str[chr];
            }
            write(1, &str[chr], 1);
            chr++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
