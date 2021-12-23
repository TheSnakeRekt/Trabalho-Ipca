#pragma once

#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include "types.h"

struct Morada;
typedef void*  (*set)(struct Morada* self, char* rua, char* codPostal, int signed porta);


typedef struct Morada {
	char* string;
	char* rua;
	char* codPostal;
	int signed porta;

	set set;
} Morada;



void toString(Morada* self) {
	size_t len = 0;
	len = snprintf(NULL, len, "%s %d %s", self->rua, self->porta, self->codPostal);
	
	
	sprintf(self->string, "%s %d %s", self->rua, self->porta, self->codPostal);
}

void* setData(Morada* self, char* rua, char* codPostal, int signed porta) {
	self->codPostal = codPostal;
	self->rua = rua;
	self->porta = porta;
	toString(self);
}

Morada* morada_create() {
	Morada *obj = (Morada*) malloc(sizeof(Morada));

	if (obj == NULL) {
		return NULL;
	}

	obj->set = setData;

	return obj;
}

char* serializeMorada(Morada mo)
{
	size_t len = 0;
	len = snprintf(NULL, len, "%s,%d,%s", mo.rua, mo.porta, mo.codPostal);

	char* apstr = '\0';
	signed int lenS = len + 1;

	if (snprintf(apstr, len + 1, "%s,%d,%s", mo.rua, mo.porta, mo.codPostal) > lenS)
	{
		printf("A Morada nao foi serializada.");
		return NULL;
	}

	return apstr;
}