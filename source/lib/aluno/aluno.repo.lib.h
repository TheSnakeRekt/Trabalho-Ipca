#pragma once
#include "aluno.lib.h"
#include "../algorithms/algorithms.lib.h"
#include "../../storage/storage.h"

char* select_aluno(int prop, char* value);
char* save_aluno(char* json);
char* mod_aluno(char* aluno);