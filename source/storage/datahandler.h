#pragma once
#include "storage.h"
#include "../data_structures/types.h"
#include "../lib/mapping/aluno_mapping.h"
#include "../lib/index/index.lib.h"
#include "../lib/aluno/aluno.repo.lib.h"

char* findBy(int type, int prop, char* value);
int save(char* stream, char* type);
int mod(char type, char* old, char* mod);