#pragma once
#include "storage.h"

struct stat st = {0};
const char* BASE_DIR = "C:\\projeto";

const char* ALUNOS_INDEX_FILE_PATH = "C:\\projeto\\alunos.index.storage";
const char* CURSO_INDEX_FILE_PATH = "C:\\projeto\\curso.index.storage";

const char* ALUNOS_FILE_PATH = "C:\\projeto\\alunos.storage";
const char* CURSOS_FILE_PATH = "C:\\projeto\\cursos.storage";

const char* ALUNOS_CURSO_FILE_PATH = "C:\\projeto\\alunos_curso.storage";

const int STORAGE_LENGTH = 5;

const char* STORAGE_NAME[5] = {
	"C:\\projeto\\alunos.index.storage",
	"C:\\projeto\\curso.index.storage",
	"C:\\projeto\\alunos.storage",
	"C:\\projeto\\cursos.storage",
	"C:\\projeto\\alunos_curso.storage",
};

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

long count_lines(FILE* fp, long long rewindSize) {
	long long pos = -rewindSize;
	fseek(fp, pos, SEEK_END);
	return ftell(fp);
}

long write_file(char* buffer, FILE* fp) {
	long long bufferLen = strlen(buffer);

	if (fwrite(buffer, bufferLen, 1, fp) >= 1) {
		rewind(fp);
		return count_lines(fp, bufferLen) - 1;
	}

	return -1;
}

