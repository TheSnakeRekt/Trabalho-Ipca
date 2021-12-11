#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct Data;

typedef void* (*set)(struct Data* self, signed int dia, signed int mes, signed int ano);

typedef struct Data {

	char* string;

	signed int dia, mes, ano;

	set set;
}Data;

void toString(Data* self) {

	size_t len = 0;

	len = snprintf(NULL, len, "%d/%d/%d", self->dia, self->mes, self->ano);

	char* temp = malloc(len);

	snprintf(temp, len + 1, "%d/%d/%d", self->dia, self->mes, self->ano);

	self->string = temp;

}

void* setData(Data* self, signed int dia, signed int mes, signed int ano) {
	self->dia = dia;
	self->mes = mes;
	self->ano = ano;
	toString(self);
}

Data* data_create() {
	Data* obj = (Data*)malloc(sizeof(Data));

	if (obj == NULL) {
		return NULL;
	}

	obj->set = setData;

	return obj;
}

char* serialize(Data dat) {

	size_t len = 0;
	len = snprintf(NULL, len, "%d/%d/%d", dat.dia, dat.mes, dat.ano);

	char* apstr = "\0";

	if (snprintf(apstr, len + 1, "%d/%d/%d", dat.dia, dat.mes, dat.ano) > len + 1) {

		printf("A Data nao foi serializado.");
		return NULL;
	}
	return apstr;
}