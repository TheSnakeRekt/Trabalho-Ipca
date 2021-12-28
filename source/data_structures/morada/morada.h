#pragma once

#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include "../types.h"

typedef struct Morada {
	char* string;
	char* rua;
	char* codPostal;
	char* localidade;

	int TYPE;
	int signed porta;
} Morada;


Morada* morada_create(char* rua, char* codPostal, char* localidade, int signed porta);
char* serializeMorada(Morada* mo);