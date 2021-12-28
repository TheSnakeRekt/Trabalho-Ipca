#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../morada/morada.h"
#include "../data/data.h"
#include "../curso/curso.h"


extern struct Aluno;

typedef void (*alterarNome)(struct Aluno* self, char* nome);
typedef void (*alterarNumeroMecanografico)(struct Aluno* self, char* n);
typedef void (*alterarDataNascimento)(struct Aluno* self, Data d);
typedef void (*alterarMorada)(struct Aluno* self, Morada m);
typedef void (*alterarCurso)(struct Aluno* self, Curso c);

 typedef struct Aluno{ 
	char* string;
	char* nome;
	char* n_mecanografico;
	int TYPE;

	Data dataNascimento;
	Morada morada; 
	Curso curso;

	alterarNome alterarNome;
	alterarDataNascimento alterarDataNascimento;
	alterarNumeroMecanografico alterarNumeroMecanografico;
	alterarMorada alterarMorada;
	alterarCurso alterarCurso;
} Aluno;

 Aluno* create_aluno(char* nome, char* n_mecanografico, Data dataNascimento, Morada morada, Curso curso);
 char* serializeAluno(Aluno* al);