#include "curso.algo.h"

char* allCursos() {
	FILE* cursos = open_file(CURSOS_FILE_PATH);
	char* allCursos = read_file(cursos);

	return allCursos;
}