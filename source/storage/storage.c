#include "storage.h"

FILE* open_file(const char* fileName) {
	return fopen(fileName, "a+");
}

int filehandle_init() {

	int i = 0;

	if (stat(BASE_DIR, &st) == -1) {
		CreateDirectoryA(BASE_DIR, NULL);
		filehandle_init();
	}
	for (i = 0; i < STORAGE_LENGTH; i++) {
		FILE* fp = fopen(STORAGE_NAME[i], "a+");

		if (!fp) {
			perror("fopen");
			continue;
		}
		fputs("", fp);
		fclose(fp);
	}

	return i;
}


char* read_file(FILE* fp) {
	char* buffer;

	fseek(fp, 0, SEEK_END);
	int lSize = ftell(fp);
	rewind(fp);

	buffer = (char*) malloc(sizeof(char) * lSize) + 1;
	fread(buffer, 1, lSize, fp);
	fclose(fp);

	return buffer;
}

int count_lines(FILE* fp) {
	char ch;
	int i = 0;
	while ((ch = fgetc(fp)) != EOF) {
		if (ch == '\n')
			i++;
	}

	return i;
}

int write_file(char* buffer, FILE* fp) {
	if (fwrite(buffer, strlen(buffer), 1, fp) >= 1) {
		rewind(fp);
		return count_lines(fp) - 1;
	}

	return -1;
}

