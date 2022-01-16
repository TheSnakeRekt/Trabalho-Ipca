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
	char* curso;

	for (int i = 0; i < strlen(buffer); i++) {
		if (buffer[i] == ';') {
			curso = (char*) malloc(i + 2);
			sprintf(curso, "%.*s;\n", i, buffer);
			if (strcmp(curso, value) == 0) {
				return 1;
			}
		}
	}

	return 0;
}

long saveCurso(Curso* curso) {
	FILE* fp = open_file(fullpath(CURSOS_FILE_PATH));
	char* fBuffer = read_file(fp);

	if (cursoExists(fBuffer, curso->string) == 1) {
		perror("Este curso já existe");
		return 0;
	}

	fp = open_file(fullpath(CURSOS_FILE_PATH));
	long i = write_file(curso->string, fp);
	fclose(fp);

	if (i < 0) {
		perror("Error while saving Curso %s", curso->string);
		return 0;
	}

	return 1;
}
