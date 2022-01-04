#include "curso.algo.h"

char* cursosByName(char* value) {
	char* cursoEncontrado;

	FILE* cursos = open_file(CURSO_INDEX_FILE_PATH);
	char* file = read_file(cursos);

	int counter = 0;
	long index = -1;

	for (int i = 0; i < strlen(file); i++) {
		char* cursoBuffer = "\0";

		if (file[i] == ';') {
			cursoEncontrado = getNomeIndex(cursoBuffer);
		}
		else {
			strcat(cursoBuffer, file[i]);
		}

		strcat(cursoBuffer, "\0");

		if (strcmp(cursoBuffer, value)) {

			index = getIndiceAndSizeIndex(cursoBuffer);

			break;
		}
	}

	cursos = open_file(CURSOS_FILE_PATH);

	file = read_file(cursos);

	return getCursoFromBuffer(file, index);
}

char* cursoByNumero(char* value) {
	return "";
}

char* allCursos() {
	FILE* cursos = open_file(CURSOS_FILE_PATH);
	char* allCursos = read_file(cursos);

	return allCursos;
}