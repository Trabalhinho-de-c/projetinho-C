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
int  Cadastro ();

int  Menu ();

int  saldo();

int  Relat12meses();

int  Relatorio1mes();

int  saida();

int  Resetar();

int  HtmlAnual();

int  HtmlMensal();

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
  FILE *abrir = fopen("saldo.txt","a");
  fclose(abrir);
  FILE * ganhos = fopen("registro.txt","a");
  fclose(ganhos);
  
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
    Relatorio1mes();
    Menu();
    scanf("%d",&opção);
    }
  if (opção == 4){
    Relat12meses();
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
  if(opção > 5 || opção < 0){
    printf("opção invalida\n");
    printf("Por favor digitar uma opção valida\n");
    Menu();
    scanf("%d",&opção);
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
  printf("Digite a data atual como no exemplo (01/02/20): \n");
  scanf("%s",a.data);
  printf(" [1] Ganhou dinheiro?\n [2] Perdeu dinheiro?\nQual sua opção: ");
  scanf("%d*c\n", &a.declaracao);
  printf("----------------------------------------------\n");
  int aux = 0;
  
  if (a.declaracao == 1){
    
    printf("Ganhou quanto hoje?: ");
    scanf("%s", a.lucro);
    printf("----------------------------------------------\n");
    printf("Como ganhou dinheiro hoje? \n");
    printf(" salario\n");
    printf(" vendas\n");
    printf(" outros\n");
    printf("----------------------------------------------\n");
    printf("Categoria: ");
    scanf("%s", a.categoria);
    if ((strcmp(a.categoria, "salario") != 0) && (strcmp(a.categoria, "vendas") != 0) && (strcmp(a.categoria, "outros") != 0)){
      puts("Categoria inválida! ");
			puts("Volte ao menu novamente!!");
      return 0;
      
  }
    printf("----------------------------------------------\n");
    FILE * ganhos = fopen("registro.txt","a");
    fprintf(ganhos,"%s\n", a.lucro);
    fprintf(ganhos,"%s\n", a.data);
    fprintf(ganhos,"%s\n\n",a.categoria);
    fclose(ganhos);
    printf("Dados Computados\n");
    printf("----------------------------------------------\n");
    
    FILE * ler = fopen("saldo.txt","r");
    int i = 0;
    while( fgets(a.saldoT ,40 , ler) != NULL ){   
      i++;
      
    }
    fclose(ler);
    
      float valor = atof(a.saldoT);
      float lucro = atof(a.lucro);

      float total = valor + lucro;
      
      FILE *arq = fopen("saldo.txt","w");
      fprintf(arq, "%.2f", total);
      fclose(arq);
  
  }
  else if (a.declaracao == 2){
    FILE * perda = fopen("registro.txt","a");
    printf("Perdeu quanto hoje? ");
    scanf("%s", a.prejuizo);
    printf("----------------------------------------------\n");
    printf("Com o que gastou seu dinheiro hoje? \n");
    printf(" alimentação\n");
    printf(" transporte\n");
    printf(" moradia\n");
    printf(" estudos\n");
    printf(" pessoais\n");
    printf("----------------------------------------------\n");
    printf("Categoria: ");
    scanf("%s", a.categoria);
      if ((strcmp(a.categoria, "alimentação") != 0) && (strcmp(a.categoria, "transporte") != 0) && (strcmp(a.categoria, "moradia") != 0) && (strcmp(a.categoria, "estudos") != 0) && (strcmp(a.categoria, "pessoais") != 0)){
        puts("Categoria inválida! ");
			     puts("Volte ao menu novamente!!");
        return 0;
      }

    printf("----------------------------------------------\n");
    fprintf(perda, "-""%s\n", a.prejuizo);
    fprintf(perda,"%s\n", a.data);
    fprintf(perda,"%s\n\n",a.categoria);
    
    printf("Dados Computados\n");

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
    puts("Você digitou uma opção inválida :) ");
    puts("Volte ao menu e faça o processo novamente!");
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
  fclose(ler);
  printf("Seu saldo atualmente é de: R$");
  printf("%s\n",a.saldoT);
 
  return 0;
}

//======================================================
//========= Função 12 Meses ============================
struct R12{
char aux[200][20];
char auxano[10];
int anoCL;
char auxmes[10];
int mesCL;
};

int Relat12meses(struct R12 c){ 

  printf("Digite o Ano em quer procurar: ex: (20)\n");
  scanf("%d",&c.anoCL);
  if(c.anoCL > 99 || c.anoCL <0){
    puts("Você digitou um ano invalido ");
    puts("Volte para o menu novamente!!");
    return 0;
  }
  
  

  char moradiaS[15]="moradia";
  char alimentacaoS[15]="alimentação";
  char trasnporteS[15]="transporte";
  char estudoS[15] = "estudos";
  char salarioS[15] = "salario";
  char vendasS[15] = "vendas";
  char outrosS[15] = "outros";
  char pessoaisS[15] = "pessoais";

  int i = 0;
  int j = 0;
  int ano = 0;
  int mes = 0;
  float PorMes1 = 0;
  float PorMes2 = 0;
  float PorMes3 = 0;
  float PorMes4 = 0;
  float PorMes5 = 0;
  float PorMes6 = 0;
  float PorMes7 = 0;
  float PorMes8 = 0;
  float PorMes9 = 0;
  float PorMes10 = 0;
  float PorMes11 = 0;
  float PorMes12 = 0;
  
  	FILE * ler = fopen("registro.txt","r");
    while( fgets(c.aux[i] ,20 , ler) != NULL ){
    i++;
    
  }
  fclose(ler);
    
    for(j=0; j!=i; j++){

    c.auxmes[0] = c.aux[j][3];
    c.auxmes[1] = c.aux[j][4];
    c.auxmes[2] = '\0';

    c.auxano[0] = c.aux[j][6];
    c.auxano[1] = c.aux[j][7];
    c.auxano[2] = '\0';

    ano = atoi(c.auxano);
    mes = atoi(c.auxmes);
    
      if(ano==c.anoCL && (mes == 1 || mes == 2 || mes == 3||mes == 4 || mes == 5 || mes == 6 || mes == 7  || mes == 8 || mes == 9 || mes == 10 || mes == 11 || mes == 12)){
        float moradia=0;
        float alimentacao=0;
        float transporte=0;
        float estudos=0;
        float pessoais=0;
        float salario=0;
        float vendas=0 ; 
        float outros = 0;
        
        if (strstr(c.aux[j+1],moradiaS) != NULL){
          moradia = moradia + atof(c.aux[j-1]);
        }
        if (strstr(c.aux[j+1],alimentacaoS) != NULL){
          alimentacao = alimentacao + atof(c.aux[j-1]);
        }
        if (strstr(c.aux[j+1],trasnporteS) != NULL){
          transporte = transporte + atof(c.aux[j-1]);
        }
        if (strstr(c.aux[j+1],estudoS) != NULL){
          estudos = estudos + atof(c.aux[j-1]);
        }
        if (strstr(c.aux[j+1],vendasS) != NULL){
          vendas = vendas + atof(c.aux[j-1]);
        }
        if (strstr(c.aux[j+1],salarioS) != NULL){
          salario = salario + atof(c.aux[j-1]);
        }
        if (strstr(c.aux[j+1],outrosS) != NULL){
          outros = outros + atof(c.aux[j-1]);
        }

        float tot = moradia + alimentacao + transporte + estudos + vendas + salario + outros;  
        
        if (mes == 1){
          PorMes1 = PorMes1 + tot;
          
        }
        if (mes == 2){
          PorMes2 = PorMes2 + tot;
          
        }
        if (mes == 3){
          PorMes3 = PorMes3 + tot;
          
        }
        if (mes == 4){
          PorMes4 = PorMes4 + tot;
        }
        if (mes == 5){
          PorMes5 = PorMes5 + tot;
        }
        if (mes == 6){
          PorMes6 = PorMes6 + tot;
        }
        if (mes == 7){
          PorMes7 = PorMes7 + tot;
        }
        if (mes == 8){
          PorMes8 = PorMes8 + tot;
        }
        if (mes == 9){
          PorMes9 = PorMes9 + tot;
        }
        if (mes == 10){
          PorMes10 = PorMes10 + tot;
        }
        if (mes == 11){
          PorMes11 = PorMes11 + tot;
        }
        if (mes == 12){
          PorMes12 = PorMes12 + tot;
        }  
  
      }
      
    }
  
  FILE* relathtml = fopen("RelatAnual.html", "w");

fprintf(relathtml,"<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'><meta name='viewport' content='widht=devide-widht, initial-scale=1.0'><meta http-equi='X-UA-Compatible' content='ie=edge'><title>Grafico Mensal</title></head>\n");
fprintf(relathtml,"<body><canvas class='line-chart'></canvas><script src='https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.5.0/Chart.min.js'></script>\n");
fprintf(relathtml,"<script>var ctx = document.getElementsByClassName('line-chart');var myDoughnutChart = new Chart(ctx, {type: 'line', data: {labels: ['Janeiro', 'Fevereiro', 'Março', 'Abril', 'Maio','Junho', 'Julho', 'Agosto', 'Setembro', 'Outubro', 'Novembro', 'Dezembro'], datasets: [{label: 'SEU GASTO ANUAL',\n");
		fprintf(relathtml," data:   [%.2f,\n", PorMes1); 
		fprintf(relathtml,"          %.2f,\n", PorMes1); 
		fprintf(relathtml,"          %.2f,\n", PorMes3); 
		fprintf(relathtml,"          %.2f,\n", PorMes4); 
		fprintf(relathtml,"          %.2f,\n", PorMes5);
		fprintf(relathtml,"          %.2f,\n", PorMes6); 
		fprintf(relathtml,"          %.2f,\n", PorMes7);
		fprintf(relathtml,"          %.2f,\n", PorMes8);
		fprintf(relathtml,"          %.2f,\n", PorMes9);
		fprintf(relathtml,"          %.2f,\n", PorMes10);
		fprintf(relathtml,"          %.2f,\n", PorMes11);
		fprintf(relathtml,"          %.2f],\n", PorMes12);
		fprintf(relathtml,"      borderWidth: 6, borderColor: 'rgba(77,166,253,0.85)', backgroundColor: 'transparent',}]}});\n");
fprintf(relathtml,"</script></body></html>\n");
fclose(relathtml); 

printf("----------------------------------------------\n");
printf("Arquivo gerado com sucesso!!\n");
printf("----------------------------------------------\n");
return 0;
}



//======================================================
//========= Função Mes =================================
struct R1{

char aux[200][20];
char auxano[10];
char auxmes[10];
int mesCL;
int anoCL;

};

int Relatorio1mes(struct R1 c){ 

  printf("Digite o Ano em quer procurar, ex:(20)\n");
  scanf("%d",&c.anoCL);
	printf("----------------------------------------------\n");
  if(c.anoCL > 99 || c.anoCL <0){
    puts("Você digitou um ano invalido ");
		puts("Volte para o menu novamente!!");
    return 0;
  }

  printf("Digite o mês em quer procurar, ex:(02)\n");
  scanf("%d",&c.mesCL);
	printf("----------------------------------------------\n");
  if(c.mesCL > 12 || c.mesCL <= 0){
    puts("Você digitou um mês invalido ");
    puts("Volte para o menu novamente!!");
    return 0;
  }

  char moradiaS[15]="moradia";
  char alimentacaoS[15]="alimentação";
  char trasnporteS[15]="transporte";
  char estudoS[15] = "estudos";
  char salarioS[15] = "salario";
  char vendasS[15] = "vendas";
  char outrosS[15] = "outros";
  char pessoaisS[15] = "pessoais";
  float moradia;
  float alimentacao=0;
  float transporte=0;
  float estudos=0;
  float pessoais=0;
  float salario=0;
  float vendas=0 ; 
  float outros = 0;
  int i = 0;
  int j = 0;
  int ano = 0;
  int mes = 0;
  
    FILE * ler = fopen("registro.txt","r");
    while( fgets(c.aux[i] ,20 , ler) != NULL ){
    i++;  
  }
  fclose(ler);
    
    for(j=0; j!=i; j++){
    c.auxmes[0] = c.aux[j][3];
    c.auxmes[1] = c.aux[j][4];
    c.auxmes[2] = '\0';

    c.auxano[0] = c.aux[j][6];
    c.auxano[1] = c.aux[j][7];
    c.auxano[2] = '\0';

    ano = atoi(c.auxano);
    mes = atof(c.auxmes);
    
      if(ano==c.anoCL&& mes== c.mesCL){
        if (strstr(c.aux[j+1],moradiaS) != NULL){
          moradia = moradia + atof(c.aux[j-1]);
          
        }
        if (strstr(c.aux[j+1],alimentacaoS) != NULL){
          alimentacao = alimentacao + atof(c.aux[j-1]);
        }
        if (strstr(c.aux[j+1],trasnporteS) != NULL){
          transporte = transporte + atof(c.aux[j-1]);
        }
        if (strstr(c.aux[j+1],estudoS) != NULL){
          estudos = estudos + atof(c.aux[j-1]);
        }
        if (strstr(c.aux[j+1],vendasS) != NULL){
          vendas = vendas + atof(c.aux[j-1]);
        }
        if (strstr(c.aux[j+1],salarioS) != NULL){
          salario = salario + atof(c.aux[j-1]);
        }
        if (strstr(c.aux[j+1],outrosS) != NULL){
          outros = outros + atof(c.aux[j-1]);
        }

      }
    }
	FILE* relatoriohtml = fopen("RelatMes.html", "w");
  fprintf(relatoriohtml,"<!DOCTYPE html><html lang='n'><head><meta charset='UTF-8'><meta name='viewport' content='widht=devide-widht, initial-scale=1.0'><meta http-equi='X-UA-Compatible' content='ie=edge'><title>Grafico Mensal</title></head>");
  fprintf(relatoriohtml,"<body><canvas class='line-chart'></canvas><script src='https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.5.0/Chart.min.js'></script>\n");
  fprintf(relatoriohtml,"<script>var ctx = document.getElementsByClassName('line-chart');var myDoughnutChart = new Chart(ctx, {type: 'line', data: {labels: ['Alimentação', 'Transporte', 'Moradia', 'Estudos', 'Pessoais', 'Vendas', 'Salário', 'Outros'], datasets: [{label: 'SUAS MOVIMENTAÇÕES NESTE MÊS',\n");
    fprintf(relatoriohtml," data:  [ %.2f,", alimentacao);
    fprintf(relatoriohtml," %.2f,\n",  transporte);
    fprintf(relatoriohtml," %.2f,\n ", moradia);
    fprintf(relatoriohtml," %.2f,\n ", estudos);
    fprintf(relatoriohtml," %.2f,\n ", pessoais);
    fprintf(relatoriohtml," %.2f,\n ", salario);
    fprintf(relatoriohtml," %.2f,\n ", vendas);
    fprintf(relatoriohtml," %.2f],\n", outros);
    fprintf(relatoriohtml," borderWidth: 6, borderColor: 'rgba(77,166,253,0.85)', backgroundColor: 'transparent',}]}});\n");
  fprintf(relatoriohtml,"</script></body></html>");
  fclose(relatoriohtml);
  
  printf("----------------------------------------------\n");
  printf("Arquivo gerado com sucesso!!\n");
  printf("----------------------------------------------\n");  
  return 0;
}
//======================================================
//========== Função Saída ==============================


struct exit{
  int saida;
  char opiniao[50];
};

int saida(struct exit b){
  printf("Por favor avalie nosso sistema com uma nota de 0 até 10: \n");
  printf("----------------------------------------------\n");
  scanf("%d", &b.saida);

  if(b.saida >= 0 && b.saida <= 5 ){
    printf("Ainda estamos em desenvolvimento, poderia nós ajudar a melhorar?\n");
    printf("Deixe sua opinião aqui?\n");
    printf("----------------------------------------------\n");
    scanf("%s", b.opiniao);
    printf("----------------------------------------------\n");
    printf("Estaremos esperando você novamente!\n");
  }
  else if(b.saida > 5 && b.saida <= 8){
    printf("Obrigado pela sua nota!\n");
    printf("Deseja deixar sua opinao para futuros upgrades?\n");
    printf("----------------------------------------------\n");
    scanf("%s", b.opiniao);
    printf("----------------------------------------------\n");
    printf("Estaremos esperando você novamente!\n");
  }
  else if(b.saida > 8 && b.saida <= 10){
    printf("Estamos muito contentes com a sua avaliação! :)\n");
    printf("----------------------------------------------\n");
    scanf("%s", b.opiniao);
    printf("----------------------------------------------\n");
    printf("Estaremos esperando você novamente!\n");
  }
  else if(b.saida < 0 || b.saida > 10){
    puts("Infelizmente sua nota está fora dos nossos padrões");
    puts("isso é uma nota boa? até a proxima.");
  }
return 0;
}
//=======================================================
//====== Função Reseta ==================================

struct apaga{
  int del;
};

int Resetar(struct apaga g){
 printf(" [1] - SIM\n [2] - NÃO\nRealmenente deseja apagar todos os dados? \n");
 scanf("%d", &g.del);
 printf("----------------------------------------------\n");

  if(g.del == 1){
    remove("registro.txt");
    remove("saldo.txt");
    remove("RelatMes.html");
		remove("RelatAnual");
    printf("Todos dados deletados\n");
  }

  else if(g.del>2 || g.del<1){
    printf("Opção invalida\n");
  }

return 0;  
}
//=======================================================
/



