# Thread Manipulation

Manipulação de Matrizes/Vetores utilizando conceitos de theads.

Compilar:

` g++ -std=c++11 <nome_dos_arquivos>.c lib/<nome_dos_arquivos>.h -o exec/executavel -lpthread`

## Q1
Dado duas matrizes quadradas de tamanho m, deve-se criar m trheads para efetuar a multiplicação entre as matrizes e retornar a matriz resultante, calculo realizado segundo descrição [aqui](http://mundoeducacao.bol.uol.com.br/matematica/multiplicacao-matrizes.htm)

Executar:

` .exec/executavel 'm' | 'm' ∈ N > 0 `


## Q2
Resolver o problema do "produtor-consumidor" assumindo que:
* O tamanho do buffer é passado por parâmetro (argc, argv)
* Existem 5 threads:

	3 consumidoras e 2 produtoras

* Garantindo exclusão mútua no acesso ao buffer, independentemente se a thread é consumidora ou produtora
* Fazendo com que:

	Qualquer thread produtora que tente escrever no buffer quando cheio durma e acorde quando o buffer tiver pelo menos uma posição livre

	Qualquer thread consumidora que tente ler no buffer quando vazio durma e acorde quando o buffer tiver pelo menos um elemento dentro dele.

Executar:

` .exec/executavel 'm' | 'm' ∈ N > 0 `

## Q3
Resolver o problema dos "leitores-escritores", recebendo 2 valores de parâmetros referente a quantidade de leitores e escritores respectivamente, assumindo que:
* Existe uma base de dados representada por uma variável inteira:

	Leitores lêem-a, Escritores incrementam-a.

* Garantindo exlusão de escrita:

	Quando um gravador precisa ter acesso à base de dados, ele o faz de maneira exclusiva (i.e. nenhum outro leitor ou gravador tem acesso).

	Quando um leitor precisa ter acesso à base de dados, outros leitores podem fazê-lo ao mesmo tempo. Entretanto, caso UM escritor queira ter acesso, nenhum leitor pode fazê-lo.

Executar:

` .exec/executavel 'm' 'n' | 'm','n' ∈ N > 0 `