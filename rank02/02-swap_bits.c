/*
Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100
*/
void	print_bits(unsigned char octet);
unsigned char	swap_bits(unsigned char octet)
{
	return ((octet << 4 | octet >> 4));
}
int main(void)
{
	// unsigned char octet = 2;
	print_bits(2);
	swap_bits(2);
	print_bits(2);
	return (0);
}