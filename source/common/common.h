#pragma once
#include "../data_structures/types.h"
#include "../lib/aluno/aluno.repo.lib.h"
#include "interop_mapper.h"
#include "domain.interop.mapper.h"

char* aluno_op(int op_type, char* data);
char* curso_op(int op_type, char* data);