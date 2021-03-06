#include "aluno.controller.h"

char* update_aluno(char* data) {
	return mod_aluno(data);
}

char* remove_aluno(char* data) {
	char* value = get_value(data, "value");
	return delete_aluno(value);
};


char* find_aluno(char* data) {

	//retorna todos os alunos
	if (strcmp(data, "*") == 0) {
		return select_aluno("", "");
	}

	int prop = atoi(get_value(data, "prop"));
	char* value = get_value(data, "value");

	return select_aluno(prop, value);
}

char* insert_aluno(char* value) {
	return save_aluno(value);
}
