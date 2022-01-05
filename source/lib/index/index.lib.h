#pragma once
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>

#include "../mapping/aluno_index_mapping.h"
#include "../mapping/aluno_curso_mapping.h"

char* getNomeIndex(char* buffer);
char* getNumeroIndex(char* buffer);
char* getNCursoIndex(char* buffer);
char* getNMecaIndex(char* buffer);
void getIndiceAndSizeIndex(char* aluno, long indexSize[]);

