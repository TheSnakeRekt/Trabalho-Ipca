#include "aluno.lib.h"

char* select_aluno(int prop, char* value) {
	char* alunoBuffer = "\0";

	switch (prop) {
		case Nome_A:
			alunoBuffer = alunosByName(value); //recebe um nome ou parte de um nome, retorna os alunos que contenham esse nome
			break;
		case N_Mecanografico_A:
			alunoBuffer = alunoByNumero(value); //recebe um numero mecanografico, retorna o aluno com esse numero
			break;
		case Curso_Numero_A:
			alunoBuffer = alunosByCurso(value); //recebe uma Sigla de curso, retorna todos alunos desse curso
			break;
		default:
			alunoBuffer = allAlunos(); //retorna todos os Alunos dentro do ficheiro;
	}

	return alunoBuffer;
}



/*
	Recebe um aluno em formato JSON, e guarda o mesmo no ficheiro de alunos, assim como os seus indices
*/
char* save_aluno(char* json) {

	Aluno* aluno = alunoFromJson(json, 0);

	if (aluno == NULL) {
		return "false";
	}

	long savedResult = saveAluno(aluno, "a+");

	return "true";
}

char* mod_aluno(char* json) {

	Aluno* alunoUpdated = alunoFromJson(json, 1);

	if (alunoUpdated == NULL) {
		return "false";
	}

	char* oldNumero = get_value(json, "numero");
	char* alunosBuffer = allAlunos();

	if (strlen(alunosBuffer) < 1) {
		return "false";
	}

	AlunoArray* alunos = alunosFromBuffer(alunosBuffer);
	int written = 0;


	if (&alunos->aluno != NULL) {
		if (strcmp(alunos->aluno.n_mecanografico, oldNumero) == 0) {
			saveAluno(alunoUpdated, "w+");
		}
	}

	while (alunos->next != NULL) {
		if (strcmp(alunos->aluno.n_mecanografico, oldNumero) == 0) {
			saveAluno(alunoUpdated, "w+");
			alunos = alunos->next;
		}
		if (written == 0) {
			saveAluno(&alunos->aluno, "w+");
		}
		else {
			saveAluno(&alunos->aluno, "a+");
		}

		written++;
		alunos = alunos->next;
	}

	return "true";
}

char* delete_aluno(char* nMeca) {

	char* alunosBuffer = allAlunos();
	if (strlen(alunosBuffer) < 1) {
		return "false";
	}

	AlunoArray* alunos = alunosFromBuffer(alunosBuffer);
	int written = 0;

	if (&alunos->aluno != NULL) {
		if (strcmp(alunos->aluno.n_mecanografico, nMeca) == 0) {
			saveAluno(NULL, "w+");
		}
	}

	while (alunos->next != NULL) {
		if (strcmp(alunos->aluno.n_mecanografico, nMeca) == 0) {
			alunos = alunos->next;
		}
		if (written == 0) {
			saveAluno(&alunos->aluno, "w+");
		}
		else {
			saveAluno(&alunos->aluno, "a+");
		}

		written++;
		alunos = alunos->next;
	}

	return "true";
}