#include "aluno.common.h"
#include "interop_mapper.h"

char* find(char* value);

char* aluno_op(int op_type, char* data) {
	switch (op_type) {
		case Select:
			return find(data);
		default:
			return "null";
	}
}

char* find(char* value) {
	size_t len = 0;
	len = snprintf(NULL, len, "Hello %s", value);

	char* buffer = (char*)malloc(len);

	sprintf(buffer, "Hello %s", value);
	return buffer;
	//return findBy(Aluno_T, prop, value);
}

/*int create(char* value) {
	return find(type, prop, value);
}

int mod(int id, int prop, char* value) {
	return mod(id, prop, value);
}*/