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
