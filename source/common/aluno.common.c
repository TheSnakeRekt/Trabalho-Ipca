#include "aluno.common.h"
#include "interop_mapper.h"
#include "../lib/json/data_parser.h"

char* find(char* value);
char* mod(char* data);
char* del(char* data);
char* create(char* data);

char* aluno_op(int op_type, char* data) {
	switch (op_type) {
		case Select:
			return find(data);
		case Delete:
			return del(data);
		case Create:
			return create(data);
		default:
			return "null";
	}
}

char* find(char* data) {
	char* prop = atoi(get_value(data, "prop"));
	char* value = get_value(data, "value");
	
	return select_aluno(prop, value);
}

char* create(char* value) {
	return save_aluno(value);
}