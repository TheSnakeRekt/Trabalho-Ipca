#include "../algorithms/aluno.algo.h"

char* select_aluno(int prop, char* value) {
	char* alunoBuffer = "\0";

	switch (prop) {
		case Nome_A:
			alunoBuffer = byName(value); //recebe um nome ou parte de um nome, retorna os alunos que contenham esse nome
			break;
		case N_Mecanografico_A:
			alunoBuffer = byNumero(value); //recebe um numero mecanografico, retorna o aluno com esse numero
			break;
		/*case Curso_Sigla_A:
			alunoBuffer = byCurso(value); recebe uma Sigla de curso, retorna todos alunos desse curso
			break;*/
		default:
			alunoBuffer = allAlunos(); //retorna todos os Alunos dentro do ficheiro;
	}

	return alunoBuffer;
}

/*
	Recebe um aluno em formato JSON, e guarda o mesmo no ficheiro de alunos, assim como os seus indices
*/
char* save_aluno(char* json) {

	Aluno* aluno = fromJson(json);

	if (aluno == NULL) {
		return "false";
	}

	long savedResult = saveAluno(aluno);
	if (savedResult == 0) {
		return "false";
	}

	return "true";
}

char* mod_aluno(char* json) {

	Aluno* aluno = fromJson(json);

	if (aluno == NULL) {
		return "false";
	}

	long savedResult = saveAluno(aluno);
	if (savedResult == 0) {
		return "false";
	}
	return "true";
}
