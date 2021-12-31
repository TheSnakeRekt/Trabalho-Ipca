#pragma once
#include <string.h>
#include <malloc.h>
#include <stdio.h>

#include "../../data_structures/aluno/aluno.h"
#include "../../storage/storage.h"
#include "../mapping/aluno_mapping.h"


char* getNome(char* aluno);
char* getNumeroMecanografico(char* aluno);
char* getDataNascimento(char* aluno);
char* getMorada(char* aluno);
char* getCurso(char* aluno);
char* getAlunoFromBuffer(char* buffer, int index);
Aluno* fromJson(char* json);