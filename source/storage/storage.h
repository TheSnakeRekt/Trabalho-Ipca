#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <sys/stat.h>
#include <string.h>


struct stat st = { 0 };

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


FILE* open_file(const char* fileName);
int filehandle_init();
char* read_file(FILE* fp);
int count_lines(FILE* fp);
int write_file(char* buffer, FILE* fp);