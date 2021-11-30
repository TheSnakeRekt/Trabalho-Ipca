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
	
		for (i = 0; i < STORAGE_LENGTH; i++) {
			FILE* fp = fopen(STORAGE_NAME[i], "w");

			if (fp != NULL) {
				fputs("\n", fp);
				fclose(fp);
			}
		}
	}


	return i;
}

