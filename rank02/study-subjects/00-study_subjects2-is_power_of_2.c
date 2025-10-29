/*
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a function that determines if a given number is a power of 2.
It returns 1 if true, 0 otherwise.

int is_power_of_2(unsigned int n);

Examples:
- is_power_of_2(1) = 1
- is_power_of_2(2) = 1
- is_power_of_2(3) = 0
- is_power_of_2(4) = 1
*/
int is_power_of_2(unsigned int n)
{
    if (n == 0)
        return (0);
    unsigned int num = 1;
    while (num < n)
        num = num * 2;
    
    return (num == n);
}