# Troca de mensagens

Manipulação de Matrizes utilizando conceitos de Sockets.


Compilar:

` g++ -std=c++11 multiplicaMatriz_mestre.c matriz_util.c lib/*.h -o mestre `

` g++ -std=c++11 multiplicaMatriz_escravo.c matriz_util.c lib/*.h -o escravo `



## Q1
Dado duas matrizes quadradas de tamanho 3, deve-se criar 3 escravos para efetuar a multiplicação entre as matrizes e retornar a matriz resultante, cada escravo deve receber uma linha da primeira matriz e toda a segunda matriz retornando assim o valor referente a sua linha, o mestre após receber as linhas dos escravos deve montar a matriz resultante, calculo realizado segundo descrição [aqui](http://mundoeducacao.bol.uol.com.br/matematica/multiplicacao-matrizes.htm)

Executar:

` ./escravo 'p' `
` ./escravo 'p+1' `
` ./escravo 'p+2' `

` ./mestre 'p' `

* 'p' o número inicial do intervalo de portas disponíveis que serão usadas pelos escravos ex: 5555

## Q2
Solução similar ao programa anterior, no entanto o mestre deve receber por argumentos o tamanho da matriz e consequentemente a quantidade de escravos ou seja

Executar:

` ./escravo 'p' `
...
` ./escravo 'p'+'(n-1)' `

` ./mestre 'p' 'n'`

* 'p' o número inicial do intervalo de portas disponíveis que serão usadas pelos escravos ex: 5555
* 'n' o tamanho da matriz e quantiade de escravos a serem criados

## Q3
Solução similar ao programa anterior, no entanto apenas um escravo deve ser criado, recebendo por argumentos o tamanho da matriz, o mestre deve enviar a informação sobre a quantidade de THREADS necessárias para execução, cada THREAD criada pelo escravo deve efetuar os calculos das questões anteriores.

Executar:

` ./escravo 'p' `

` ./mestre 'p' 'n'`

* 'p' o número inicial do intervalo de portas disponíveis que serão usadas pelos escravos ex: 5555
* 'n' o tamanho da matriz, a quantiade de THREADS que o escravo deverá criar

* obs: para compilar este código deverá ser adicionado a flag "-lpthread" após a instrução "-o mestre" e "-o escravo"