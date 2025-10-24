/*
Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);
*/
#include <string.h>
#include <stdio.h>
int main(void)
{
	char *s = "hello";
	const char *accept = "jfkhpell";
	printf("%zu\n", strspn(s, accept));
	return (0);
}