#include "aluno.repo.lib.h"

char* select_aluno(int prop, char* value) {
	char* alunoBuffer = "\0";

	switch (prop) {
		case Nome_A:
			alunoBuffer = byName(value);
			break;
		case N_Mecanografico_A:
			//alunoBuffer = byNumero(value);
			break;
	}

	return alunoBuffer;
}
