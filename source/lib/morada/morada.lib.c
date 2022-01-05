#include "morada.lib.h"


Morada* moradaFromBuffer(char* buffer) {
	int pos = 0;
	int start = 0;
	int lastValuePos = 0;
	int tLen = 0;

	char* rua = "\0";
	char* codPostal = "\0";
	char* localidade = "\0";
	char* tmp = "\0";
	int porta = -1;

	for (int i = 0; i < strlen(buffer); i++) {
		if (pos >= Morada_Rua_A && pos <= Morada_Localidade_A) {

			int j = i + 1;
			while (buffer[j] != ',')
			{
				j++;
				if (strlen(buffer) < j) {
					return NULL;
				}
			}
			if (pos != Morada_Localidade_A) {
				buffer[j] = ' ';
			}

			tLen = j - i + 1;
			switch (pos){
				case Morada_Rua_A:
					rua = malloc(tLen);
					sprintf(rua, "%.*s", tLen - 1, &buffer[i]);
					break;
				case Morada_Numero_A:
					tmp = (char *) malloc(tLen);
					sprintf(tmp, "%.*s", tLen - 1, &buffer[i]);
					porta = atoi(tmp);
					break;
				case Morada_Cod_Postal_A:
					codPostal = malloc(tLen);
					sprintf(codPostal, "%.*s", tLen - 1, &buffer[i]);
					break;
				case Morada_Localidade_A:
					localidade = malloc(tLen);
					sprintf(localidade, "%.*s", tLen - 1, &buffer[i]);
					break;
				default:
					break;
			}

			pos++;
			i = j;
			if (pos > Morada_Localidade_A) {
				break;
			}
		} else if (buffer[i] == ',') {
			pos++;
		}
	}

	if (porta < 0) {
		return NULL;
	}
	return morada_create(rua, codPostal, localidade, porta);
}