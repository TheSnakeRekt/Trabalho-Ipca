#pragma once
#include <string.h>
#include <malloc.h>
#include "../mapping/aluno_mapping.h"

char* getNumeroMecanografico(char* aluno) {
	int pos = 0;
	int len = 0;
	char* n_meca;

	for (int i = 0; i < strlen(aluno); i++) {
		if (pos == N_Mecanografico_A) {
			int j = i + 1;
			while (aluno[j] != ',')
			{
				j++;
			}
			int len = j - i;


			n_meca = (char*) malloc(len + 1);
			sprintf(n_meca, "%.*s\n", len, &aluno[i]);

			break;
		}
		else if(aluno[i] == ',') {
			pos++;
		}
	}

	return n_meca;
}

char* getAlunoFromBuffer(char* buffer, int index) {
	char* aluno;
	int counter = 0;

	for (int i = 0; i < strlen(buffer); i++) {
		if (buffer[i] == ';') {
			counter++;
		}
		if (counter == index) {
			int j = i;
			while (buffer[j] != ';')
			{
				j++;
			}
			int len = j-i;

			aluno = (char*) malloc(len + 1) ;
			sprintf(aluno, "%.*s\n", len, &buffer[i]);

			break;
		}
	}

	return aluno;
}