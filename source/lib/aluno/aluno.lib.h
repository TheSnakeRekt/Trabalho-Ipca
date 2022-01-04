#pragma once
#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "../json/data_parser.h"
#include "../../data_structures/aluno/aluno.h"
#include "../mapping/aluno_mapping.h"



char* getNome(char* aluno);
char* getNumeroMecanografico(char* aluno);
char* getDataNascimento(char* aluno);
char* getMorada(char* aluno);
char* getCurso(char* aluno);
char* getAlunoFromBuffer(char* buffer, long index[]);
Aluno* fromJson(char* json);