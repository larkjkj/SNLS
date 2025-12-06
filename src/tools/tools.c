#include <stdio.h>
#include "types.h"

extern u16 convertBEtoLE16(u16 address) {
	unsigned x = ((u8) (address));
	unsigned y = ((u8) (address >> 8));
	return (y << 8 | x);
}

extern u8 returnBank(size_t byteSize) {
	u8 x = ((byteSize)) / 32768;
	return x;
}

//extern char decimalToHEX(int decNumb) {
/* the fuck was this? */
/*	char recNumb;
	char hexMap[6] = {
		'A', 'B', 'C', 'D', 'E', 'F'
	};

	while (decNumb | 16 == 1) {
		decNumb /= 16;
		recNumb = ((decNumb % 16) << 8);

		//u8 recNumb = (decNumb %= 16);

		printf("%i => %c\n", decNumb, recNumb);
	}
*/
//	return printf("%X", decNumb);


