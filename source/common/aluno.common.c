#include "aluno.common.h"

char* aluno_op(int op_type, char* data) {
	switch (op_type) {
	case Select:
		return find_aluno(data);
	case Mod:
		return update_aluno(data);
	case Delete:
		return remove_aluno(data);
	case Create:
		return insert_aluno(data);
	default:
		return "null";
	}
}