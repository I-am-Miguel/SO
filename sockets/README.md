# Troca de mensagens

Manipulação de Matrizes/Vetores utilizando conceitos de Sockets.

Compilar:

` gcc  soma_vetor_escravo.c -o escravo `
` gcc  soma_vetor_mestre.c -o mestre `

## Q1
Desenvolver 2 programas C sendo:
* Um chamado de soma_vetor_mestre que envia a 'n' escravos vetores de inteiros com 'm' elementos cada e em seguida aguarda de cada escravo um valor inteiro correspondente a soma do vetor e os imprime na tela.

* Um chamado de soma_vetor_escravo que recebe do mestre o vetor de inteiros de 'm' elementos e calcula a soma de todos estes elementos. Em seguida, envia de volta ao mestre o valor resultante.

Executar:

` ./escravo 'p' | 'p' ∈ {Port}`

` ./mestre 'P' 'm' 'n' `

* 'P' o número inicial do intervalo de portas disponíveis que serão usadas pelos escravos ex: 5555
* 'm' 'n' ∈ N > 0 | 'm' o tamanho do vetor a ser enviado e 'n' a quantidade de escravos criados o valor 'P'
