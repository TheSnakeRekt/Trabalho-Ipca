#pragma once
#include "storage.h"

struct stat st = {0};
const char* BASE_DIR = "C:\\projeto";

const char* ALUNOS_INDEX_FILE_PATH = "C:\\projeto\\alunos.index.storage";
const char* CURSO_INDEX_FILE_PATH = "C:\\projeto\\curso.index.storage";

const char* ALUNOS_FILE_PATH = "C:\\projeto\\alunos.storage";
const char* CURSOS_FILE_PATH = "C:\\projeto\\cursos.storage";
const char* MORADA_FILE_PATH = "C:\\projeto\\morada.storage";

const char* ALUNOS_CURSO_FILE_PATH = "C:\\projeto\\alunos_curso.storage";
const char* ALUNOS_MORADA_FILE_PATH = "C:\\projeto\\alunos_morada.storage";

const int STORAGE_LENGTH = 7;

const char* STORAGE_NAME[7] = {
	"C:\\projeto\\alunos.index.storage",
	"C:\\projeto\\curso.index.storage",
	"C:\\projeto\\alunos.storage",
	"C:\\projeto\\cursos.storage",
	"C:\\projeto\\morada.storage",
	"C:\\projeto\\alunos_curso.storage",
	"C:\\projeto\\alunos_morada.storage"
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

