#include "aluno.lib.h"

char* getNomeAluno(char* aluno) {
	int i = 0;
	char* nome = "\0";

	for (i = 0; i <strlen(aluno); i++) {
		if (aluno[i] == ','){
			break;
		}
	}

	nome = (char*)malloc(i + 1);
	
	sprintf(nome, "%.*s\n", i, aluno);

	return nome;
}

char* getNumeroMecanograficoAluno(char* aluno){
	int pos = 0;
	int i = 0;
	int tLen = 0;

	char* n_meca = "\0";

	for (i = 0; i < strlen(aluno); i++) {
		if (pos == N_Mecanografico_A) {
			int j = i + 1;
			while (aluno[j] != ',')
			{
				j++;
			}
			 tLen = j - i;

			break;
		}
		else if(aluno[i] == ',') {
			pos++;
		}
	}

	n_meca = (char*)malloc(tLen + 1);
	sprintf(n_meca, "%.*s\n", tLen, &aluno[i]);

	return n_meca;
}

char* getDataNascimentoAluno(char* aluno) {
	int pos = 0;
	int i = 0;
	int tLen = 0;

	char* dataNascimento;

	for (i = 0; i < strlen(aluno); i++) {
		if (pos == Data_Nascimento_A) {
			int j = i + 1;
			while (aluno[j] != ',')
			{
				j++;
			}
			tLen = j - i;

			break;
		}
		else if (aluno[i] == ',') {
			pos++;
		}
	}


	dataNascimento = (char*)malloc(tLen + 1);
	sprintf(dataNascimento, "%.*s\n", tLen, &aluno[i]);

	return dataNascimento;
}

char* getMoradaAluno(char* aluno) {
	int pos = 0;
	int start = 0;
	int lastValuePos = 0;
	int tLen = 0;

	char* morada;

	for (int i = 0; i < strlen(aluno); i++) {
		if (pos >= Morada_Rua_A && pos <= Morada_Localidade_A) {
			if (start == 0) {
				start = i;
			}

			int j = i + 1;
			while (aluno[j] != ',')
			{
				j++;
			}
			if (pos != Morada_Localidade_A) {
				aluno[j] = ' ';
			}
			lastValuePos = j;

			pos++;
			tLen = tLen + j - i + 1;
			i = lastValuePos;
		}else if (aluno[i] == ',') {
			pos++;
		}
		else if(pos > Morada_Localidade_A) {
			break;
		}
	}

	morada = (char*)malloc(tLen + 1);
	sprintf(morada, "%.*s\n", tLen - 1, &aluno[start]);
	

	return morada;
}

char* getCursoAluno(char* aluno) {
	int pos = 0;
	int i = 0;
	int tLen = 0;

	char* curso;

	for (i = 0; i < strlen(aluno); i++) {
		if (pos == Curso_Sigla_A) {
			int j = i + 1;
			while (aluno[j] != ',')
			{
				j++;
			}
			aluno[j] = ' ';
			tLen = j - i + 1;

			break;
		}
		else if (aluno[i] == ',') {
			pos++;
		}
	}


	curso = (char*)malloc(tLen + 1);
	sprintf(curso, "%s\n", &aluno[i]);

	return curso;
}

char* getAlunoFromBuffer(char* buffer, long size) {
	char* aluno;


	aluno = (char*) malloc(size + 1);
	sprintf(aluno, "%.*s", size, buffer);

	return aluno;
}

Aluno* alunoFromJson(char* json) {
	signed int mes, dia, ano;
	int nPorta;

	char* nome = get_value(json, "nome");
	char* numero = get_value(json, "numero");

	mes = atoi(get_value(json, "mes"));
	dia = atoi(get_value(json, "dia"));
	ano = atoi(get_value(json, "ano"));

	char* rua = get_value(json, "rua");
	char* codPostal = get_value(json, "codPostal");
	char* localidade = get_value(json, "localidade");
	nPorta = atoi(get_value(json, "n_porta"));

	char* nomeCurso = get_value(json, "curso");
	char* nCurso = get_value(json, "n_curso");

	Curso* curso = curso_create(nomeCurso, nCurso);

	if (curso != NULL) {							
		long savedCurso = saveCurso(curso);

		if (savedCurso < 0) {
			perror("Falha ao criar elementos do aluno");
			return "false";
		}
	}

	Data* dataNascimento = data_create(dia, mes, ano);
	Morada* morada = morada_create(rua, codPostal, localidade, nPorta);
	
	if (dataNascimento == NULL || morada == NULL) {
		perror("Falha ao criar elementos do aluno");
		return "false";
	}

	return create_aluno(nome, numero, *dataNascimento, *morada, *curso);
}