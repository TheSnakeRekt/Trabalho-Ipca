# Trabalho-Ipca
Trabalho Final de programação do ETesp de SEC do IPCA


Payloads enviados como argumentos através do front

1 0 "{\"prop\":8,\"value\":\"A140\"}" - Alunos por Curso Filter
1 0 "{\"prop\":0,\"value\":\"Jorge\"}" - Alunos por Nome Filter
1 0 "{\"prop\":2,\"value\":\"a23069\"}" - Aluno por Numero Filter
1 3 "{\"value\":\"a23069\"}" - Apagar

1 1 "{
	\"nome\":\"Jorge Guimaraes\",
	\"numero\":\"a23069\",
	\"mes\":\"04\",
	\"dia\":\"11\",
	\"ano\":\"1996\",
	\"rua\":\"Travessa B\",
	\"codPostal\":\"4805-206\",
	\"localidade\":\"Longos\",
	\"n_porta\":\"82\",
	\"curso\":\"SEC\",
	\"n_curso\":\"A140\"
}" - Criar Aluno

2 1 "{\"nome\":\"SEC\",\"n_curso\":\"A141\"}" - Criar Curso

1 2 "{\"nome\":\"Jorge guimaraes\",\"dataDeNascimento\":\"2022-01-12\",\"numero\":\"a23063\",\"curso\":{\"nome\":\"NEC\",\"numero\":\"A169\"},\"morada\":{\"rua\":\"Travessa\",\"numero\":\"82\",\"codPostal\":\"4805-206\",\"localidade\":\"Longos\"}}" - Modificar Aluno
