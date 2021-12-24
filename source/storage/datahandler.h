#include "../data_structures/types.h"
#include "../lib/mapping/aluno_mapping.h"


//seleciona através de critério de pesquisa e valor {prop -> value}
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