#pragma once
#include <stdio.h>
#include <malloc.h>

struct Curso;
typedef void* (*set)(struct Curso* self, char* nome, char* numero);

typedef struct Curso {
	char* nome;
	char* numero;
	const char* TYPE = "Curso";

	set set;
} Curso;


Curso* setData(Curso* self, char* nome, char* numero) {
	self->nome = nome;
	self->numero = numero;


	return self;
}

Curso* curso_create() {
	Curso* obj = (Curso*) malloc(sizeof(Curso));

	if (obj == NULL) {
		return curso_create();
	}
	obj->set = setData;

	return obj;
}

char* serialize(Curso cu)
{
    size_t len = 0;
    len = snprintf(NULL, len, "%s,%s", cu.nome, cu.numero);

    char* apstr;

    if (snprintf(apstr, len + 1, "%s,%s", cu.nome, cu.numero) > len + 1)
    {
        printf("O Curso nao foi serializado.");
        return NULL;
    }

    return apstr;
}