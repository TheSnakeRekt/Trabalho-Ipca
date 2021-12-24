#pragma once

#include <stdio.h>
#include <malloc.h>

typedef struct Curso {
	char* string;
	char* nome;
	char* numero;

	int TYPE;

} Curso;

Curso* curso_create(char* nome, char* numero) {
	Curso* obj = (Curso*) malloc(sizeof(Curso));

	if (obj == NULL) {
		return NULL;
	}

	obj->TYPE = Curso_T;

	obj->nome = nome;
	obj->numero = numero;

	return obj;
}

char* serializeCurso(Curso* cu)
{
    size_t len = 0;
    len = snprintf(NULL, len, "%s,%s", cu->nome, cu->numero);

	cu->string = (char*) malloc(len);
	signed int totalB = snprintf(cu->string, len + 1, "%s,%s", cu->nome, cu->numero);

    if (totalB > len + 1)
    {
        printf("O Curso nao foi serializado.");
        return NULL;
    }

    return cu->string;
}