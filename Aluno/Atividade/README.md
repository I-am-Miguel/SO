# Matriz and Thread

Manipulação de matrizes utilizando os conceitos de theads.

Compilar:

` g++ -std=c++11 <nome_dos_arquivos>.c lib/<nome_dos_arquivos>.h -o exec/executavel -lpthread`


# Q1
Dado duas matrizes quadradas de tamanho m, deve-se criar m trheads para efetuar a multiplicação entre as matrizes e retornar a matriz resultante, calculo realizado segundo descrição [aqui](http://mundoeducacao.bol.uol.com.br/matematica/multiplicacao-matrizes.htm)

Executar:

` .exec/executavel 'm', 'm' ∈ N > 0 `


# Q2
Resolver o problema do "produtor consumidor" assumindo que:
* O tamanho do buffer é passado por parâmetro (argc, argv)
* Existem 5 threads:

	3 consumidoras e 2 produtoras

* Garantindo exclusão mútua no acesso ao buffer, independentemente se a thread é consumidora ou produtora e;
* Fazendo com que:
	
	Qualquer thread produtora que tente escrever no buffer quando cheio durma e acorde quando o buffer tiver pelo menos uma posição livre
	
	Qualquer thread consumidora que tente ler no buffer quando vazio durma e acorde quando o buffer tiver pelo menos um elemento dentro dele.
