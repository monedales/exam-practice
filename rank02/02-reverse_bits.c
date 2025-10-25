/*
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
	unsigned int i;
	unsigned char res = 0; // our result accumulator

	i = 8; //loop counter for 8 bits
	while (i--) //decrementa o i depois de checar seu valor
	{
		res = (res << 1) | (octet & 1);
		octet = octet >> 1;
	}
	return (res);
}
// If you want to test the code:
int	main(void)
{
	unsigned char bit = 0;
	// by changing the number on the next line, you change
	// the bits that are sent to the reverse_bits function
	// 5 => 0000 0101, the result should be 1010 0000
	unsigned char res = reverse_bits((unsigned char)5);

	int i = 8;
	
	while (i--)
	{
		bit = (res >> i & 1) + 48;
		printf("%c", bit);
	}
}
/*
Bitwise Operations: This function showcases three essential bitwise operators: 
AND (&) for extraction, OR (|) for combination, and bit shifts (<<, >>) for positioning.
Accumulator Pattern: The res variable accumulates the final result bit by bit, which
 is a fundamental programming technique for building complex values incrementally.
Potential Gotchas
One subtle aspect is that the function modifies the octet parameter during processing. 
Since C passes parameters by value, this doesn't affect the original variable in the 
calling code, but beginners might find this modification confusing.
The post-decrement in while (i--) can also be tricky - the loop condition uses the current 
value of i, then decrements it. This means when i starts at 8, the first iteration sees 
i as 8 (truthy), then i becomes 7 for the next iteration.
*/