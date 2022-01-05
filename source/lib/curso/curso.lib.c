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
	char* nomeCurso = get_value(json, "nome");
	char* nCurso = get_value(json, "n_curso");

	if (strcmp("null", nomeCurso) || strcmp("null", nCurso)) {
		return NULL;
	}

	return curso_create(nomeCurso, nCurso);
}

Curso* cursoFromBuffer(char* buffer) {

	int pos = 0;
	int i = 0;
	int tLen = 0;
	char* cursoNome = NULL;
	char* nCurso = NULL;

	int counter = 0;
	for (i = 0; i < strlen(buffer); i++) {
		if (pos == Curso_Sigla_A) {
			int j = i + 1;
			
			while (buffer[j] != ',')
			{
				j++;
				if (j > strlen(buffer)) {
					return NULL;
				}
			}
			

			tLen = j - i + 1;
			
			cursoNome = (char*)malloc(tLen);
			sprintf(cursoNome, "%.*s", tLen - 1, &buffer[i]);
			i = j + 1;

			while (buffer[j] != ';')
			{
				j++;
			}
			tLen = j - i + 1;

			nCurso = (char*)malloc(tLen + 1);
			sprintf(nCurso, "%.*s", tLen - 1, &buffer[i]);
			break;
		}
		else if (buffer[i] == ',') {
			pos++;
		}
	}

	if (cursoNome == NULL || nCurso == NULL) {
		return NULL;
	}

	return curso_create(cursoNome, nCurso);
}