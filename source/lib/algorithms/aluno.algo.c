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
	char* alunoEncontrado = NULL;

	FILE* alunos = open_file(ALUNOS_INDEX_FILE_PATH);
	char* file = read_file(alunos);

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

		if (strcmp(numeroEncontrado, value) == 0) {

			getIndiceAndSizeIndex(alunoBuffer, index);

			alunos = open_file(ALUNOS_FILE_PATH);

			char* fileFromPos = readFromBufferPos(alunos, index[0]);


			long size = index[1] - index[0];
			alunoEncontrado = (char*)malloc(size + 1);
			alunoEncontrado = getAlunoFromBuffer(fileFromPos, size);
			break;
		}
	}

	return alunoEncontrado;
}

char* alunosByCurso(char* value) {
	char* alunosFound = NULL;


	FILE* alunos = open_file(ALUNOS_CURSO_FILE_PATH);
	char* file = read_file(alunos);

	long index[2];

	int counter = 0;
	int i = 0;
	int pos = 0;

	for (i = 0; i < strlen(file); i++) {
		char* curso_aluno = NULL;

		int j = i;
		while (file[j] != ';')
		{
			j++;
		}

		int len = j - i;

		curso_aluno = (char*) malloc(len + 1);
		sprintf(curso_aluno, "%.*s;", len, &file[i]);

		char* nCursoEncontrado = getNCursoIndex(curso_aluno);

		if (strcmp(nCursoEncontrado, value) == 0) {

			getIndiceAndSizeIndex(curso_aluno, index);
			alunos = open_file(ALUNOS_FILE_PATH);


			char* fileFromPos = readFromBufferPos(alunos, index[0]);


			long size = index[1] - index[0];
			if (alunosFound == NULL) {
				alunosFound = (char*)malloc(size + 1);
				alunosFound = getAlunoFromBuffer(fileFromPos, size);
			}
			else {
				alunosFound = (char*)realloc(alunosFound, strlen(alunosFound) + size + 1);
				alunosFound = strcat(alunosFound, getAlunoFromBuffer(fileFromPos, size));
			}

			free(fileFromPos);


		}
		i = j + 1;
	}

	return alunosFound;
}

char* allAlunos() {
	FILE* alunos = open_file(ALUNOS_FILE_PATH);
	char* allAlunos = read_file(alunos);

	return allAlunos;
}