#include "morada.h"

Morada* morada_create(char* rua, char* codPostal, char* localidade, int signed porta) {
	Morada* obj = (Morada*)malloc(sizeof(Morada));

	if (obj == NULL) {
		return NULL;
	}
	obj->TYPE = Morada_T;

	obj->codPostal = codPostal;
	obj->rua = rua;
	obj->porta = porta;
	obj->localidade = localidade;
	obj->string = "\0";

	return obj;
}

char* serializeMorada(Morada* mo)
{
	size_t len = 0;
	len = snprintf(NULL, len, "%s,%d,%s,%s", mo->rua, mo->porta, mo->codPostal, mo->localidade);

	mo->string = (char*)malloc(len);
	signed int totalB = snprintf(mo->string, len + 1, "%s,%d,%s,%s", mo->rua, mo->porta, mo->codPostal, mo->localidade);

	if (totalB > len + 1)
	{
		printf("A Morada nao foi serializada.");
		return NULL;
	}

	return mo->string;
}