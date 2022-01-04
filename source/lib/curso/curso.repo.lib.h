#pragma once
#include "curso.lib.h"
#include "../algorithms/curso.algo.h"
#include "../../storage/storage.h"

char* select_curso(int prop, char* value);
char* save_curso(char* json);
char* mod_curso(char* curso);