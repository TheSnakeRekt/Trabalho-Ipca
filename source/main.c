#include <stdio.h>
#include <stdarg.h>
#include "storage/filehandle.h"
#include "data_structures/aluno.h"
#include "lib/aluno/aluno.lib.h"

int main() {
	filehandle_init();
	
	/*
		Exemplo de como um aluno seria criado programaticamente, e em seguida
		guardado no ficheiro correspondente.
	*/

	Data* dataNascimento = data_create(11, 4, 1996);
	Morada* morada = morada_create("Travessa da Murteira B", "4805-206", "Longos", 86);
	Curso* curso = curso_create("SEC", "C140");

	Aluno* aluno = create_aluno("Jorge Guimaraes", "a23065", *dataNascimento, *morada, *curso);

	FILE* file = open_file(ALUNOS_FILE_PATH);

	int index = write_file(serializeAluno(aluno), file);

	if (index < 0) {
		perror("O Aluno nao foi guardado");
		return 1;
	}

	/* 
		Aqui estamos a inserir o aluno no ficheiro de Index para ser mais rapido encontrar-lo
		quando este for pesquisado.
	*/

	file = open_file(ALUNOS_INDEX_FILE_PATH);
	fprintf(file, "%d,%s,%s;\n", index, "a23065", "Jorge Guimaraes");
	fclose(file);

	/*
		Aqui estamos a abrir um ficheiro e carregar o seu conteudo para um buffer;

		Em seguida recuperamos um aluno com uma determinada posiçao neste caso o primeiro aluno,
		pois estamos a passar 0 , libertamos a memoria do buffer, pois ja nao precisamos de toda a informaçao
		e em seguida recuperamos o numero mecanografico do aluno, e finalmente imprimimos os dois.
	*/

	file = open_file(ALUNOS_FILE_PATH);
	char * buffer = read_file(file);

	char* alunoFromFile = getAlunoFromBuffer(buffer, 0);
	

	char* numeroMecanografico = getNumeroMecanografico(alunoFromFile);

	printf("%s\n%s", alunoFromFile, numeroMecanografico);
	system("pause");

	return 0;
}