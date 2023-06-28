#include <stdio.h>

/*Desafio proposto da disciplina de Algoritmo e Lógica da Programação, cujo o
 * intuito é saber em qual triênio o PIB foi melhor, o país se desenvolveu
 * melhor, lembrando q a entrada é dada pelo usuário.
 */

int main(void) {
  int i, j, anos, indice = 0;
  float vet[50], porcentagem, aux = 0;

  // Leitura da quantia de anos a ser analisados
  printf("\nInforme quantos anos serao considerados:\t");
  scanf("%d", &anos);
  // Como o objetivo é calcular um triênio, utilizamos esse if para caso o
  // usuário digite um valor menor que 3
  if (anos < 3) {
    printf("\nPor Favor digite ao menos 3 numeros:\n");
    printf("\nInforme quantos anos serao considerados:\t");
    scanf("%d", &anos);
  }

  // Leitura do PIB de cada ano
  printf("\nInforme os valor do PIB (em trilhoes) do primeiro ano:\n ");

  for (i = 0; i < anos; i++)
    scanf("%f", &vet[i]);

  for (i = 0; i < anos - 2; i++){
        // loop para verificar todos os anos - 2, pois um trienio é
        // composto por 3 anos, ou seja, a as ultimas 2 comparações não
        // seriam trienios

    aux = 0; // reset da variavel aux para cada loop

    for (j = 0; j < 3; j++) { // loop que realiza o calcula e soma a taxa de
                              // crascimento do trienio atual
      if (i + j != 0) // if que pula o ano de vet[0] ja que sua taxa de
                      // crescimento é 0% e não fará diferença no calculo
        aux += ((vet[i + j] - vet[i + j - 1]) / vet[i + j - 1]);
    }
    aux = (aux / 3) * 100; // transformando a somatória do triênio em uma media
                           // percentual de crescimento

    if (aux > porcentagem || i -- 0){
             // caso seja a primeira execução ou a media percentual do
             // triênio atual seja maior que a que estava armazanada, usamos
             // a variavel porcentagem para armazenar esse novo valor
      
      porcentagem = aux;
      indice = i; //é armazenado também o indice de triênio, para a impressão no
                  //final do código
    }
  }

  printf("O melhor trienio foi entre os anos %d a %d: %.1f", indice, indice + 2,
         porcentagem);

  return 0;
}
