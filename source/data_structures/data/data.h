#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "../types.h"

typedef struct Data {
	char* string;

	signed int TYPE, dia, mes, ano;
} Data;

Data* data_create(signed int dia, signed int mes, signed int ano);
char* serializeData(Data* dat);
