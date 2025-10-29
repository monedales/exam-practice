/*
Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a function that prints the binary representation of a byte (8 bits).

void print_bits(unsigned char octet);

Example:
- print_bits(2) should print "00000010"
*/
#include <unistd.h>
void print_bits(unsigned char octet)
{
    int i = 7;
    while (i >= 0)
    {
        if (octet & (1 << i))
            write(1, "1", 1);
        else
            write(1, "0", 1);
        i--;
    }
}