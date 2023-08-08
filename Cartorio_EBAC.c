#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h> //biblioteca respons�velvel por cuidar das strings

int qtd_virgulas(char *str) //fun��o para contar a quantidade de virgulas da string
{
    int virgulas = 0;
    while(*str){
        if (*str == ','){
           virgulas++;
        }
        str++;
    }
    return virgulas;
}
	
int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	setlocale(LC_ALL, "Portuguese");//definifndo linguagem
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");

}

int consulta()
{
	char cpf[40];
	char conteudo[100];
	char nome_completo[40];
	char cargo[20];
		
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	  	
	FILE *file;
	file = fopen(cpf,"r");
	  	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
		
	}
	
			
	while(fgets(conteudo, 100, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n\n");
		printf("CPF: %s\n", cpf);
		
		//quebrar - split da string para obter as informa��es separadas por virgula
	    int qtd_informacoes = 0;
		qtd_informacoes = qtd_virgulas(conteudo) + 1;
		int i = 0;
	    char strings[qtd_informacoes][strlen(conteudo)];
	    char *pch = strtok (conteudo,",");
	    while (pch != NULL)
		{
	        strcpy(strings[i++], pch); //copiar cada string para a posi��o correta
	        pch = strtok (NULL, ",");
	    }
			
		printf("Nome: %s %s\n", strings[1], strings[2]);
		printf("Cargo: %s\n", strings[3]);
	
	}
	
	
	printf("\n\n");
	  	
	system ("pause");
}

int excluir()
{
	setlocale(LC_ALL, "Portuguese");//definifndo linguagem
	
	printf("Voc� escolheu excluir nomes!\n\n");
	system("pause");	
}


int main()
	{	
		int opcao=0; //definindo vari�veis
		int laco=1;
		
		for (laco=1;laco=1;)
		{
		
			system("cls");
			
			setlocale(LC_ALL, "Portuguese");//definifndo linguagem
			
			printf("\t\t\t\t######### Cart�rio da EBAC #########\n\n");//inicio do menu
			printf("\tEscolha a op��o desejada:\n\n");
			printf("\t1 - Registrar Nomes\n\n");
			printf("\t2 - Pesquisar Nomes\n\n");
			printf("\t3 - Excluir Nomes\n\n");
			printf("Op��o: ");//fim do menu
			
			scanf("%d",&opcao);//armazendando op��o digitada pelo usu�rio
			
			system("cls");
			
			
			switch(opcao) //in�ncio da sele��o
			{
				case 1:
					registro();
				break;
				
				case 2:
					consulta();
				break;
				
				case 3:
					excluir();
				break;
				
				default:
					printf("Voc� escolheu uma op��o inv�lida!\n\n");
					system("pause");
				break;
			}
			
			
		}
		
	}
