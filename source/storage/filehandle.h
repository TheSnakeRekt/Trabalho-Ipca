#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <sys/stat.h>
#include "storage.h"


FILE* open_file(char* fileName) {
	return fopen(fileName, "a");
}

struct stat st = { 0 };

int filehandle_init() {

	int i = 0;

	if (stat(BASE_DIR, &st) == -1) {
		CreateDirectoryA(BASE_DIR, NULL);
		filehandle_init();
	}
	for (i = 0; i < STORAGE_LENGTH; i++) {
		FILE* fp = fopen(STORAGE_NAME[i], "w+");

		if (!fp) {
			perror("fopen");
			continue;
		}
		fputs("\n", fp);
		fclose(fp);
	}

	return i;
}


char* read_file(FILE* fp) {
	char* buffer;

	fseek(fp, 0, SEEK_END);
	int lSize = ftell(fp);
	rewind(fp);

	buffer = (char*)malloc(sizeof(char) * lSize);
	fread(buffer, 1, lSize, fp);

	return buffer;
}

int write_file(char* buffer, FILE* fp) {
	return fwrite(buffer, sizeof(buffer), 1 ,fp);
}
