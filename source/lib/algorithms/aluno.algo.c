#include "aluno.algo.h"

char* alunosByName(char* value) {
	char* alunosFound = NULL;
	

	FILE* alunos = open_file(ALUNOS_INDEX_FILE_PATH);
	char* file = read_file(alunos);

	long index[2];

	int counter = 0;
	int i = 0;
	int pos = 0;

	for (i = 0; i < strlen(file); i++) {
		char* alunoBuffer = NULL;

		int j = i;
		while (file[j] != ';')
		{
			j++;
		}
		
		int len = j - i;

		alunoBuffer = (char*)malloc(len + 1);
		sprintf(alunoBuffer, "%.*s;", len, &file[i]);
		
		char* alunoEncontrado = getNomeIndex(alunoBuffer);
		char* found = strstr(alunoEncontrado, value);

		if (found != NULL && strlen(found) > strlen(value) && alunoEncontrado != "\0") {

			free(found);
			found = NULL;

			getIndiceAndSizeIndex(alunoBuffer, index);
			alunos = open_file(ALUNOS_FILE_PATH);

			
			char* fileFromPos = readFromBufferPos(alunos, index[0]);
			
			
			long size = index[1] - index[0];
			if (alunosFound == NULL) {
				alunosFound = (char*)malloc(size + 1);
				alunosFound = getAlunoFromBuffer(fileFromPos, size);
			}
			else {
				alunosFound = (char*) realloc(alunosFound,strlen(alunosFound) + size + 1);
				alunosFound = strcat(alunosFound, getAlunoFromBuffer(fileFromPos, size));
			}
			
			free(fileFromPos);
			
			
		}
		i = j + 1;
	}

	return alunosFound;
}

char* alunoByNumero(char* value) {
	char* alunoEncontrado = "\0";

	FILE* alunos = open_file(ALUNOS_INDEX_FILE_PATH);
	char* file = read_file(alunos);

	int counter = 0;
	long index[2];

	for (int i = 0; i < strlen(file); i++) {
		char* alunoBuffer = NULL;

		int j = i;
		while (file[j] != ';')
		{
			j++;
		}

		int len = j - i;

		alunoBuffer = (char*)malloc(len + 1);
		sprintf(alunoBuffer, "%.*s;", len, &file[i]);
		char* numeroEncontrado = getNumeroIndex(alunoBuffer);

		if (strcmp(numeroEncontrado, value)) {

			getIndiceAndSizeIndex(alunoBuffer, index);

			alunos = open_file(ALUNOS_FILE_PATH);

			char* fileFromPos = readFromBufferPos(alunos, index[0]);


			long size = index[1] - index[0];
			alunoEncontrado = getAlunoFromBuffer(fileFromPos, index);
			break;
		}
	}

	return alunoEncontrado;
}

char* alunosByCurso(char* value) {
	char* alunoEncontrado = NULL;

	FILE* alunos = open_file(ALUNOS_CURSO_FILE_PATH);
	char* file = read_file(alunos);

	int counter = 0;
	long index[2] = { 0 };

	for (int i = 0; i < strlen(file); i++) {
		char* alunoBuffer = "\0";

		if (file[i] == ';') {
			alunoEncontrado = getNumeroIndex(alunoBuffer);
		}
		else {
			strcat_s(alunoBuffer, strlen(alunoBuffer), file[i]);
		}

		strcat_s(alunoBuffer, strlen(alunoBuffer), "\0");

		if (strcmp(alunoBuffer, value)) {

			getIndiceAndSizeIndex(alunoBuffer, index);

			alunos = open_file(ALUNOS_FILE_PATH);

			char* fileFromPos = readFromBufferPos(alunos, index[0]);


			long size = index[1] - index[0];
			alunoEncontrado = getAlunoFromBuffer(fileFromPos, index);
			break;
		}
	}

	alunos = open_file(ALUNOS_FILE_PATH);

	file = read_file(alunos);

	return alunoEncontrado;
}

char* allAlunos() {
	FILE* alunos = open_file(ALUNOS_FILE_PATH);
	char* allAlunos = read_file(alunos);

	return allAlunos;
}