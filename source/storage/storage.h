#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <sys/stat.h>
#include <string.h>


struct stat st;

const char* BASE_DIR;

const char* ALUNOS_INDEX_FILE_PATH;

const char* ALUNOS_FILE_PATH;
const char* CURSOS_FILE_PATH;

const char* ALUNOS_CURSO_FILE_PATH;

const int STORAGE_LENGTH;

const char* STORAGE_NAME[4];


FILE* open_file(const char* fileName);
int filehandle_init();
char* read_file(FILE* fp);
long count_lines(FILE* fp, long long bufferSize);
long write_file(char* buffer, FILE* fp);
char* readFromBufferPos(FILE* fp, long long rewindSize);
FILE* openw_file(const char* fileName);