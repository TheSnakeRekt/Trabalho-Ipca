#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <sys/stat.h>
#include <string.h>


struct stat st;

const char* BASE_DIR;

const char* ALUNOS_INDEX_FILE_PATH;
const char* CURSO_INDEX_FILE_PATH;

const char* ALUNOS_FILE_PATH;
const char* CURSOS_FILE_PATH;
const char* MORADA_FILE_PATH;

const char* ALUNOS_CURSO_FILE_PATH;
const char* ALUNOS_MORADA_FILE_PATH;

const int STORAGE_LENGTH;

const char* STORAGE_NAME[7];


FILE* open_file(const char* fileName);
int filehandle_init();
char* read_file(FILE* fp);
int count_lines(FILE* fp);
int write_file(char* buffer, FILE* fp);