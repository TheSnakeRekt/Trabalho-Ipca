#include "aluno.h"
//funcao que altera as propriedades dos alunos

void alterar_nome(Aluno* self, char* nome) {
	self->nome = nome;
}

void alterar_nascimento(Aluno* self, Data nascimento) {
	self->dataNascimento = nascimento;
}

void alterar_numero(Aluno* self, char* numero) {
	self->n_mecanografico = numero;
}

void alterar_morada(Aluno* self, Morada morada) {
	self->morada = morada;
}

void alterar_curso(Aluno* self, Curso curso) {
	self->curso = curso;
}

Aluno* create_aluno(char* nome, char* n_mecanografico, Data dataNascimento, Morada morada, Curso curso) {

	Aluno* obj = malloc(sizeof(Aluno));

	if (obj == NULL) {
		return NULL;
	}
	obj->TYPE = Aluno_T;

	obj->nome = nome;
	obj->n_mecanografico = n_mecanografico;
	obj->dataNascimento = dataNascimento;
	obj->morada = morada;
	obj->curso = curso;
	obj->string = "\0";
	serializeAluno(obj);

	obj->alterarNome = alterar_nome;
	obj->alterarDataNascimento = alterar_nascimento;
	obj->alterarNumeroMecanografico = alterar_numero;
	obj->alterarMorada = alterar_morada;
	obj->alterarCurso = alterar_curso;

	return obj;
}

char* serializeAluno(Aluno* al) {

	size_t len = 0;

	len = snprintf(NULL, len, "%s,%s,%s,%s,%s", al->nome, serializeData(&al->dataNascimento), al->n_mecanografico, al->morada.string, al->curso.string);

	al->string = (char*) malloc(len);
	signed int totalB = snprintf(al->string, len + 1, "%s,%s,%s,%s,%s", al->nome, serializeData(&al->dataNascimento), al->n_mecanografico, al->morada.string, al->curso.string);

	if (totalB > len + 1)
	{
		printf("O Aluno nao foi serializado.");
		return NULL;
	}

	return al->string;
}

long saveAluno(Aluno* aluno, char* mode) {
	if(aluno == NULL){
		FILE* fp = fopen(ALUNOS_FILE_PATH, mode);
		write_file("\0", fp);
		fp = fopen(ALUNOS_INDEX_FILE_PATH, mode);
		write_file("\0", fp);
		fp = fopen(ALUNOS_CURSO_FILE_PATH, mode);
		write_file("\0", fp);
		return 0;
	}

	FILE* fp = fopen(ALUNOS_FILE_PATH, mode);
	long index = write_file(aluno->string, fp);
	fclose(fp);

	fp = fopen(ALUNOS_INDEX_FILE_PATH, mode);
	int len = snprintf(NULL, 0, "%d|%d,%s,%s;\n", index, index + strlen(aluno->string), aluno->n_mecanografico, aluno->nome);

	char* aluno_index = (char*) malloc(len + 1);

	snprintf(aluno_index, len+1, "%d|%d,%s,%s;\n", index, index + strlen(aluno->string), aluno->n_mecanografico, aluno->nome);
	write_file(aluno_index, fp);
	fclose(fp);

	free(aluno_index);

	fp = fopen(ALUNOS_CURSO_FILE_PATH, mode);

	len = snprintf(NULL, 0, "%d|%d,%s,%s;\n", index, index + strlen(aluno->string), aluno->curso.numero, aluno->n_mecanografico);

	char* aluno_curso = (char*)malloc(len + 1);

	snprintf(aluno_curso, len + 1, "%d|%d,%s,%s;\n", index, index + strlen(aluno->string), aluno->curso.numero, aluno->n_mecanografico);
	write_file(aluno_curso, fp);
	fclose(fp);
	

	if (index < 0) {
		perror("Error while saving Aluno %s\n", aluno->n_mecanografico);
	}

	return index;
}