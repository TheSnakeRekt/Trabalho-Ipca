#include "curso.repo.lib.h"


char* select_curso(int prop, char* value) {
	char* cursoBuffer = "\0";

	switch (prop) {
	case Nome_C:
		cursoBuffer = cursosByName(value); //recebe um nome ou parte de um nome, retorna os cursos que contenham esse nome
		break;
	case Numero_C:
		cursoBuffer = cursoByNumero(value); //recebe um numero de curso, retorna o curso com esse numero
		break;
	default:
		cursoBuffer = allCursos(); //retorna todos os Cursos dentro do ficheiro;
	}

	return cursoBuffer;
}

char* save_curso(char* json) {
	char* result = "false";
	Curso* curso = cursoFromJson(json);

	if (curso != NULL) {
		long savedCurso = saveCurso(curso);

		if (savedCurso < 0) {
			perror("Falha ao criar elementos do aluno");
		}
		result = "true";
	}

	return result;
}

char* mod_curso(char* curso) {
	return "";
}