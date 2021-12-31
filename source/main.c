#include <stdio.h>
#include <stdarg.h>
#include "lib/json/data_parser.h"
#include "common/aluno.common.h"

char* execute(int domain, int op_type, char* data);

/*
	apaguei o antigo codigo pois ele era so um exemplo, tive de adiantar a comunicaçao com a interface, porque ainda nao tinha feito isso
	o main ja esta a usar o que for passado na linha de comandos.
*/

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


char* execute(int domain, int op_type, char* data) {
	switch (domain) {
		case Aluno:
			return aluno_op(op_type, data);
		default:
			perror("Error: This domain does not exist");
	}
}