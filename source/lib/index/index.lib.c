#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>

#include "../mapping/aluno_index_mapping.h"

char* getNomeIndex(char* aluno) {
	int i = 0;
	int tLen = 0;
	int pos = 0;
	char* nome;

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

	nome = (char*)malloc(tLen + 1);

	sprintf(nome, "%.*s\n", tLen, &aluno[i]);

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

int getIndiceIndex(char* aluno) {
	int i = 0;
	char* indice;

	for (i = 0; i < strlen(aluno); i++) {
		if (aluno[i] == ',') {
			break;
		}
	}

	indice = (char*)malloc(i + 1);

	sprintf(indice, "%.*s\n", i, aluno);

	return atoi(indice);
}