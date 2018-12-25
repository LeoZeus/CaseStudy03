#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
#include <iostream>


void printIP(unsigned char ip[]);
uint32_t convertBinary(unsigned char ip[]);
void convertToIP(unsigned char ip[], const uint32_t &n);
void inputIP(unsigned char ip[]);

bool isConnected()




int main()
{
	unsigned char ip_in[4] = { 0 };
	unsigned char ip_out[4] = { 0 };
	inputIP(ip_in);

	__int32 result = convertBinary(ip_in);
	printf("a. The result after convert: %u \n", result);

	convertToIP(ip_out, result);
	printf("b. The ip after reconvert: \n");
	printIP(ip_out);

	system("pause");
	return 0;
}

void inputIP(unsigned char ip[])
{
	printf("Enter Your IP. Follow 4 step \n");
	for (int i = 0; i < 4; ++i)
	{
		int a = 0;
		printf("Block %u (<256): ", i + 1); 
		scanf("%hhu" ,&ip[i]);
	}
}

uint32_t convertBinary(unsigned char ip[])
{
	uint32_t n = 0;

	for (int i = 0; i < 3; ++i)
		n = (n | ip[i]) << 8;
	n = n | ip[3];

	return n;

}

void convertToIP(unsigned char ip[], const uint32_t &n)
{
	uint32_t temp = n;

	for (int i = 0; i <4; ++i)
	{
		ip[i] = temp >> 8 * 3;
		temp = temp << 8;
	}
}

void printIP(unsigned char ip[])
{
	for (int i = 0; i < 3; ++i)
		printf("%u.", ip[i]);
	printf("%u\n", ip[3]);

}
