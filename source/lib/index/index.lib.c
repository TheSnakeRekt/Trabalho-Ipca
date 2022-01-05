#include "index.lib.h"

char* getNomeIndex(char* buffer) {
	int i = 0;
	int tLen = 0;
	int pos = 0;
	char* nome = NULL;

	for (i = 0; i < strlen(buffer); i++) {
		if (pos == Nome_Aluno_I) {
			int j = i + 1;
			while (buffer[j] != ';')
			{
				j++;
			}
			tLen = j - i;

			break;
		}
		else if (buffer[i] == ',') {
			pos++;
		}
	}

	nome = (char*) malloc(tLen + 1);

	sprintf(nome, "%.*s", tLen, &buffer[i]);

	return nome;
}

char* getNumeroIndex(char* buffer) {
	int i = 0;
	int tLen = 0;
	int pos = 0;
	char* numero = "\0";

	for (i = 0; i < strlen(buffer); i++) {
		if (pos == Aluno_Index_C) {
			int j = i + 1;
			while (buffer[j] != ',')
			{
				j++;
				if (strlen(buffer) < j) {
					return "\0";
				}
			}
			tLen = j - i;

			break;
		}
		else if (buffer[i] == ',') {
			pos++;
		}
	}

	numero = (char*)malloc(tLen + 1);

	sprintf(numero, "%.*s", tLen, &buffer[i]);

	return numero;
}

char* getNCursoIndex(char* buffer) {
	int i = 0;
	int tLen = 0;
	int pos = 0;
	char* nCurso;

	for (i = 0; i < strlen(buffer); i++) {
		if (pos == Curso_Numero_C - 1) {
			
			int j = i + 1;
			if (buffer[i] == ',') {
				break;
			}
			while (buffer[j] != ',')
			{
				j++;
			}
			tLen = j - i;

			break;
		}
		else if (buffer[i] == ',') {
			pos++;
		}
	}

	nCurso = (char*)malloc(tLen + 1);

	sprintf(nCurso, "%.*s", tLen, &buffer[i]);

	return nCurso;
}

char* getNMecaIndex(char* buffer) {
	int i = 0;
	int tLen = 0;
	int pos = 0;
	char* nMeca;

	for (i = 0; i < strlen(buffer); i++) {
		if (pos == N_Mecanografico_I) {
			int j = i + 1;
			while (buffer[j] != ';')
			{
				j++;
			}
			tLen = j - i;

			break;
		}
		else if (buffer[i] == ',') {
			pos++;
		}
	}

	nMeca = (char*)malloc(tLen + 1);

	sprintf(nMeca, "%.*s\n", tLen, &buffer[i]);

	return nMeca;
}

void getIndiceAndSizeIndex(char* aluno, long indexSize[]) {
	int i = 0;
	char* indice = NULL;

	for (i = 0; i < strlen(aluno); i++) {
		if (aluno[i] == ',') {
			break;
		}
	}

	indice = (char*) malloc(i + 1);

	sprintf(indice, "%.*s", i, aluno);

	for (int j = i; j > 0; j--) {
		if (indice[j] == '|') {
			char* temp = (char*)malloc(j + 1);
			sprintf(temp, "%.*s", j, indice);
			indexSize[0] = atoi(temp);

			sprintf(temp, "%.*s", i, &indice[j + 1]);
			indexSize[1] = atoi(temp);

			free(indice);
			break;
		}
	}
}