#include "../data_structures/types.h"
#include "../lib/mapping/aluno_mapping.h"
#include "storage.h"
#include "../lib/index/index.lib.h"
#include "../lib/aluno/aluno.lib.h"


char* find(int type, int prop, char* value) {
	switch (type) {
		case Aluno_T:
			return select_aluno(prop, value);
	}
}



int save(char* stream, char* type); //guarda dados
int mod(char type, char* old, char* mod); //modificar dados



