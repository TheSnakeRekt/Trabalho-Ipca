#include "curso.h"


Curso* curso_create(char* nome, char* numero) {
	Curso* obj = (Curso*)malloc(sizeof(Curso));

	if (obj == NULL) {
		return NULL;
	}

	obj->TYPE = Curso_T;

	obj->nome = nome;
	obj->numero = numero;
	obj->string = "\0";
	serializeCurso(obj);

	return obj;
}

char* serializeCurso(Curso* cu)
{
	size_t len = 0;
	len = snprintf(NULL, len, "%s,%s;\n", cu->nome, cu->numero);

	cu->string = (char*)malloc(len);
	signed int totalB = snprintf(cu->string, len + 1, "%s,%s;\n", cu->nome, cu->numero);

	if (totalB > len + 1)
	{
		printf("O Curso nao foi serializado.");
		return NULL;
	}

	return cu->string;
}

int cursoExists(char* buffer,char* value) {
	int pos = 0;
	char* curso;

	for (int i = 0; i < strlen(buffer); i++) {
		if (buffer[i] == '\n') {
			curso = (char*) malloc(i + 2);
			sprintf(curso, "%.*s\n", i, &buffer[pos]);
			if (strcmp(curso, value) == 0) {
				return pos;
			}
			pos = i;
		}
	}

	return -1;
}

long saveCurso(Curso* curso) {
	FILE* fp = open_file(CURSOS_FILE_PATH);
	char* fBuffer = read_file(fp);

	int existingPos = cursoExists(fBuffer, curso->string);
	if (existingPos >= 0) {
		return existingPos;
	}

	fp = open_file(CURSOS_FILE_PATH);
	long i = write_file(curso->string, fp);
	fclose(fp);

	if (i < 0) {
		perror("Error while saving Curso %s", curso->string);
		return 0;
	}

	return i;
}
