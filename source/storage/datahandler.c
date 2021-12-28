#include "../data_structures/types.h"
#include "../lib/mapping/aluno_mapping.h"
#include "storage.h"
#include "../lib/index/index.lib.h"
#include "../lib/aluno/aluno.lib.h"

//seleciona através de critério de pesquisa e valor {prop -> value}


char* byName(char* value) {
	FILE* alunos = open_file(ALUNOS_INDEX_FILE_PATH);

	char* file = read_file(alunos);
	int counter = 0;
	char* alunoEncontrado;
	char* index; 

	for (int i = 0; i < strlen(file); i++) {
		char* alunoBuffer;	
		
		if (file[i] == ';') {
			alunoEncontrado = getNomeIndex(alunoBuffer);
		}
		else {
			alunoBuffer = alunoBuffer + file[i];
		}
		
		if (strcmp(alunoEncontrado, value)) {
			
			index = getIndiceIndex(alunoEncontrado);
			
			break;
		}	
	}
	alunos = open_file(ALUNOS_FILE_PATH);

	file = read_file(alunos);

	return getAlunoFromBuffer(file, index);
}



char* select(int type, int prop, char* value) {
	switch (type) {
		case Aluno_T:
			return select_aluno(prop, value);
	}
}

char* select_aluno(int prop, char* value) {
	switch (prop) {
		case Nome_A:
			return byName(value); //aqui vai estar o algoritmo de pesquisa por nome
		case N_Mecanografico_A:
			return byNumero(value); //aqui vai estar o algoritmo de pesquisa por NumeroMecanografico
	}
}


int save(char* stream, char* type); //guarda dados
int mod(char type, char* old, char* mod); //modificar dados



