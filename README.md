# Trabalho-Ipca
<h2> Trabalho Final de programação do ETesp de SEC do IPCA </h2>


<b>Exemplos de payloads enviados como argumentos através do front</b>

- Alunos por Curso Filter:<br>
<pre>1 0 "{\"prop\":8,\"value\":\"data\"}"</pre> 

 - Alunos por Nome Filter:<br>
<pre>1 0 "{\"prop\":0,\"value\":\"Jorge\"}"</pre>

- Aluno por Numero Filter:<br>
<pre>1 0 "{\"prop\":2,\"value\":\"data\"}"</pre> 

 - Apagar:<br>
<pre>1 3 "{\"value\":\"n_aluno\"}"</pre>

 - Criar Aluno:<br>
<pre>1 1 "{\"nome\":\"Jorge Guimaraes\",\"numero\":\"a23062\",\"mes\":\"04\",\"dia\":\"11\",\"ano\":\"1996\",
\"rua\":\"data\",\"codPostal\":\"data-data\",\"localidade\":\"data\",
\"n_porta\":\"data\",\"curso\":\"SEC\",\"n_curso\":\"A140\"}"</pre>

- Criar Curso:<br>
<pre>2 1 "{\"nome\":\"data\",\"n_curso\":\"data\"}"</pre>

- Modificar Aluno:<br>
<pre>1 2 "{\"nome\":\"Jorge\",\"numero\":\"data\",\"mes\":\"data\",\"dia\":\"data\",\"ano\":\"data\",
\"rua\":\"data\",\"codPostal\":\"foiwefoh\",\"localidade\":\"oiewifjoi\",\"n_porta\":\"data\",
\"curso\":\"data\",\"n_curso\":\"data\",\"oldNumero\":\"data\"}"</pre>
