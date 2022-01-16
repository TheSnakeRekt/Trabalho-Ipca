#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <sys/stat.h>
#include <string.h>

const enum FILENAMES {
	ALUNOS_INDEX_FILE_PATH = 0,
	ALUNOS_FILE_PATH = 1,
	CURSOS_FILE_PATH = 2,
	ALUNOS_CURSO_FILE_PATH = 3
};

const int STORAGE_LENGTH;
const char* STORAGE_NAME[4];


char* fullpath(int i);
FILE* open_file(const char* fileName);
int filehandle_init();
char* read_file(FILE* fp);
long count_lines(FILE* fp, long long bufferSize);
long write_file(char* buffer, FILE* fp);
char* readFromBufferPos(FILE* fp, long long rewindSize);
FILE* openw_file(const char* fileName);