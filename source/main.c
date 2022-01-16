#include <stdio.h>
#include <stdarg.h>
#include "common/aluno.common.h"
#include "common/curso.common.h"


char* execute(int domain, int op_type, char* data);


void main(int argc, char* argv[]) {
	
	
	if (argc < 2) {
		printf("%d ficheiros foram criados", filehandle_init());
		return;
	}

	if (argc != 4) {
		perror("not enough args <domain> <optype> <data>");
		return;
	}

	/*
		A Funcao atoi() convert um char em int, é uma funcao que ja vem com o C
	*/
	
	int domain = atoi(argv[1]);
	int op_type = atoi(argv[2]);


	printf("%s",execute(domain, op_type, argv[3]));
}

/*
	Executa as Op (operaçoes) consoante o dominio que receber.

	Dominios:
		- Aluno
		- Curso
*/
char* execute(int domain, int op_type, char* data) {
	switch (domain) {
		case Aluno_D:
			return aluno_op(op_type, data);
		case Curso_D:
			return curso_op(op_type, data);
		default:
			perror("Error: This domain does not exist");
	}
}