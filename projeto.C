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

int Relatorio12meses();

int RelatorioMes();

int saida();

//=======================================================
//            DECLARAÇÃO DAS VARIAVEIS
//=======================================================
int opção = -1;  //variavel para o menu
int categ = -1;  //variavel para a categoria
//=======================================================
//            PROGRAMA PRINCIPAL
//=======================================================
int main (void){
  Menu();
  scanf("%d*c",&opção);
  
while(opção >= 0 && opção <= 5){
    
  if (opção == 1){
    Cadastro();
    Menu();
    scanf("%d",&opção);
   
  }
  if (opção == 2){
      //Relatorio12meses();
    }
  if (opção == 3){
      //int RelatorioMes();
    }
  if (opção == 4){
      //em desenvolvimento
    }
  if (opção == 5){
      //ainda pensando
    }
  if (opção == 0){
    saida();
    break;
  }
  }
  return 0;
}

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

  return 0;
  }

//======================================================
//========= Função Cadastro ============================
struct cad{
  int declaracao;
  int valor;
  int debito;
  char data[20];
  char prejuizo[20];
  char lucro[20];
  char categoria[20];
  
};

int Cadastro (struct cad a){
  printf("Digite a data atual como no exemplo (01.02.2020): \n");
  scanf("%s",a.data);
  printf(" [1] Ganhou dinheiro?\n [2] Perdeu dinheiro?\nQual sua opção: ");
  scanf("%d*c\n", &a.declaracao);
  printf("----------------------------------------------\n");
  
  
  if (a.declaracao == 1){
    printf("Ganhou quanto hoje?: ");
    scanf("%s", a.lucro);
    printf("----------------------------------------------\n");
    printf("Com o que ganhou dinheiro hoje? \n");
    printf("Salario\n");
    printf("Vendas\n");
    printf("Outros\n");
    printf("----------------------------------------------\n");
    printf("Categoria: ");
    scanf("%s", a.categoria);
    printf("----------------------------------------------\n");
    FILE * ganhos = fopen("registro.txt","a");
    fprintf(ganhos,"%s\n", a.lucro);
    fprintf(ganhos,"%s\n", a.data);
    fprintf(ganhos,"%s\n\n",a.categoria);

    printf("Dados computados\n");
    
    fclose(ganhos);
  }
  else if (a.declaracao == 2){
    FILE * perda = fopen("registro.txt","a");
    printf("Perdeu quanto hoje? ");
    scanf("%s", a.prejuizo);
    printf("----------------------------------------------\n");
    printf("Com o que gastou seu dinheiro hoje? \n");
    printf("Alimentação\n");
    printf("Transporte\n");
    printf("Moradia\n");
    printf("Estudos\n");
    printf("Pessoal\n");
    printf("----------------------------------------------\n");
    printf("Categoria: ");
    scanf("%s", a.categoria);
    printf("----------------------------------------------\n");
    fprintf(perda, "-""%s\n", a.prejuizo);
    fprintf(perda,"%s\n", a.data);
    fprintf(perda,"%s\n\n",a.categoria);

    printf("Dados computados\n");
    
    fclose(perda);
  }
  else if (a.declaracao > 2 || a.declaracao < 1){
    printf("Você digitou uma opção inválida, volte para o menu e faço o processo novamente :) \n");

  }

  return 0;
}
//======================================================
//========= Função 12 Meses ============================
struct R12{
char teste[20];

};

int Relatorio12meses(struct R12 c){

  printf("ta funfando? ");
  scanf("%s", c.teste);
  return 0;
}



//======================================================


struct exit{
  int saida;
  char opiniao[100];
};

int saida(struct exit b){
  printf("Por favor avalie nosso sistema com uma nota de 0 até 10: \n");
  scanf("%d", &b.saida);

  if(b.saida >= 0 || b.saida <= 5 ){
    printf("Ainda estamos em desenvolvimento, poderia nós ajudar a melhorar?\n");
    printf("Deixe sua opinião aqui?\n");
    scanf("%s", b.opiniao);
    printf("Estaremos esperando você novamente!\n");
  }
  else if(b.saida > 5 && b.saida <= 8){
    printf("Obrigado pela sua nota!\n");
    printf("Deseja deixar sua opinao para futuros upgrades?\n");
    scanf("%s", b.opiniao);
    printf("Estaremos esperando você novamente!\n");
  }
  else if(b.saida > 8 && b.saida <= 10){
    printf("Estamos muito contentes com a sua avaliação! :)\n");
    scanf("%s", b.opiniao);
    printf("Estaremos esperando você novamente!\n");
  }
  else if(b.saida < 0 || b.saida > 10){
    printf("Infelizmente sua nota está fora dos nossos padrões");
  }
return 0;
}
