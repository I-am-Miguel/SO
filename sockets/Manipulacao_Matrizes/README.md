# Troca de mensagens

Manipulação de Matrizes utilizando conceitos de Sockets.

## Q1
Dado duas matrizes quadradas de tamanho 3, deve-se criar 3 escravos para efetuar a multiplicação entre as matrizes e retornar a matriz resultante, cada escravo deve receber uma linha da primeira matriz e toda a segunda matriz retornando assim o valor referente a sua linha, o mestre após receber as linhas dos escravos deve montar a matriz resultante, calculo realizado segundo descrição [aqui](http://mundoeducacao.bol.uol.com.br/matematica/multiplicacao-matrizes.htm)

Compilar:

` g++ -std=c++11 multiplicaMatriz_mestre.c matriz_util.c lib/*.h -o mestre `

` g++ -std=c++11 multiplicaMatriz_escravo.c matriz_util.c lib/*.h -o escravo `


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