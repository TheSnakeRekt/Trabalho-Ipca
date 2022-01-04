#pragma once
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>

#include "../mapping/aluno_index_mapping.h"

char* getNomeIndex(char* aluno);
char* getNumeroIndex(char* aluno);
void getIndiceAndSizeIndex(char* aluno, long indexSize[]);

