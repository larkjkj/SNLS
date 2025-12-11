#include <stdio.h>
#include <stdlib.h>
#include "vars/memory.h"
#include "types.h"

extern u16 U16convertBEtoLE(u16 address) {
	unsigned x = ((u8) (address));
	unsigned y = ((u8) (address >> 8));
	return (y << 8 | x);
}

extern u8 returnBank(size_t byteSize) {
	u8 x = ((byteSize)) / 32768;
	return x;
}

extern void populateBuffer(u8** buffer, unsigned int count, unsigned int size) {
	for(unsigned int j = 0; j < count; j ++) {
		buffer[j] = malloc(sizeof(size));
	}
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


