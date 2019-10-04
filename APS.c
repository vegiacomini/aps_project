#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 8

void menu1(int vetor[]){
   int i;

   for(i=0;i<8;i++){
     srand(time(NULL)+1);
     vetor[i]=rand()%100;
   }

}

void elimina(int vetor[], int n){
   vetor[n]=0;
}

void bubblesort(int vetor[], int n){

  int c, d, swap;
  for (c = 0 ; c < n - 1; c++) {
    for (d = 0 ; d < n - c - 1; d++) {
       if (vetor[d] > vetor[d+1]) {
          swap=vetor[d];
          vetor[d]=vetor[d+1];
          vetor[d+1]=swap;
         }
       }
    }
}

int moda(int vetor[]){

  int cont, moda, j, k;
  cont = 0;
  moda = 0;
  for(j=0;j<8;j++){
    for(k=j+1;k<8;k++){
      if(vetor[j]==vetor[k]){
        cont=cont+1;
      }
      if(cont>moda){
        moda=vetor[j];
      }
    }
  }
  if(cont==0){
    printf("\nNenhum numero se repete no Vetor 1.");
  }

   return moda;
}

int main(){

  int vetor1[MAX], vetor2[MAX], i, opcao, sair, aux, aux2, j, k, moda, cont;
  printf("\n\n");

sair = 1;
while(sair==1){
  printf("\n\n======== CALCULADORA DE VETORES ========\n 1 – Gerar vetores\n 2 – Imprimir vetores\n 3 – Eliminar elemento do vetor\n 4 – Pesquisar elemento nos vetores\n 5 – Ordenar os vetores\n 6 – Calcular operações matemáticas\n 7 – Calcular métodos estatísticos\n 8 – Total de elementos válidos\n 9 - Sair\n ===================================\n Escolha a sua opção: ");
  scanf("%d", &opcao);

  switch(opcao){

  case 1:
         menu1(vetor1);
         menu1(vetor2);
        break;

  case 2:
       printf("Vetor 1\n[ ");
       for(i=0;i<8;i++){
         printf("%d ", vetor1[i]);
       }
       printf("]\n");
       printf("Vetor 2\n[ ");
       for(i=0;i<8;i++){
         printf("%d ", vetor2[i]);
       }
       printf("]\n");
        break;

   case 3:
       printf("Escolha o vetor que deseja editar: ");
       scanf("%d", &aux);
       if(aux==1){
         printf("Qual posicao do vetor deseja apagar? ");
         scanf("%d", &aux);
         if(aux<8){
           elimina(vetor1, aux);
         } else { printf("Posicao do vetor nao eh valida! Tente de novo.\n");}
       } else if(aux==2){
         printf("Qual posicao do vetor deseja apagar? ");
         scanf("%d", &aux);
         if(aux<8){
           elimina(vetor2, aux);
         } else { printf("Posicao do vetor nao eh valida! Tente de novo.\n");}
       } else { printf("Vetor nao eh valido!\n"); }
       break;

   case 4:
       printf("Digite o valor que deseja procurar: ");
       scanf("%d", &aux);

       for(i=0; i<8; i++){
         if(vetor1[i]==aux){
           printf("O valor procurado %d se encontra na posicao %d do Vetor 1\n", aux, i);
           aux2 = 1;
         }
       }
       for(i=0; i<8; i++){
         if(vetor2[i]==aux){
           printf("O valor procurado %d se encontra na posicao %d do Vetor 2\n", aux, i);
           aux2 = 1;
         }
       }
       if(aux2!=1){ printf("O valor %d nao foi encontrado em nenhum dos vetores!\n", aux); }
       aux2 = 0;
       break;

     case 5:
          bubblesort(vetor1, 8);
          bubblesort(vetor2, 8);

          printf("Vetor 1\n[ ");
          for(i=0;i<8;i++){
            printf("%d ", vetor1[i]);
          }
          printf("]\n");
          printf("Vetor 2\n[ ");
          for(i=0;i<8;i++){
            printf("%d ", vetor2[i]);
          }
          printf("]\n");
          break;

      case 6:
          printf("SOMA\n");
          for(i=0;i<8;i++){
            printf("[%i]+[%i]=[%i]\n", vetor1[i], vetor2[i], vetor1[i]+vetor2[i]);
          }
          printf("\nSUBTRACAO\n");
          for(i=0;i<8;i++){
            printf("[%i]-[%i]=[%i]\n", vetor1[i], vetor2[i], vetor1[i]-vetor2[i]);
          }
          printf("\nMULTIPLICACAO\n");
          for(i=0;i<8;i++){
            printf("[%i]*[%i]=[%i]\n", vetor1[i], vetor2[i], vetor1[i]*vetor2[i]);
          }
          printf("\nDIVISAO\n");
          for(i=0;i<8;i++){
            if(vetor2[i]!=0){
            printf("[%i]/[%i]=[%i]\n", vetor1[i], vetor2[i], vetor1[i]/vetor2[i]);
          } else{
            printf("[%i]/[%i]= Impossivel Dividir\n", vetor1[i], vetor2[i]);
          }
          }
          break;

       case 7:
           bubblesort(vetor1, 8);
           bubblesort(vetor2, 8);

           printf("\nA mediana do vetor 1 eh: %d", (vetor1[3]+vetor1[4])/2);
           printf("\nA mediana do vetor 2 eh: %d", (vetor2[3]+vetor2[4])/2);

           cont = 0;
           moda = 0;
           for(j=0;j<8;j++){
             for(k=j+1;k<8;k++){
               if(vetor1[j]==vetor1[k]){
                 cont=cont+1;
               }
               if(cont>moda){
                 moda=vetor1[j];
               }
             }
           }
           if(cont==0){
             printf("\nNenhum numero se repete no Vetor 1.");
           }
           else {printf("\nA moda do Vetor 1 eh: %d", moda);}


           cont = 0;
           moda = 0;
           for(j=0;j<8;j++){
             for(k=j+1;k<8;k++){
               if(vetor2[j]==vetor2[k]){
                 cont=cont+1;
               }
               if(cont>moda){
                 moda=vetor2[j];
               }
             }
           }
           if(cont==0){
             printf("\nNenhum numero se repete no Vetor 2.");
           }
           else {printf("\nA moda do Vetor 2 eh: %d", moda);}

           break;

           case 8:

           cont = 0;
           for(i=0; i<8; i++){
             if(vetor1[i]<1 || vetor1[i]>500){
               cont = cont + 1;
             }
           }
           printf("\nO numero de elementos validos no Vetor 1 eh: %d", 8-cont);

           cont = 0;
           for(i=0; i<8; i++){
             if(vetor2[i]<1 || vetor2[i]>500){
               cont = cont + 1;
             }
           }
           printf("\nO numero de elementos validos no Vetor 2 eh: %d", 8-cont);

           break;
          case 9:
          sair = 0;
          break;
}
}
  printf("\n\n");
  return 0;
}
