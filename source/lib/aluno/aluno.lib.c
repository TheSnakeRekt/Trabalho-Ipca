#include "aluno.lib.h"


AlunoArray* new_node(Aluno al) {
	AlunoArray* alunoList = malloc(sizeof(AlunoArray));

	alunoList->aluno = al;
	alunoList->next = NULL;

	return alunoList;
}

char* getNomeAluno(char* aluno) {
	int i = 0;

	for (i = 0; i <strlen(aluno); i++) {
		if (aluno[i] == ','){
			break;
		}
	}

	char* nome = (char*)malloc(i + 1);
	
	sprintf(nome, "%.*s", i, aluno);

	return nome;
}

char* getNumeroMecanograficoAluno(char* aluno){
	int pos = 0;
	int i = 0;
	int tLen = 0;

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

	char* n_meca = (char*)malloc(tLen + 1);
	sprintf(n_meca, "%.*s", tLen, &aluno[i]);
	
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


int alunoExists(char* value) {
	if (alunoByNumero(value) != NULL) {
		return 1;
	}
	return 0;
}


AlunoArray* alunosFromBuffer(char* buffer) {
	AlunoArray* alunoArray = NULL;


	for (int i = 0; i < strlen(buffer); i++) {
		int j = i;
		while (buffer[j] != ';')
		{
			j++;
		}

		int len = j - i;

		char* alunoBuffer = (char*)malloc(len + 1);
		sprintf(alunoBuffer, "%.*s;", len, &buffer[i]);

		Data* data = dataFromBuffer(alunoBuffer);
		Curso* curso = cursoFromBuffer(alunoBuffer);
		Morada* morada = moradaFromBuffer(alunoBuffer);
		char* nome = getNomeAluno(alunoBuffer);
		char* nMeca = getNumeroMecanograficoAluno(alunoBuffer);

		
		if (curso == NULL || data == NULL || morada == NULL || strcmp(nome, "") == 0 || strcmp(nMeca, "") == 0 || strstr(nMeca,",") > 0) {
			continue;
		}

		Aluno* aluno = create_aluno(nome, nMeca, *data,
			*morada, *curso);

		if (aluno == NULL) {
			continue;
		}

		if (alunoArray == NULL) {
			alunoArray = malloc(sizeof(AlunoArray));

			alunoArray->aluno = *aluno;
			alunoArray->next = NULL;
		}
		else {
			AlunoArray* tmp = malloc(sizeof(AlunoArray));
			AlunoArray* node = new_node(*aluno);

			tmp = alunoArray;
			while (alunoArray->next != NULL) {
				alunoArray = alunoArray->next;
			}

			alunoArray->next = node;
			alunoArray = tmp;
		}

		i = j + 1;
	}

	return alunoArray;
}

Aluno* alunoFromJson(char* json) {
	signed int mes, dia, ano;
	int nPorta;

	char* nome = get_value(json, "nome");
	char* numero = get_value(json, "numero");

	if (alunoExists(numero) == 1) {
		perror("O Aluno ja existe.");
		return NULL;
	}

	mes = atoi(get_value(json, "mes"));
	dia = atoi(get_value(json, "dia"));
	ano = atoi(get_value(json, "ano"));

	char* rua = get_value(json, "rua");
	char* codPostal = get_value(json, "codPostal");
	char* localidade = get_value(json, "localidade");
	nPorta = atoi(get_value(json, "n_porta"));

	Curso* curso = cursoFromJson(json);
	Data* dataNascimento = data_create(dia, mes, ano);
	Morada* morada = morada_create(rua, codPostal, localidade, nPorta);
	
	if (dataNascimento == NULL || morada == NULL) {
		perror("Falha ao criar elementos do aluno");
		return "false";
	}

	return create_aluno(nome, numero, *dataNascimento, *morada, *curso);
}