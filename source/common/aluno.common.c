#include "aluno.common.h"

char* aluno_op(int op_type, char* data) {
	switch (op_type) {
	case Select:
		return find_aluno(data);
	case Mod:
		return update_aluno(data);
	/*case Delete:
		return del(data);*/
	case Create:
		return create_aluno(data);
	default:
		return "null";
	}
}