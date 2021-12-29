#include "datahandler.h"


char* findBy(int type, int prop, char* value) {
	switch (type) {
		case Aluno_T:
			return select_aluno(prop, value);
	}
}



int save(char* stream, char* type); //guarda dados
int mod(char type, char* old, char* mod); //modificar dados



