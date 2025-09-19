/*
Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/
#include <stdio.h>
#include <unistd.h>
int	ft_atoi_base(const char *str, int str_base)
{
	if (str_base < 2 || str_base > 16)
		return (0);
	int result = 0;
	int signal = 1;
	int digit = 0;
	int idx = 0;
	while ((str[idx] >= '\t' && str[idx] <= '\r') || str[idx] == ' ')
		idx++;
	if (str[idx] == '-')
	{
		signal = -signal;
		idx++;
	}
	while (str[idx])
	{
		if (str[idx] >= '0' && str[idx] <= '9')
			digit = str[idx] - '0';
		else if (str[idx] >= 'a' && str[idx] <= 'f')
			digit = str[idx] - 'a' + 10;
		else if (str[idx] >= 'A' && str[idx] <= 'F')
			digit = str[idx] - 'A' + 10;
		else
			break;
		if (digit >= str_base)
			break;
		result = result * str_base + digit;
		idx++;
	}
	return (result * signal);
}

int main(void)
{
	printf("%d\n", ft_atoi_base("a", 16));
	printf("%d\n", ft_atoi_base("deadbeef", 16));

	    // Different bases
    printf("\nDifferent bases:\n");
    printf("'101' base 2: %d (expected: 5)\n", ft_atoi_base("101", 2));
    printf("'123' base 8: %d (expected: 83)\n", ft_atoi_base("123", 8));
    printf("'FF' base 16: %d (expected: 255)\n", ft_atoi_base("FF", 16));
    
    // Negative numbers
    printf("\nNegative numbers:\n");
    printf("'-123' base 10: %d (expected: -123)\n", ft_atoi_base("-123", 10));
    printf("'-ff' base 16: %d (expected: -255)\n", ft_atoi_base("-ff", 16));
    
    // Whitespace handling
    printf("\nWhitespace tests:\n");
    printf("'  123' base 10: %d (expected: 123)\n", ft_atoi_base("  123", 10));
    printf("'\\t\\n 42' base 10: %d (expected: 42)\n", ft_atoi_base("\t\n 42", 10));
    
    // Invalid characters (should stop parsing)
    printf("\nInvalid character tests:\n");
    printf("'123xyz' base 10: %d (expected: 123)\n", ft_atoi_base("123xyz", 10));
    printf("'12G' base 16: %d (expected: 18)\n", ft_atoi_base("12G", 16));
    
    // Invalid bases
    printf("\nInvalid base tests:\n");
    printf("'123' base 1: %d (expected: 0)\n", ft_atoi_base("123", 1));
    printf("'123' base 17: %d (expected: 0)\n", ft_atoi_base("123", 17));
	return (0);
}
