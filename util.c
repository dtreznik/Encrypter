#include <stdio.h>
#include <stdlib.h>

void assert(int expression, const char* msg){
	if (expression == 0) {
		printf(msg);
		exit(EXIT_FAILURE);
	}
}

int hash(char* str, const int len) {
	const int p = 257;
	const int m = 1e9 + 9;

	int hash = 0;
	int ppower = 1;
	for (int i = 0; i < len; i++) {
		hash += (str[i] * ppower) % m;
		ppower = (ppower * p) % m;
	}
	return hash;
}

int reverseNum(unsigned int num) {
	unsigned int rev = 0;
	while (num > 0) {
		rev += num % 10;
		rev *= 10;
		num /= 10;
	}
	return rev / 10;
}
