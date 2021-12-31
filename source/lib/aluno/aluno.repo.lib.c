#include "aluno.repo.lib.h"

char* select_aluno(int prop, char* value) {
	char* alunoBuffer = "\0";

	switch (prop) {
		case Nome_A:
			alunoBuffer = byName(value);
			break;
		case N_Mecanografico_A:
			alunoBuffer = byNumero(value);
			break;
		default:
			alunoBuffer = allAlunos();
	}

	return alunoBuffer;
}


char* save_aluno(char* json) {

	Aluno* aluno = fromJson(json);

	if (aluno == NULL) {
		perror("Json was not parsed");
		return "false";
	}

	FILE* fp = open_file(ALUNOS_FILE_PATH);
	int i = write_file(aluno->string, fp);
	fclose(fp);

	fp = open_file(ALUNOS_INDEX_FILE_PATH);
	fprintf(fp, "%d,%s,%s;\n", i, aluno->n_mecanografico, aluno->nome);
	fclose(fp);

	fp = open_file(ALUNOS_CURSO_FILE_PATH);
	fprintf(fp, "%d,%s,%s;\n", i, aluno->curso.nome, aluno->nome);
	fclose(fp);

	if (i < 0) {
		perror("false");
		return "false";
	}

	free(aluno);
	fclose(fp);
	return "true";
}
