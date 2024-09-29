#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //bibliotea de alocações de texto por região
#include <string.h> //biblioteca responsavel pelas strings


int main(){
	//FUNÇÃO E TELA INICIAL
	
	int opcao=0; //Criando variavél
	int loop=1;
	
	for(loop=1;loop=1;){
	
		system("cls"); //LIMPAR TELA
	
		setlocale(LC_ALL, "Portuguese"); //setando a linguagem
	
		printf("\t### Cartório da EBAC ###\n\n"); // \n FAZ PULAR LINHA 
		printf("\tEscolha a opção desejada do menu\n\n"); // \t FAZ UM PARAGRAFO
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Excluir Nomes\n\n");
		printf("Opção: ");
		scanf("%d", &opcao); // ARMAZENAR OPÇÃO ESCOLHIDA
	
		system("cls"); //LIMPAR TELA
	
		switch(opcao){
			//	MENU PARA REGISTRO DE NOMES
			case 1:
			registro();
			break;
			
			//	MENU PARA CONSULTA DE NOMES
			case 2:
			consulta();
			break;
			
			//	MENU PARA EXCLUSÃO DE NOMES
			case 3:
			exclusao();
			break;
			
			//CASO ESCOLHA ALGUMA OPÇÃO NÃO CORRESPONDENTE
			default:
			printf("Essa opção não está disponivel\n");
			system("pause");
			break;
		}

	}
}

int registro(){

//FUNÇÂO DE REGISTRO DE NOMES
	
	//Variaveis que serão coletadas
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	printf("Digite o Cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	strcpy(arquivo, cpf); //RESPOSAVEL POR COPIAR OS VALORES DAS STRINGS
	
	FILE *file; //criar arquivo
	file = fopen(arquivo, "w"); //criar arquivo
	fclose(file);
	
	//Armazenando o CPF
	file = fopen(arquivo, "a"); //Atualizar informações do arquivo
	fprintf(file, "O CPF é: ");
	fprintf(file,cpf); // salvar o valor da variavel
	fclose(file); // fecha o arquivo
	
	// armazenando NOME
	file = fopen(arquivo, "a"); //Atualizar informações do arquivo
	fprintf(file, "\nO nome é: ");
	fprintf(file,nome);
	fclose(file);
	
	// Armazenando SOBRENOME
	file = fopen(arquivo, "a"); 
	fprintf(file, " ");//espaço entre o nome e sobrenome
	fprintf(file,sobrenome);
	fclose(file);
		
	// Armazenando CARGO
	file = fopen(arquivo, "a"); 
	fprintf(file, "\nO cargo é: ");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta(){
	//FUNÇÃO CONSULTA DE NOMES
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");// ler o arquivo CPF
	
	if(file == NULL){
		printf("Não foi Localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("%s",conteudo);
	}
	fclose(file);
	printf("\n");
	system("pause");
	
}

int exclusao(){
	
	//FUNÇÃO EXCLUSÃO DE NOMES
	
	char cpf[40];
	
	printf("Digite CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	
	
	FILE *file;
	file = fopen(cpf,"r");
	

	if(file == NULL){
		fclose(file);
		printf("Não contém esse usuário no sistema!\n");
		system("pause");
	}else{
		fclose(file);
		remove(cpf);
		printf("O Usuário foi removido!\n");
		system("pause");
	}

}
