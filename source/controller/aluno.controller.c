#include "aluno.controller.h"

char* update_aluno(char* data) {
	char* nMeca = get_value(data, "n_meca");
	char* alunoBuffer = select_aluno(N_Mecanografico_A, nMeca);

	return mod_aluno(alunoBuffer);
}

char* del(char* data) {
	return "null";
};


char* find_aluno(char* data) {

	//retorna todos os alunos
	if (strcmp(data, "*") == 0) {
		return select_aluno("", "");
	}

	char* prop = atoi(get_value(data, "prop"));
	char* value = get_value(data, "value");

	return select_aluno(prop, value);
}

char* create_aluno(char* value) {
	return save_aluno(value);
}
