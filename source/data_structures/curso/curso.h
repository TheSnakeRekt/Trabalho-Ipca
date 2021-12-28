#pragma once

#include <malloc.h>
#include <stdio.h>
#include "../types.h"

typedef struct Curso {
	char* string;
	char* nome;
	char* numero;

	int TYPE;

} Curso;


Curso* curso_create(char* nome, char* numero);
char* serializeCurso(Curso* cu);
