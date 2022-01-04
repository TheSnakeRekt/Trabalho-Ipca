#include "curso.controller.h"

char* update_curso(char* data) {
	char* nCurso = get_value(data, "nCurso");
	char* curso_buffer = select_curso(Numero_C, nCurso);

	return mod_curso(curso_buffer);
}

char* delete_curso(char* data) {
	return "null";
};

char* find_curso(char* data) {

	//retorna todos os cursos
	if (strcmp(data, "*") == 0) {
		return select_curso("", "");
	}

	char* prop = atoi(get_value(data, "prop"));
	char* value = get_value(data, "value");

	return select_curso(prop, value);
}

char* insert_curso(char* value) {
	return save_curso(value);
}
