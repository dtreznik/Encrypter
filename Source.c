#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "util.h"

int main(int argc, char * argv[]) {
	assert(argc == 4, "Invalid arguments provided ([PATH] [KEY] [MODE (E or D)]");
	char* fileName = argv[1];
	FILE* filePointer = fopen(fileName, "r");
	assert(filePointer != NULL, "could not open file");
	
	fseek(filePointer, 0, SEEK_END);
	int fileLen = ftell(filePointer);
	rewind(filePointer);

	char* fileContent = (char*)malloc(fileLen * sizeof(char));
	fread(fileContent, sizeof(char), fileLen, filePointer);

	const char* key = argv[2];
	const unsigned int hashedKey = hash(key, strlen(key));
	
	bool enc = (argv[3][0] == 'E');
	if (enc) {
		printf("Encrypting...");
		for (int i = 0; i < fileLen; i++) {
			int temp = hashedKey;
			while (temp > 0) {
				fileContent[i] ^= (((temp % 10) << 4) | (temp % 10));
				temp = temp / 10;
			}
		}
		freopen(fileName, "w", filePointer);
		fwrite(fileContent, sizeof(char), fileLen, filePointer);
		
		printf("Done");
	}
	else {
		printf("Decrypting...");
		const unsigned int hashRev = reverseNum(hashedKey);
		for (int i = 0; i < fileLen; i++) {
			int temp = hashRev;
			while (temp > 0) {
				fileContent[i] ^= (((temp % 10) << 4) | (temp % 10));
				temp = temp / 10;
			}
		}
		freopen(fileName, "w", filePointer);
		fwrite(fileContent, sizeof(char), fileLen, filePointer);
		printf("Done");
	}
	fclose(filePointer);
	free(fileContent);
	return 0;
}
