#pragma once
#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "../json/data_parser.h"
#include "../../data_structures/aluno/aluno.h"
#include "../algorithms/aluno.algo.h"
#include "../mapping/aluno_mapping.h"



char* getNomeAluno(char* aluno);
char* getNumeroMecanograficoAluno(char* aluno);
char* getDataNascimentoAluno(char* aluno);
char* getMoradaAluno(char* aluno);
char* getCursoAluno(char* aluno);
char* getAlunoFromBuffer(char* buffer, long index[]);
Aluno* alunoFromJson(char* json);