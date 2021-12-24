#pragma once
#include <string.h>
#include <malloc.h>
#include "../mapping/aluno_mapping.h"

char* getNumeroMecanografico(char* aluno){
	int pos = 0;
	int i = 0;
	int tLen = 0;

	char* n_meca;

	for (i = 0; i < strlen(aluno); i++) {
		if (pos == N_Mecanografico_A) {
			int j = i + 1;
			while (aluno[j] != ',')
			{
				j++;
			}
			 tLen = j - i;

			break;
		}
		else if(aluno[i] == ',') {
			pos++;
		}
	}

	n_meca = (char*)malloc(tLen + 1);
	sprintf(n_meca, "%.*s\n", tLen, &aluno[i]);

	return n_meca;
}

char* getDataNascimento(char* aluno) {
	int pos = 0;
	int i = 0;
	int tLen = 0;

	char* dataNascimento;

	for (i = 0; i < strlen(aluno); i++) {
		if (pos == Data_Nascimento_A) {
			int j = i + 1;
			while (aluno[j] != ',')
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


	dataNascimento = (char*)malloc(tLen + 1);
	sprintf(dataNascimento, "%.*s\n", tLen, &aluno[i]);

	return dataNascimento;
}

char* getMorada(char* aluno) {
	int pos = 0;
	int start = 0;
	int lastValuePos = 0;
	int tLen = 0;

	char* morada;

	for (int i = 0; i < strlen(aluno); i++) {
		if (pos >= Morada_Rua_A && pos <= Morada_Localidade_A) {
			if (start == 0) {
				start = i;
			}

			int j = i + 1;
			while (aluno[j] != ',')
			{
				j++;
			}
			if (pos != Morada_Localidade_A) {
				aluno[j] = ' ';
			}
			lastValuePos = j;

			pos++;
			tLen = tLen + j - i + 1;
			i = lastValuePos;
		}else if (aluno[i] == ',') {
			pos++;
		}
		else if(pos > Morada_Localidade_A) {
			break;
		}
	}

	morada = (char*)malloc(tLen + 1);
	sprintf(morada, "%.*s\n", tLen - 1, &aluno[start]);
	

	return morada;
}

char* getCurso(char* aluno) {
	int pos = 0;
	int i = 0;
	int tLen = 0;

	char* curso;

	for (i = 0; i < strlen(aluno); i++) {
		if (pos == Curso_Sigla_A) {
			int j = i + 1;
			while (aluno[j] != ',')
			{
				j++;
			}
			aluno[j] = ' ';
			tLen = j - i + 1;

			break;
		}
		else if (aluno[i] == ',') {
			pos++;
		}
	}


	curso = (char*)malloc(tLen + 1);
	sprintf(curso, "%s\n", &aluno[i]);

	return curso;
}

char* getAlunoFromBuffer(char* buffer, int index) {
	int i = 0;
	int tLen = 0;
	int counter = 0;

	char* aluno;

	for (i = 0; i < strlen(buffer); i++) {
		if (buffer[i] == ';') {
			counter++;
		}
		if (counter == index) {
			int j = i;
			while (buffer[j] != ';')
			{
				j++;
			}
			tLen = j-i;
			break;
		}
	}

	aluno = (char*) malloc(tLen + 1);
	sprintf(aluno, "%.*s\n", tLen, &buffer[i]);

	return aluno;
}

