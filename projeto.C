//=======================================================
// Nome: Murilo Lameira da Silva    R.A: 22.120.008 - 2
// Nome: Guilherme Brigagão Cabelo  R.A: 22.120.071 - 0
// Data: 17/11/2020
//=======================================================
//            GERENCIADOR FINANCEIRO
//=======================================================

//=======================================================
//            BIBLIOTECAS
//=======================================================
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <time.h>
//=======================================================
//            DECLARAÇÃO DAS FUNÇOES 
//=======================================================
int Cadastro ();

int Menu ();

int Categoria();

int Relatorio12meses();

int RelatorioMes();

//=======================================================
//            DECLARAÇÃO DAS VARIAVEIS
//=======================================================
int opção = -1;

//=======================================================
//            PROGRAMA PRINCIPAL
//=======================================================
int main (void){
  Menu ();
  scanf("%d",&opção);
while(opção >= 0 && opção <= 5){  
  if (opção == 1){
    Cadastro();
    //Menu();
    //scanf("%d",&opção);
   
  }
  else if (opção == 2){
      //Categoria();
    }
  else if (opção == 3){
      //Relatorio12meses();
    }
  else if (opção == 4){
      //int RelatorioMes();
    }
  else if (opção == 5){
      //ainda pensando
    }
  else if (opção == 0){
      printf("Obrigado por escolher nosso gerenciador!\n");
      printf("Venha nos visitar novamente em breve :p\n\n");
      break;
    }
  return 0;
  }
}

	
	
//}//fecha o main


//=======================================================
//            FUNÇÕES
//=======================================================
int Menu (){
  //int opção = -1;

  printf("");
  printf("1 - Cadastro\n"); 
  printf("2 - Categorias\n");
  printf("3 - Relatório 12 meses\n");
  printf("4 - Relatório último mes\n");
  printf("5 - \n");

  printf("0 - Sair\n");
  printf("o que deseja fazer?: ");
  //scanf("%d",&opção);


 /* if (opção == 1){
    Cadastro();
  }
    else if (opção == 2){
        //Categoria();
    }
    else if (opção == 3){
        //Relatorio12meses();
    }
    else if (opção == 4){
        //int RelatorioMes();
    }
    else if (opção == 5){
        //ainda pensando
    }
    else if (opção == 0){
      printf("Obrigado por escolher nosso gerenciador!");
      printf("Venha nos visitar novamente em breve :p");
    }
    else {
      printf("Opção invalida!!");
    }*/
  }

struct cad{
  int declaracao;
  int valor;
  int debito;
  char prejuizo[20];
  char lucro[20];
  
};

int Cadastro (struct cad a){
  
  printf("Eai ganhou dinheiro hoje?\n 1: Ganhou\n 2: Perdeu \n");
  scanf("%d\n", &a.declaracao);
  
  if (a.declaracao == 1){
    printf("Ganhou quanto hoje?: \n");
    scanf("%s", a.lucro);
    FILE * ganhos = fopen("ganhos.txt","a");
    fprintf(ganhos,"%s", a.lucro);
    printf("dados computados\n");

    fclose(ganhos);
  }
  if (a.declaracao == 2){
    FILE * perda = fopen("perdas.txt","a");
    printf("Perdeu quanto hoje?: \n");
    scanf("%s", a.prejuizo);
    fprintf(perda, "%s", a.prejuizo);
    printf("dados computados\n");
    
    fclose(perda);
  }



}
