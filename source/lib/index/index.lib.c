#include "index.lib.h"

char* getNomeIndex(char* aluno) {
	int i = 0;
	int tLen = 0;
	int pos = 0;
	char* nome = NULL;

	for (i = 0; i < strlen(aluno); i++) {
		if (pos == Nome_Aluno_I) {
			int j = i + 1;
			while (aluno[j] != ';')
			{
				j++;
			}
			tLen = j - i;

			break;
		}
		else if (aluno[i] == ',') {
			pos++;
		}
	}

	nome = (char*) malloc(tLen + 1);

	sprintf(nome, "%.*s", tLen, &aluno[i]);

	return nome;
}

char* getNumeroIndex(char* aluno) {
	int i = 0;
	int tLen = 0;
	int pos = 0;
	char* nome;

	for (i = 0; i < strlen(aluno); i++) {
		if (pos == N_Mecanografico_I) {
			int j = i + 1;
			while (aluno[j] != ';')
			{
				j++;
			}
			tLen = j - i;

			break;
		}
		else if (aluno[i] == ',') {
			pos++;
		}
	}

	nome = (char*)malloc(tLen + 1);

	sprintf(nome, "%.*s\n", tLen, &aluno[i]);

	return nome;
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