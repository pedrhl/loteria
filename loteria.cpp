#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>//necessário para a função time()
#include <locale.h>

#define VALIDO   1
#define INVALIDO 0

int sorteio[15];
int numero[15];
int _count = 0;

int sorteio_de_numeros();
int search (int array[], int valor, int count);

// ======================================================================================================================================================
int main(void){
	
    setlocale(LC_ALL, "Portuguese");

	int getnumber;
	int i, k, j, aux;
	int repeated_count, repeated[15] = {};
	
	printf("=============================== BEM VINDO A LOTERIAS PITÁGORAS =============================== \n\n");
	printf("-> POR FAVOR INSIRA OS NUMEROS DA SUA CARTELA, LEMBRE-SE : \n-> OS NUMEROS DEVERAM SER APENAS 15 E DE 1 A 25 SEM REPETIÇÕES. \n\n");

	for(i = 0; i < 15; i++){

		printf("INSIRA AQUI OS 15 NUMEROS: ");
		scanf("%i",&getnumber);

		if(getnumber < 1 || getnumber > 25){
            printf("NÚMERO INVALIDO, POR FAVOR INSIRA NOVAMENTE. \n\n");
            i--;
        }
        else if (search(numero, getnumber, i) == -1)
            numero[i] = getnumber;
        else{
            printf("NUMERO JÁ FOI INSERIDO. \n");
            i--;           
        } 
	}
	
	
    sorteio_de_numeros();
    
    
// ======================================================================================================================================================   

	printf("\n NUMEROS INSERIDOS PELO USUÁRIO: ");
    for(i = 1; i < 15; i++){
        aux = numero[i];
        for(j = i-1; j >=0 && aux < numero[j]; j--)
            numero[j+1] = numero[j];             
        numero[j+1] = aux;           
    }
    
    for(int k = 0; k < 15; k++)
     printf("%d ", numero[k]);
        printf("\n\n");
        
        
// ======================================================================================================================================================   
    printf("\n **************** VOCÊ ACERTOU %d NÚMEROS NA CARTELA ****************\n\n", _count);
    printf(" OS NUMEROS A QUAL VOCÊ ACERTO FORAM: ");
    
    repeated_count = 0;
  for(i = 0; i < 15; i++) {
    for(j = 0; j < 15 && sorteio[i] != numero[j]; j++); // É um for vazio apenas p/ percorrer o segundo array até encontrar um valor repetido.
    if (j < 15) {
      for(j = 0; repeated_count && j < repeated_count && sorteio[i] != repeated[j]; j++); // Verifica se já temos o valor na lista de números repetidos.
      if (j >= repeated_count) { // Neste ponto temos um número repetido que não está na lista de repetidos (novo número)
        repeated[repeated_count] = sorteio[i];
        repeated_count++;
      }
    }
  }
 
  if (!repeated_count) {
    printf("Não há números repetidos.");
  } else {
    for(i=0; i<repeated_count; i++)
      printf("%d ", repeated[i]);
  }
    printf("\n\n");
    
// ======================================================================================================================================================       
    if (_count <= 10){
        printf("VOCÊ ACERTOU MENOS QUE 11 NÚMEROS E NÃO GANHOU NADA. \n\n");
    }else if (_count == 11){
            printf("VOCÊ ACERTOU 11 E GANHOU R$ 4,00.\n\n");
        }else if (_count == 12){
                printf("VOCÊ ACERTOU 12 E GANHOU R$ 8,00.\n\n");
            }else if (_count == 13){
                    printf("VOCÊ ACERTOU 13 E GANHOU R$ 20,00\n\n");
                }else if(_count == 14){
                        printf("VOCÊ GANHOU 14 E GANHOU R$ 1.000,00\n\n");
                    }else if(_count == 15){
                            printf("PARABÉNS!!! VOCÊ ACERTOU 15 E GANHOU O PRÊMI0 MÁXIMO DE R$ 500.000,00\n\n");
                        }

     system ("pause");
     return 0;
}

// ======================================================================================================================================================

int sorteio_de_numeros () {

    int i, j, status;
    int aux;
    
	printf(" \n\n OS NÚMEROS SORTEADOS FORAM: ");
    srand(time(NULL));
    for (i = 0; i < 15; ++i) {
       do {
          sorteio[i] = 1 + rand() % 25;
          status = VALIDO;
          for (j = 0; j < i; ++j)
             if (sorteio[i] == sorteio[j])
                status = INVALIDO;
       } while (status == INVALIDO); 
       
       for(int k = 0; k < 15; k++)
            if(sorteio[i] == numero[k])
                _count++;  
	}
	for(i = 1; i < 15; i++){
        aux = sorteio[i];
        for(j = i-1; j >=0 && aux < sorteio[j]; j--)
            sorteio[j+1] = sorteio[j];             
        sorteio[j+1] = aux;           
    }
    
    for(int k = 0; k < 15; k++)
     printf("%d ", sorteio[k]);
    }


// ======================================================================================================================================================

int search (int array[], int valor, int count) {
    int indice;
    for(int i = 0; i < count; i++)
        if(array[i] == valor)
            return i;
    return -1;
}


		
