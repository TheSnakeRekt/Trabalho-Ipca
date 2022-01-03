#include "aluno.common.h"

char* aluno_op(int op_type, char* data) {
	switch (op_type) {
	case Select:
		return find(data);
	case Mod:
		return mod(data);
	/*case Delete:
		return del(data);*/
	case Create:
		return create(data);
	default:
		return "null";
	}
}