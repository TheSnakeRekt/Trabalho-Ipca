#include "curso.lib.h"

char* getCursoName(char* buffer) {
	int i = 0;
	int tLen = 0;
	int pos = 0;
	char* nome = NULL;

	for (i = 0; i < strlen(buffer); i++) {
		if (pos == Nome_C) {
			int j = i + 1;
			while (buffer[j] != ';')
			{
				j++;
			}
			tLen = j - i;

			break;
		}
		else if (buffer[i] == ',') {
			pos++;
		}
	}

	nome = (char*)malloc(tLen + 1);

	sprintf(nome, "%.*s\n", tLen, &buffer[i]);

	return nome;
}

char* getCursoNumero(char* buffer) {
	int i = 0;
	int tLen = 0;
	int pos = 0;
	char* numero = NULL;

	for (i = 0; i < strlen(buffer); i++) {
		if (pos == Numero_C) {
			int j = i + 1;
			while (buffer[j] != ';')
			{
				j++;
			}
			tLen = j - i;

			break;
		}
		else if (buffer[i] == ',') {
			pos++;
		}
	}

	numero = (char*)malloc(tLen + 1);

	sprintf(numero, "%.*s\n", tLen, &buffer[i]);

	return numero;
}

Curso* cursoFromJson(char* json) {
	char* nomeCurso = get_value(json, "curso");
	char* nCurso = get_value(json, "n_curso");

	return curso_create(nomeCurso, nCurso);
}