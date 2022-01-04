#pragma once
#include "../data_structures/types.h"
#include "../lib/mapping/curso_mapping.h"
#include "../lib/curso/curso.repo.lib.h"
#include "../lib/json/data_parser.h"

char* update_curso(char* data);
char* find_curso(char* data);
char* insert_curso(char* value);
char* delete_curso(char* value);