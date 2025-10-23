/*
Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.
The display will be in the order characters appear in the command line, and
will be followed by a \n.
If the number of arguments is not 2, the program displays \n.
Example:
$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/
#include <unistd.h>
int main(int argc, char **argv)
{
	char *str1 = argv[1];
	char *str2 = argv[2];
	int ascii[256] = {0};
	int chr1 = 0;
	int chr2 = 0;

	if(argc == 3)
	{
		while (str1[chr1])
		{
				if (ascii[str1[chr1]] == 0)
				{
					ascii[str1[chr1]] = 1;
					write(1, &str1[chr1], 1);
				}
			chr1++;
		}
		while (str2[chr2])
		{
			if (ascii[str2[chr2]] == 0)
			{
				ascii[str2[chr2]] = 1;
				write(1, &str2[chr2], 1);
			}
			chr2++;
		}
	}
	write(1, "\n", 1);
	return (0);
}