#pragma once
#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "../json/data_parser.h"
#include "../../data_structures/curso/curso.h"
#include "../mapping/curso_mapping.h"

char* getCursoName(char* value);
char* getCursoNumero(char* value);
Curso* cursoFromJson(char* json);