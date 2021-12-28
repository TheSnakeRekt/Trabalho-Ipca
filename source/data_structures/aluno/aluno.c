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

	Aluno* obj = (Aluno*)malloc(sizeof(Aluno));

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

	obj->alterarNome = alterar_nome;
	obj->alterarDataNascimento = alterar_nascimento;
	obj->alterarNumeroMecanografico = alterar_numero;
	obj->alterarMorada = alterar_morada;
	obj->alterarCurso = alterar_curso;

	return obj;
}

char* serializeAluno(Aluno* al) {

	size_t len = 0;

	len = snprintf(NULL, len, "%s,%s,%s,%s,%s;\n", al->nome, serializeData(&al->dataNascimento), al->n_mecanografico, serializeMorada(&al->morada), serializeCurso(&al->curso));

	al->string = (char*)malloc(len);
	signed int totalB = snprintf(al->string, len + 1, "%s,%s,%s,%s,%s;\n", al->nome, serializeData(&al->dataNascimento), al->n_mecanografico, serializeMorada(&al->morada), serializeCurso(&al->curso));

	if (totalB > len + 1)
	{
		printf("O Aluno nao foi serializado.");
		return NULL;
	}

	return al->string;
}