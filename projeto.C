
//=======================================================
// Nome: Murilo Lameira da Silva    R.A: 22.120.008 - 2
// Nome: Guilherme Brigagão Cabelo  R.A: 22.120.071 - 0
// Data: 17/11/2020
//=============== Gerenciador Finaceiro =================

//=======================================================
//				           BIBLIOTECAS
//=======================================================
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <time.h>
//=======================================================
//				    DECLARAÇÃO DAS FUNÇOES 
//=======================================================
int Cadastro ();

int Menu ();

//=======================================================
//				  DECLARAÇÃO DAS VARIAVEIS
//=======================================================


//=======================================================
//				     PROGRAMA PRINCIPAL
//=======================================================
int main (void){
  //int opção = 0;
  Menu ();
		//printf("%d\n", &opção);
	
	
}//fecha o main


//=======================================================
//					        FUNÇÕES
//=======================================================
int Menu (){
  int opção = -1;

  printf("");
  printf("1 - Cadastro\n"); 
  printf("2 - Categorias\n");
  printf("3 - Relatório 12 meses\n");
  printf("4 - Relatório último mes\n");
  printf("5 - ");

  printf("0 - Sair\n");
  printf("o que deseja fazer?: ");
  scanf("%d",&opção);
  
  while(opção < 0 || opção > 4){
    switch(opção){
//-------- switch chama função 'Sair'  
      case 0:
          printf("Agradecemos a sua preferencia");
          printf("Volte sempre!!");
      break;
//---------------------------------------------------
//-------- switch chama função 'Cadastro'------------   
      case 1:
          Cadastro();
          printf("Cadastro");
      break;
//---------------------------------------------------
//-------- switch chama função 'Categorias'-----------
      case 2:
          //Categorias();
          printf("case 2");
      break;
//---------------------------------------------------
//-------- switch chama função 'Relatório 12 meses'--   
      case 3:
         //Relat12meses();
         printf("case 3");
      break;
//---------------------------------------------------
//-------- switch chama função 'Relatório Ultimo mes'  
      case 4:
          //RelatUltMes();
          printf("case 4");
      break;
//---------------------------------------------------  
    }
  }
  return 0;
}




int Cadastro (){

  FILE *arq;

  arq = fopen("NovaPessoa.txt", "w");

  fclose(arq);

}

