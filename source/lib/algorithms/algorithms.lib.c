#include "algorithms.lib.h"

char* byName(char* value) {
	char* alunoEncontrado;

	FILE* alunos = open_file(ALUNOS_INDEX_FILE_PATH);
	char* file = read_file(alunos);

	int counter = 0;
	int index = -1;

	for (int i = 0; i < strlen(file); i++) {
		char* alunoBuffer = "\0";

		if (file[i] == ';') {
			alunoEncontrado = getNomeIndex(alunoBuffer);
		} else {
			strcat(alunoBuffer, file[i]);
		}

		strcat(alunoBuffer, "\0");

		if (strcmp(alunoBuffer, value)) {

			index = getIndiceIndex(alunoBuffer);

			break;
		}
	}

	alunos = open_file(ALUNOS_FILE_PATH);

	file = read_file(alunos);

	return getAlunoFromBuffer(file, index);
}

char* byNumero(char* value) {
	char* alunoEncontrado;

	FILE* alunos = open_file(ALUNOS_INDEX_FILE_PATH);
	char* file = read_file(alunos);

	int counter = 0;
	int index = -1;

	for (int i = 0; i < strlen(file); i++) {
		char* alunoBuffer = "\0";

		if (file[i] == ';') {
			alunoEncontrado = getNumeroIndex(alunoBuffer);
		}
		else {
			strcat(alunoBuffer, file[i]);
		}

		strcat(alunoBuffer, "\0");

		if (strcmp(alunoBuffer, value)) {

			index = getIndiceIndex(alunoBuffer);

			break;
		}
	}

	alunos = open_file(ALUNOS_FILE_PATH);

	file = read_file(alunos);

	return getAlunoFromBuffer(file, index);
}

char* allAlunos() {
	FILE* alunos = open_file(ALUNOS_INDEX_FILE_PATH);

	return read_file(alunos);
}