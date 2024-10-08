#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //bibliotea de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel pelas strings


int main(){
		setlocale(LC_ALL, "Portuguese"); //setando a linguagem
	
	
	//FUN��O E TELA INICIAL
	int opcao=0; //Criando variav�l
	int loop=1;
	char senhadigitada[30] = "a"; //Variavel que armazena a senha
	
	//Looping para verificar se a senha digitada esta correta
	while(1){
		system("cls"); //LIMPAR TELA
		
		printf("\t### Cart�rio da EBAC ###\n\n");
		printf("Login de adminstrados\n\nDigite a sua senha: ");
		scanf("%s", senhadigitada);
		
		int	comparacao = strcmp(senhadigitada, "admin"); // atribuindo uma variavel que compara se a senha digitada � igual a admin
		
		// caso a senha digitada seja correta retorna um valor 0, neste caso quebrando o looping e liberando para a tela
		if (comparacao == 0) {
			system("cls");
			printf("\n\tAcesso Liberado\n");
			system("pause");
			break;
		}
		// caso a senha seja incorreta o looping n�o � quebrando e retorna a verifica��o
		else{
			printf("Acesso Negado\n");
			system("pause");
		}
	}
	
		
	for(loop=1;loop=1;){
	
		system("cls"); //LIMPAR TELA
	
		setlocale(LC_ALL, "Portuguese"); //setando a linguagem
	
		printf("\t### Cart�rio da EBAC ###\n\n"); // \n FAZ PULAR LINHA 
		printf("\tEscolha a op��o desejada do menu\n\n"); // \t FAZ UM PARAGRAFO
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Excluir Nomes\n\n");
		printf("\t4 - Fechar Aplicativo\n\n");
		printf("Op��o: ");
		scanf("%d", &opcao); // ARMAZENAR OP��O ESCOLHIDA
	
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
			
			//	MENU PARA EXCLUS�O DE NOMES
			case 3:
			exclusao();
			break;
			
			//FUN��O DE FECHAR O APP
			case 4:
			printf("Fechando Aplicativo");
			return 0;
			break;
			
			//CASO ESCOLHA ALGUMA OP��O N�O CORRESPONDENTE
			default:
			printf("Essa op��o n�o est� disponivel\n");
			system("pause");
			break;
		}

	}
}

int registro(){

//FUN��O DE REGISTRO DE NOMES
	
	//CRIANDO ARQUIVO PARA LISTAR NOMES	
	FILE *arq;
	arq = fopen("ListaNomes","r");
	
	//VERIFICANDO SE J� EXISTE
	if(arq == NULL){
		arq = fopen("ListaNomes", "w");
		fprintf(arq, "Esses s�o os Cadastrados:\n");
		fclose(arq);
	}
	\
	//Variaveis que ser�o coletadas
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
	file = fopen(arquivo, "a"); //Atualizar informa��es do arquivo
	fprintf(file, "O CPF �: ");
	fprintf(file,cpf); // salvar o valor da variavel
	fclose(file); // fecha o arquivo
	
	//Salvando CPF PARA LISTAGEM
	arq = fopen("ListaNomes", "a");
	fprintf(arq, "\nCPF: ");
	fprintf(arq, cpf);
	fclose(arq);
	
	
	// armazenando NOME
	file = fopen(arquivo, "a"); //Atualizar informa��es do arquivo
	fprintf(file, "\nO nome �: ");
	fprintf(file,nome);
	fclose(file);
	
	//SALVANDO NOME PARA LISTAGEM
	arq = fopen("ListaNomes", "a");
	fprintf(arq, "\nNOME: ");
	fprintf(arq, nome);
	fclose(arq);
	
	// Armazenando SOBRENOME
	file = fopen(arquivo, "a"); 
	fprintf(file, " ");//espa�o entre o nome e sobrenome
	fprintf(file,sobrenome);
	fclose(file);
	
	//SALVANDO SOBRENOME PARA LISTAGEM
	arq = fopen("ListaNomes", "a");
	fprintf(arq, " ");
	fprintf(arq, sobrenome);
	fprintf(arq, "\n");
	fclose(arq);
		
	// Armazenando CARGO
	file = fopen(arquivo, "a"); 
	fprintf(file, "\nO cargo �: ");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta(){
	//FUN��O CONSULTA DE NOMES
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];

	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");// ler o arquivo CPF
	
	if(file == NULL){
		printf("N�o foi Localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("%s",conteudo);
	}
	fclose(file);
	printf("\n");
	system("pause");
	
}

int exclusao(){
	
	//FUN��O EXCLUS�O DE NOMES
	
	char cpf[40];
	char ListaNomes[999];
	
	FILE *arq;
	arq = fopen("ListaNomes","r");

	while(fgets(ListaNomes, 999, arq) != NULL){
		printf("%s",ListaNomes);
	}
	
	printf("\n\nDigite CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	
	
	FILE *file;
	file = fopen(cpf,"r");
	

	if(file == NULL){
		fclose(file);
		printf("N�o cont�m esse usu�rio no sistema!\n");
		system("pause");
	}else{
		fclose(file);
		remove(cpf);
		printf("O Usu�rio foi removido!\n");
		system("pause");
	}

}
