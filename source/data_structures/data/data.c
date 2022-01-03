#include "data.h"


Data* data_create(signed int dia, signed int mes, signed int ano) {
	Data* obj = (Data*)malloc(sizeof(Data));

	if (obj == NULL) {
		return NULL;
	}

	obj->TYPE = Data_T;

	obj->dia = dia;
	obj->mes = mes;
	obj->ano = ano;
	obj->string = "\0";
	serializeData(obj);

	return obj;
}

char* serializeData(Data* dat) {

	size_t len = 0;
	len = snprintf(NULL, len, "%d/%d/%d", dat->dia, dat->mes, dat->ano);

	dat->string = (char*)malloc(len);
	int signed totalB = snprintf(dat->string, len + 1, "%d/%d/%d", dat->dia, dat->mes, dat->ano);

	if (totalB > len + 1) {

		printf("A Data nao foi serializado.");
		return NULL;
	}
	return dat->string;
}