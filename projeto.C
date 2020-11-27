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
 
int Resetar(); 

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
    saldo();
    Menu();
    scanf("%d",&opção);

    }
  if (opção == 3){
    RelatorioMes();
    Menu();
    scanf("%d",&opção);
    }
  if (opção == 4){
    Relatorio12meses();
    Menu();
    scanf("%d",&opção);
  }
  if (opção == 5){
      Resetar();
      Menu();
      scanf("%d",&opção);
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
  

  printf("----------------------------------------------\n");
  printf("[1] - Cadastro\n"); 
  printf("[2] - Saldo\n");
  printf("[3] - Relatório último mes \n");
  printf("[4] - Relatório Anual\n");
  printf("[5] - Deletar todos os dados\n");

  printf("[0] - Sair\n");
  printf("----------------------------------------------\n");
  printf("O que deseja fazer?: ");
  

  return 0;
  }

//======================================================
//========= Função Cadastro ============================
struct cad{
  int declaracao;
  int valor;
  int debito;
  char data[100];
  char prejuizo[100];
  char lucro[100];
  char categoria[100];
  char saldoT[40];
  char total[40];
  
};

int Cadastro (struct cad a){
  printf("Digite a data atual como no exemplo (01.02.2020): \n");
  scanf("%s",a.data);
  printf(" [1] Ganhou dinheiro?\n [2] Perdeu dinheiro?\nQual sua opção: ");
  scanf("%d*c\n", &a.declaracao);
  printf("----------------------------------------------\n");
  int aux = 0;
  
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
    printf("----------------------------------------------\n");
    FILE *abrir = fopen("saldo.txt","a");
    fclose(abrir);

    FILE * ler = fopen("saldo.txt","r");
    int i = 0;
    while( fgets(a.saldoT ,40 , ler) != NULL ){   
      i++;
      
    }

      float valor = atof(a.saldoT);
      float lucro = atof(a.lucro);

      float total = valor + lucro;
      
      
      
      FILE *arq = fopen("saldo.txt","w");
      fprintf(arq, "%.2f", total);
      fclose(arq);

     
    fclose(ler);
    
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
    printf("Pessoais\n");
    printf("----------------------------------------------\n");
    printf("Categoria: ");
    scanf("%s", a.categoria);
    printf("----------------------------------------------\n");
    fprintf(perda, "-""%s\n", a.prejuizo);
    fprintf(perda,"%s\n", a.data);
    fprintf(perda,"%s\n\n",a.categoria);

    printf("Dados computados\n");

    FILE *abrir = fopen("saldo.txt","a");
    fclose(abrir);
    FILE * ler = fopen("saldo.txt","r");
    int i = 0;
    while( fgets(a.saldoT ,40 , ler) != NULL ){   
      i++;
      
    }

      float valor = atof(a.saldoT);
      float prejuizo = atof(a.prejuizo);

      float total = valor - prejuizo;
      
      
      
      FILE *arq = fopen("saldo.txt","w");
      fprintf(arq, "%.2f", total);
      fclose(arq);
    
    fclose(perda);
  }
  else if (a.declaracao > 2 || a.declaracao < 1){
    printf("Você digitou uma opção inválida, volte para o menu e faça o processo novamente :) ");

  }

  return 0;
  
}

//======================================================
//========= Função Saldo ============================
struct saldo{
  char saldoT[100];
  
};
int saldo(struct saldo a){
  int i = 0;

  FILE * ler = fopen("saldo.txt","r");
  while( fgets(a.saldoT ,40 , ler) != NULL ){   
  i++;
  
  }
  printf("Seu saldo atualmente é de: R$");
  printf("%s\n",a.saldoT);
  
  fclose(ler);
return 0;
}

//======================================================
//========= Função 12 Meses ============================
struct R12{
char ano1[20];
char mes1[20];

};

int Relatorio12meses(struct R12 c){
  printf("Digite o Ano\n");
  scanf("%s",c.ano1);
  printf("Digite o Mês que deseja: \n");
  scanf("%s",c.mes1);
  FILE* relat = fopen ("Registro.txt", "r");
  FILE* relhtml = fopen("RelatAnual.html", "w");
  fprintf(relhtml,"");
 
  return 0;
}



//======================================================
//========= Função Mes =================================
struct Mes{
  char ano[100];
  char mes[100];
};
int RelatorioMes(struct Mes e){ 
  printf("Digite o Ano\n");
  scanf("%s",e.ano);
  printf("Digite o Mês que deseja: \n");
  scanf("%s",e.mes);
  FILE* relat = fopen ("Registro.txt", "r");
  FILE* relhtml = fopen("RelatMes.html", "w");
  fprintf(relhtml,"\n");


return 0;
}
//======================================================
//========== Função Saída ==============================


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
//=======================================================
//====== Função Reseta ==================================
struct apaga{
  int del;
};

int Resetar(struct apaga g){
 printf(" [1] - SIM\n [2] - NÃO\nRealmenente deseja apagar todos os dados? ");
 scanf("%d", &g.del);
 printf("----------------------------------------------\n");

  if(g.del == 1){
    remove("registro.txt");
    remove("saldo.txt");
    remove("RelatMes.html");
    printf("Todos dados deletados\n");
  }
  else if(g.del == 2){
      Menu();
      scanf("%d",&opção);

  }
  else{
    printf("Opção invalida");
  }


return 0;  
}
//=======================================================
//====== Função cria html anual =========================

int HtmlAnual(){
  FILE* relhtml = fopen("RelatAnual.html", "w");
  fprintf(relhtml,"<!DOCTYPE html>\n<html lang='en'>\n");
  fprintf(relhtml,"<head>\n<meta charset='UTF-8'>\n<meta name='viewport' content='widht=devide-widhtinitial-scale=1.0'>\n<meta http-equi='X-UA-Compatible' content='ie=edge'>\n<title>Grafico Anual</title>\n</head>\n");
  
  fprintf(relhtml,"<body>\n<canvas class='line-chart'></canvas>\n<script src='https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.5.0/Chart.min.js'>\n</script>\n");
  
  fprintf(relhtml,"<script>\nvar ctx = document.getElementsByClassName('line-chart');\nvar myDoughnutChart = new Chart(ctx, {type: 'line', data: {labels: ['Janeiro', 'Fevereiro', 'Março', 'Abril', 'Junho', 'Julho', 'Agosto', 'Setembro', 'Outubro', 'Novembro', 'Dezembro'],\ndatasets: [{label: 'Alimentação', data: [535, 874, 482, 682, 572, 919, 192, 128, 791, 892, 472, 293, 939, 138],\nborderWidth: 6,\nborderColor: 'rgba(50, 115, 220,0.90)',\nbackgroundColor: 'transparent',},"); 
  fprintf(relhtml,"{label: 'Transporte', data: [150, 75, 97, 689, 572, 910, 719, 182, 789, 189, 942, 823, 989, 938],\nborderWidth: 6,\nborderColor: 'rgba(6,204,6,0.85)',\nbackgroundColor: 'transparent',\n},");
  fprintf(relhtml,"{label: 'Moradia', data: [600, 780, 970, 689, 572, 910, 719, 482, 789, 589, 642, 723, 489, 538],\nborderWidth: 6,\nborderColor: 'rgba(77,166,253,0.85)',\nbackgroundColor: 'transparent',\n},");
  fprintf(relhtml,"{label: 'Estudos', data: [100, 78, 97, 189, 72, 91, 79, 82, 89, 99, 64, 72, 89, 58],\nborderWidth: 6,\nborderColor: 'rgba(220, 70, 70,.60)',\nbackgroundColor: 'transparent',\n},");
  fprintf(relhtml,"{label: 'Pessoais', data: [800, 978, 597, 489, 772, 391, 579, 282, 389, 399, 264, 372, 289, 358],\nborderWidth: 6,\nborderColor: 'rgba(225, 0, 0,.60)',\nbackgroundColor: 'transparent',}]}});\n</script>\n");
  fprintf(relhtml,"</body>\n");
  fprintf(relhtml,"</html>\n");

  fclose(relhtml);
return 0;
}

//=======================================================
//====== Função cria html mensal ========================
int HtmlMensal(){
  FILE* relatoriohtml = fopen("RelatMes.html", "w");
  fprintf(relatoriohtml,"<!DOCTYPE html>\n<html lang='en'>\n<head>\n<meta charset='UTF-8'>\n<meta name='viewport' content='widht=devide-widht, initial-scale=1.0'>\n<meta http-equi='X-UA-Compatible' content='ie=edge'>\n<title>Grafico Mensal</title>\n</head>\n ");
  fprintf(relatoriohtml,"<body>\n<canvas class='line-chart'></canvas>\n<script src='https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.5.0/Chart.min.js'></script>\n<script>\nvar ctx = document.getElementsByClassName('line-chart');\nvar myDoughnutChart = new Chart(ctx, {\ntype: 'line',\ndata: {\nlabels: ['Alimentação', 'Transporte',\n 'Moradia', 'Estudos', 'Pessoais'],\ndatasets: [{\nlabel: 'SEU GASTO MENSAL',\ndata: [535, 874, 482, 682, 572, 919, 192, 128],\nborderWidth: 6,\nborderColor: 'rgba(77,166,253,0.85)',\nbackgroundColor: 'transparent',\n}]}});\n</script>\n ");
  
  
  fclose(relatoriohtml);
return 0;
}
//=======================================================

