/****************************************************************
* Conversion between Gray Code and Binary, also providing examples
  of c bitwise functions and of returning arrays from functions  
* Author: pasa@mercantec.dk
* Revision 0 - 26-jun-2012 
*****************************************************************/

#include <stdio.h>

/*
        The purpose of this function is to convert an unsigned
        binary number to reflected binary Gray code.
*/
unsigned int binaryToGray(unsigned int num)
{
    return (num >> 1) ^ num;
}
 
/*
        The purpose of this function is to convert a reflected binary
        Gray code number to a binary number.
*/
unsigned int grayToBinary(unsigned int num)
{
    unsigned int numBits = 8 * sizeof(num);
    unsigned int shift;
    for (shift = 1; shift < numBits; shift *= 2)
    {
        num ^= num >> shift;
    }
    return num;
}

/*
        The purpose of this function is to convert a binary
        number to its "ones complement" i.e. to flip every bit.
*/

unsigned int onesComplement(unsigned int num)
{
	num = ~num;
	
	return num;
}

/*
        The purpose of this function is to convert a binary
        number to its "twos complement" i.e. to flip every bit and then add one.
		Twos complement binary numbers represent the negative of the original
		binary number and are therefore a convenient and efficient way to store
		and do arithmetic with binary numbers.
*/

unsigned int twosComplement(unsigned int num)
{
	num = ~num + 1;
	
	return num;
}

char *intToBin(unsigned int num)
{
	// make a static char array that will persist when function returns
	static char b[7];
	char *p = b;
	int x = 128;
		
	while(x)
	{
		//compare next bit position in num, using and(&)
		//with a string of zeros and a 1 in the positon of interest 
		*p++ = x & num ? '1' : '0';
		//shift the "1" one place to the right
		x >>= 1;
	}
	return b;
}

int main ()
{
	unsigned int i = 0;
	
	while (i < 256)
	{
		printf ("%s%d\t", "Decimal: ", i);
		printf ("%s%s\t", "Binary: ", intToBin(i));
		printf ("%s%s\t", "Gray: ", intToBin(binaryToGray(i)));
		printf ("%s%s\t", "Ones: ", intToBin(onesComplement(i)));
		printf ("%s%s\t", "Twos: ", intToBin(twosComplement(i)));
		printf ("%s%s\n", "Add (Binary and Twos): ", intToBin(i + twosComplement(i)));
		i++;
	}
}

