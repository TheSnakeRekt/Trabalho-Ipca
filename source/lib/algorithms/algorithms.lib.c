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
		}
		else {
			alunoBuffer = alunoBuffer + file[i];
		}

		alunoEncontrado = alunoEncontrado + '\0';

		if (strcmp(alunoEncontrado, value)) {

			index = getIndiceIndex(alunoEncontrado);

			break;
		}
	}

	alunos = open_file(ALUNOS_FILE_PATH);

	file = read_file(alunos);

	return getAlunoFromBuffer(file, index);
}