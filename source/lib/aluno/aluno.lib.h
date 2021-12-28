#pragma once
#include <string.h>
#include <malloc.h>
#include <stdio.h>

#include "../../storage/storage.h"
#include "../mapping/aluno_mapping.h"


char* getNome(char* aluno);
char* getNumeroMecanografico(char* aluno);
char* getDataNascimento(char* aluno);
char* getMorada(char* aluno);
char* getCurso(char* aluno);
char* getAlunoFromBuffer(char* buffer, int index);