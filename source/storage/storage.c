#pragma once
#include "storage.h"


const int STORAGE_LENGTH = 4;

const char* STORAGE_NAME[4] = {
	".\\dist\\backend\\alunos.index.storage",
	".\\dist\\backend\\alunos.storage",
	".\\dist\\backend\\cursos.storage",
	".\\dist\\backend\\alunos_curso.storage",
};

FILE* open_file(const char* fileName) {
	return fopen(fileName, "a+");
}

FILE* openw_file(const char* fileName) {
	return fopen(fileName, "w+");
}

char* fullpath(int i) {
	DWORD len = GetFullPathNameA(STORAGE_NAME[i], NULL, NULL, NULL);
	char* pathBuffer = (char *) malloc (len);
	GetFullPathNameA(STORAGE_NAME[i], len, pathBuffer, NULL);
	return pathBuffer;
}

int filehandle_init() {

	int i = 0;

	for (i = 0; i < STORAGE_LENGTH; i++) {

		FILE* fp = fopen(fullpath(i), "a+");
	
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
	char* buffer = NULL;

	if (fseek(fp, 0L, SEEK_END) == 0) {
		long bufsize = ftell(fp);

		if (bufsize == -1) { 
			perror("Error reading file"); 
		}

		buffer = malloc(sizeof(char) * (bufsize + 1));

		
		if (fseek(fp, 0L, SEEK_SET) != 0) { 
			perror("Error reading file");
		}

		size_t newLen = fread(buffer, sizeof(char), bufsize, fp);
		if (ferror(fp) != 0) {
			perror("Error reading file");
		}
		else {
			buffer[newLen++] = '\0'; 
		}
	}
	fclose(fp);

	return buffer;
}

long count_lines(FILE* fp, long long rewindSize) {
	long long pos = -rewindSize;

	fseek(fp, pos, SEEK_END);
	return ftell(fp);
}

char* readFromBufferPos(FILE* fp, long long rewindSize) {
	if (rewindSize == 0) {
		return read_file(fp);
	}
	char* buffer = NULL;

	if (fseek(fp, rewindSize, SEEK_SET) == 0) {
		long bufsize = ftell(fp);
		if (bufsize == -1) {
			perror("Error reading file");
		}

		buffer = malloc(sizeof(char) * (bufsize + 1));

		size_t newLen = fread(buffer, sizeof(char), bufsize, fp);
		if (ferror(fp) != 0) {
			perror("Error reading file");
		}
		else {
			buffer[newLen++] = '\0';
		}
	}
	fclose(fp);

	return buffer;
}

long write_file(char* buffer, FILE* fp) {
	long long bufferLen = strlen(buffer);
	
	if (fwrite(buffer, bufferLen, 1, fp) >= 1) {
		rewind(fp);
		return count_lines(fp, bufferLen + 1);
	}

	return -1;
}

