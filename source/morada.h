#pragma once
#include <malloc.h>
#include <stdio.h>
#include <string.h>

struct Morada;
typedef void*  (*set)(struct Morada* self, char* rua, char* codPostal, int signed porta);


typedef struct Morada {
	char* string;
	char* rua;
	char* codPostal; 
	const char* TYPE = "Morada";
	int signed porta;

	set set;
} Morada;



void toString(Morada* self) {
	size_t len = 0;
	len = snprintf(NULL, len, "%s %d $s", self->rua, self->porta, self->codPostal);
	
	
	sprintf_s(self->string, len + 1, "%s %d %s", self->rua, self->porta, self->codPostal);
}

Morada* setData(Morada* self, char* rua, char* codPostal, int signed porta) {
	self->codPostal = codPostal;
	self->rua = rua;
	self->porta = porta;
	toString(self);

	return self;
}

Morada* morada_create() {
	Morada *obj = (Morada*) malloc(sizeof(Morada));

	if (obj == NULL) {
		return morada_create();
	}

	obj->set = setData;

	return obj;
}

char* serialize(Morada mo)
{
	size_t len = 0;
	len = snprintf(NULL, len, "%s,%d,$s", mo.rua, mo.porta, mo.codPostal);

	char* apstr;

	if (snprintf(apstr, len + 1, "%s,%d,$s", mo.rua, mo.porta, mo.codPostal) > len + 1)
	{
		printf("A Morada nao foi serializado.");
		return NULL;
	}

	return apstr;
}