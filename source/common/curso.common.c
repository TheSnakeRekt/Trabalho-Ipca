#include "curso.common.h"

char* curso_op(int op_type, char* data) {
	switch (op_type) {
	case Select:
		return find_curso(data);
	case Delete:
		return delete_curso(data);
	case Create:
		return insert_curso(data);
	case Mod:
		return update_curso(data);
	default:
		return "null";
	}
}