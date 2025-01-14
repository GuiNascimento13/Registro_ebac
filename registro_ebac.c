#include <stdio.h> //biblioteca de cominicação com o usuário 
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável pelas strings
//bibliotecas devem estar sempre no início do código


int registrar() //Definindo a função Registrar
{
	setlocale(LC_ALL, "Portuguese"); //Definição de Linguagem
	
	// Início da definição de variáveis tipo strings
	char arquivo[12]; 
	char cpf[12]; 
	char nome[20];
	char sobrenome[20];
	char atribuicao[15]; 
	//Fim das variáveis
	
	//Início da coleta dos dados a serem registrados	
	printf("Você escolheu Registrar!\n\n");
	printf("Digite o CPF:");
	scanf("%s", cpf);
	
	printf("Nome:");
	scanf("%s", nome);
	
	printf("Sobrenome:");
	scanf("%s", sobrenome);
	
	printf("Atribuição:");
	scanf("%s", atribuicao);
	
	strcpy(arquivo, cpf); //Copia as váriaveis strings (não esquecer de criar a variável arquivo)
		
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Comando para escrever o arquivo ("w" escreve e "a" atualiza)
	fprintf(file, cpf);
	fprintf(file, "\n");
	fprintf(file, nome);
	fprintf(file, "\n");
	fprintf(file, sobrenome);
	fprintf(file, "\n");
	fprintf(file, atribuicao);
	fclose(file); //Fecha e salva o arquivo na pasta destino
	//Fim da coleta de dados 
}

int consultar() //Definindo a função Consultar
{
	setlocale(LC_ALL, "Portuguese"); //Definição de Linguagem
	
	//Início da definição de variáveis tipo strings
	char cpf[20];
	char info[100];
	//Fim das vaiáveis
	
	//Início da consulta
	printf("Você escolheu Consultar!\n");
	printf("Digite o CPF:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //Abre o arquivo para leitura ("r" faz a leitura)
	
	if(file == NULL) //Comando de ação para resultado nulo ou inexistente
	{
		printf("\n");
		printf("Registro não encontrado!\n\n");
	}
	
	while(fgets(info, 100, file) != NULL) //Comando para mostrar os dados do arquivo lido
	{
		printf("Dados do Registro:");
		printf("%s", info);
		printf("\n");
	}
	system("pause");
	//Fim da consulta
}

int deletar() // Definindo a função Deletar
{
	setlocale(LC_ALL, "Portuguese"); //Definição de Linguagem
	
	//Início da definição das variáveis tipo strings
	char cpf[12];
	//Fim da definição de variáveis
	
	//Início da ação Deletar
	printf("Você escolheu Deletar!\n");
	printf("Digite o CPF:");
	scanf("%s", cpf);
	
	remove(cpf); //Comando para deletar
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL);
	{
		printf("Resgistro Deletado!\n");
		system("pause");
	}
	//Fim da ação
	
}

int main()
{
	setlocale(LC_ALL, "Portuguese");// Definição da Linguagem
	
	int opcao=0; //Definição de variáveis
	int loop=1;
	char senha[]="a";
	int comparar;
	
		//Início da tela de login.
		printf("\t Registro EBAC \n\n ");
		printf("Acessar como Administrador.\n\n");
		printf("Digite a Senha:");
		scanf("%s",senha);
		
		comparar = strcmp(senha,"admin");
		//Fim da tela de login.
		
	if(comparar==0)
	{
		system("cls");
		
		for(loop=1;loop=1;) // Comando para sempre retornar ao MENU Inicial
		{
			system("cls"); //Comando para limpar tela
		
			printf("\t Registro EBAC \n\n "); // Início do Menu
			printf("Escolha uma das opções do menu abaixo:\n\n ");
			printf("\t1 - Registrar\n ");	
			printf("\t2 - Consultar\n ");
			printf("\t3 - Deletar\n ");
			printf("\t4 - Fechar Aplicação\n\n");
			printf("Selecione uma das opções e tecle ENTER:"); 
		
			scanf("%d", &opcao); // Armazenamento de Ação do Usuário (Pressionar Tecla)
		
			system("cls"); // Fim do Menu
		
				switch(opcao) // Início da Seleção (Resposta à Ação do Usuário)	
					{
						case 1:
						registrar();
						break;
						
						case 2:
						consultar();
						break;
						
						case 3:
						deletar();
						break;
						
						case 4:
						printf("Obrigado, até a próxima!");
						return 0;
						break;
						
						default:
						printf("Opção Inválida!\n");
						system("pause");
						break;		
					}//Fim da Seleção			
		}
	}
	else
	{
		printf("Senha Inválida!");
	}	
}


