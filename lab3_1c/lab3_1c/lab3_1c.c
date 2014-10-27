/* File: lab3_1c.c */
/* Alexander Ustyuzhanin, IE SO1 group 1, WS14, 26.10.2014 */

#define _CRT_SECURE_NO_WARNINGS									// suppress warnings about unsafe scanf (C4996)
#include <stdio.h>										
#include <stdlib.h>

/* Test results for values 0, 1, 32767, -32767
1) value is 0
Enter an integer value: 0
Got value 0, HEX 0
Toggled LSB, result is 1, HEX 0x1
Toggle function returned 1, HEX 0x1

2) value is 1
Enter an integer value: 1
Got value 1, HEX 0x1
Toggled LSB, result is 0, HEX 0
Toggle function returned 0, HEX 0

3) value is 32767
Enter an integer value: 32767
Got value 32767, HEX 0x7fff
Toggled LSB, result is 32766, HEX 0x7ffe
Toggle function returned 32766, HEX 0x7ffe

4) value is -32767
Enter an integer value: -32767
Got value -32767, HEX 0x8001
Toggled LSB, result is -32768, HEX 0x8000
Toggle function returned -32768, HEX 0x8000
*/

short toggle_LSB(short value)
{
	short maskLSB = 0x1;
	short maskLSBSwap = 0xfffe;
	short lsb;

	lsb = value & maskLSB;
	if(0 == lsb)
		value = value | maskLSB;			// set LSB to 1
	else
		value = value & maskLSBSwap;		// set LSB to 0
	return value;
}

int main()
{
	short short_val_16bit;
	short maskLSB = 0x1;
	short maskLSBSwap = 0xfffe;
	short lsb;
	short funcResult;

	printf("Enter an integer value: ");
	fflush(stdin);
	scanf("%hi", &short_val_16bit);
	printf("Got value %hd, HEX %#hx\n", short_val_16bit, short_val_16bit);

	funcResult = toggle_LSB(short_val_16bit);
	lsb = short_val_16bit & maskLSB;
	if(0 == lsb)
		short_val_16bit = short_val_16bit | maskLSB;			// set LSB to 1
	else
		short_val_16bit = short_val_16bit & maskLSBSwap;		// set LSB to 0

	printf("Toggled LSB, result is %hd, HEX %#hx\n", short_val_16bit, short_val_16bit);
	printf("Toggle function returned %hd, HEX %#hx\n", funcResult, funcResult);

	system("pause");
	return 0;
}