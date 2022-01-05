#pragma once
#include "../data_structures/types.h"
#include "../lib/mapping/aluno_mapping.h"
#include "../lib/aluno/aluno.repo.lib.h"
#include "../lib/json/data_parser.h"
#include "../common/domain.interop.mapper.h"

char* update_aluno(char* data);
char* find_aluno(char* data);
char* insert_aluno(char* value);
char* remove_aluno(char* data);