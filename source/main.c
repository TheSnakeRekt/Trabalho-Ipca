#include <stdio.h>
#include <stdarg.h>
#include "storage/filehandle.h"
#include "data_structures/aluno.h"

int main() {
	filehandle_init();
	
	/*
		Exemplo de como um aluno seria criado programaticamente, e em seguida
		guardado no ficheiro correspondente.

	*/

	Data* dataNascimento = data_create(11, 4, 1996);
	Morada* morada = morada_create("Travessa da Murteira", "4805-206", 86);
	Curso* curso = curso_create("SEC", "C140");

	Aluno* aluno = create_aluno("Jorge Guimaraes", "a23065", *dataNascimento, *morada, *curso);

	FILE* file = open_file(ALUNOS_FILE_PATH);

	int index = write_file(serialize(aluno), file);

	if (index < 0) {
		perror("O Aluno nao foi guardado");
		return 1;
	}

	file = open_file(ALUNOS_INDEX_FILE_PATH);
	fprintf(file, "%d,%s,%s;\n", index, "a23065", "Jorge Guimaraes");
	fclose(file);

	return 0;
}