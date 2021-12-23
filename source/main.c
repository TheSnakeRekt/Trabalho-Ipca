#include <stdio.h>
#include <stdarg.h>
#include "storage/filehandle.h"
#include "data_structures/aluno.h"

int main() {
	filehandle_init();

	Data* dataNascimento = data_create();
	dataNascimento->set(dataNascimento, 11, 4, 1996);

	Morada* morada = morada_create();
	morada->set(morada, "Travessa da Murteira", "4805-206", 86);
	

	Curso* curso = curso_create();
	curso->set(curso, "SEC", "C140");

	Aluno* aluno = create_aluno("Jorge Guimaraes", "a23065", *dataNascimento, *morada, *curso);

	printf("%s", serialize(*aluno));
}

