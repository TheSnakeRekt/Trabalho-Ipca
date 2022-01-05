#include "curso.algo.h"

char* cursosByName(char* value) {
	char* cursosFound = NULL;

	FILE* alunos = open_file(CURSOS_FILE_PATH);
	char* file = read_file(alunos);

	for (int i = 0; i < strlen(file); i++) {
		char* cursoBuffer = NULL;

		int j = i;
		while (file[j] != ';')
		{
			j++;
		}

		int len = j - i;

		cursoBuffer = (char*)malloc(len + 1);
		sprintf(cursoBuffer, "%.*s;", len, &file[i]);

		char* cursoEncontrado = getCursoName(cursoBuffer);
		char* found = strstr(cursoEncontrado, value);

		if (found != NULL && strlen(found) > strlen(value) && cursoEncontrado != "\0") {

			free(found);
			found = NULL;

			long size = strlen(cursoEncontrado);
			if (cursosFound == NULL) {
				cursosFound = memcpy(cursosFound, cursoEncontrado, size + 1);
			}
			else {
				cursosFound = (char*)realloc(cursosFound, strlen(cursosFound) + size + 1);
				cursosFound = strcat(cursosFound, cursoEncontrado);
			}

			free(cursoEncontrado);
		}
		i = j + 1;
	}

	return cursosFound;
}

char* cursoByNumero(char* value) {
	char* cursoEncontrado = "\0";

	FILE* cursos = open_file(CURSOS_FILE_PATH);
	char* file = read_file(cursos);


	for (int i = 0; i < strlen(file); i++) {

		int j = i;
		while (file[j] != ';')
		{
			j++;
		}

		int len = j - i;

		cursoEncontrado = (char*)malloc(len + 1);
		sprintf(cursoEncontrado, "%.*s;", len, &file[i]);
		char* numeroCursoEncontrado = getCursoNumero(cursoEncontrado);

		if (strcmp(numeroCursoEncontrado, value)) {
			return cursoEncontrado;
			break;
		}

		free(cursoEncontrado);
		cursoEncontrado = "\0";
	}

	return cursoEncontrado;
}

char* allCursos() {
	FILE* cursos = open_file(CURSOS_FILE_PATH);
	char* allCursos = read_file(cursos);

	return allCursos;
}