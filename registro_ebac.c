#include <stdio.h> //biblioteca de cominica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel pelas strings
//bibliotecas devem estar sempre no in�cio do c�digo


int registrar() //Definindo a fun��o Registrar
{
	setlocale(LC_ALL, "Portuguese"); //Defini��o de Linguagem
	
	// In�cio da defini��o de vari�veis tipo strings
	char arquivo[12]; 
	char cpf[12]; 
	char nome[20];
	char sobrenome[20];
	char atribuicao[15]; 
	//Fim das vari�veis
	
	//In�cio da coleta dos dados a serem registrados	
	printf("Voc� escolheu Registrar!\n\n");
	printf("Digite o CPF:");
	scanf("%s", cpf);
	
	printf("Nome:");
	scanf("%s", nome);
	
	printf("Sobrenome:");
	scanf("%s", sobrenome);
	
	printf("Atribui��o:");
	scanf("%s", atribuicao);
	
	strcpy(arquivo, cpf); //Copia as v�riaveis strings (n�o esquecer de criar a vari�vel arquivo)
		
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

int consultar() //Definindo a fun��o Consultar
{
	setlocale(LC_ALL, "Portuguese"); //Defini��o de Linguagem
	
	//In�cio da defini��o de vari�veis tipo strings
	char cpf[20];
	char info[100];
	//Fim das vai�veis
	
	//In�cio da consulta
	printf("Voc� escolheu Consultar!\n");
	printf("Digite o CPF:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //Abre o arquivo para leitura ("r" faz a leitura)
	
	if(file == NULL) //Comando de a��o para resultado nulo ou inexistente
	{
		printf("\n");
		printf("Registro n�o encontrado!\n\n");
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

int deletar() // Definindo a fun��o Deletar
{
	setlocale(LC_ALL, "Portuguese"); //Defini��o de Linguagem
	
	//In�cio da defini��o das vari�veis tipo strings
	char cpf[12];
	//Fim da defini��o de vari�veis
	
	//In�cio da a��o Deletar
	printf("Voc� escolheu Deletar!\n");
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
	//Fim da a��o
	
}

int main()
{
	setlocale(LC_ALL, "Portuguese");// Defini��o da Linguagem
	
	int opcao=0; //Defini��o de vari�veis
	int loop=1;
	char senha[]="a";
	int comparar;
	
		//In�cio da tela de login.
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
		
			printf("\t Registro EBAC \n\n "); // In�cio do Menu
			printf("Escolha uma das op��es do menu abaixo:\n\n ");
			printf("\t1 - Registrar\n ");	
			printf("\t2 - Consultar\n ");
			printf("\t3 - Deletar\n ");
			printf("\t4 - Fechar Aplica��o\n\n");
			printf("Selecione uma das op��es e tecle ENTER:"); 
		
			scanf("%d", &opcao); // Armazenamento de A��o do Usu�rio (Pressionar Tecla)
		
			system("cls"); // Fim do Menu
		
				switch(opcao) // In�cio da Sele��o (Resposta � A��o do Usu�rio)	
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
						printf("Obrigado, at� a pr�xima!");
						return 0;
						break;
						
						default:
						printf("Op��o Inv�lida!\n");
						system("pause");
						break;		
					}//Fim da Sele��o			
		}
	}
	else
	{
		printf("Senha Inv�lida!");
	}	
}


