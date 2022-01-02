#pragma once

#include <malloc.h>
#include <stdio.h>
#include "../../storage/storage.h"
#include "../types.h"

struct Curso;


typedef struct Curso {
	char* string;
	char* nome;
	char* numero;

	int TYPE;
} Curso;


Curso* curso_create(char* nome, char* numero);
char* serializeCurso(Curso* cu);
long saveCurso(Curso* self);