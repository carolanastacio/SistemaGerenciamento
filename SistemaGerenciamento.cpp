#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#define MAX 200

 struct projeto{
	int codigo;
	int ano;
	int status;
	float custo;
	char cidade [50];
	char empresa [50];
	char nome [50];
	char descricao [50];
	char gerente [50];
	};
	
	void cadastroProjeto (projeto cadastro [MAX]);
	void imprimirTodos (projeto cadastro [MAX]);
	void imprimirStatus (projeto cadastro [MAX]);
	void imprimirCodigo (projeto cadastro [MAX]);
	
	
	int posicao = 0;
	projeto cadastro[MAX];
	
	int main(){
		setlocale(LC_ALL, "Portuguese");
		system ("cls");
		
		int escolha;
				
		do{
			 system("cls");
			printf("\n******************************************");
			printf("\n*         SEJA BEM VINDO                 *");
			printf("\n* METRA MEDICINA E SEGURANÇA DO TRABALHO *");
			printf("\n******************************************");
			printf("\n\n");
			printf("\n **** M E N U ***\n");
			printf("\n 1- Cadastro");
			printf("\n 2- Imprimir todos os projetos");
			printf("\n 3- Pesquisar por Status");
			printf("\n 4- Pesquisar por código");
			printf("\n 5- Sair\n");
			printf("\n>>Digite uma opção: ");
			scanf("%d", &escolha);
			
			switch (escolha){
				case 1:
					cadastroProjeto (cadastro);
					break;
				case 2:
					imprimirTodos (cadastro);
					break;
				case 3:
					imprimirStatus (cadastro);
					break;
				case 4:
					imprimirCodigo (cadastro);
					break;			
				case 5:
					printf ("\n Saindo do programa");
					system ("pause");
					break;
				default:
				printf("\nEscolha errada!!!\n");
				system("Pause");
		   }
		}while (escolha !=5);
			return 0;
}
	void cadastroProjeto (projeto cadastro [MAX]){
	    
		char resp = 's';
		while ((resp =='s') && (posicao <= MAX)){
			posicao++;
			system ("cls");
			
			printf("\nCódigo do projeto: %d\n", posicao);
			cadastro[posicao].codigo = posicao;
			fflush(stdin);
			printf("Informe o nome: ");
			scanf("%s", cadastro[posicao].nome);
			fflush(stdin);
			printf("Informe a descrição: ");
			scanf("%s", cadastro[posicao].descricao);
			fflush(stdin);
			printf("Informe o ano: ");
			scanf("%d", &cadastro[posicao].ano);
			fflush(stdin);
			printf("Custo do projeto: R$ ");
			scanf("%f", &cadastro[posicao].custo);
			fflush(stdin);
			printf("Empresa solicitante: ");
			scanf("%s", &cadastro[posicao].empresa);
			fflush(stdin);
			printf("Será realizado na filial de: ");
			scanf("%s", &cadastro[posicao].cidade);
			fflush(stdin);
			printf("Informe o responsável: ");
			fflush(stdin);
			scanf("\n%s", cadastro[posicao].gerente);
			fflush(stdin);
			printf("Informe o status: ");
			printf("\n 1- Pendente   2- Andamento   3-Concluído \n ");
			scanf("\n %d", &cadastro[posicao].status);
			fflush(stdin);
			printf("\n**************projeto cadastradado com sucesso!****************\n");
	
		
			if(posicao < MAX){
				printf("\nDeseja cadastrar novo projeto?");
				printf("\n [s] Sim   [n] Não:  ");
				fflush(stdin);
				scanf("\n%c", &resp);
			} else{
					system ("cls");
					printf("\nSua base está cheia!");
			     	system("pause");
				}
		system("pause");			
		}
	}
		
	void imprimirTodos (projeto cadastro[MAX]){
	
	system ("cls");
	printf("\n<< PROJETOS CADASTRADOS >>\n");
	int linha = 1;
	
	if (posicao >= 1){
		while(linha<= posicao){
			printf("Código do projeto: %d\n", cadastro[linha].codigo); 
			printf("Nome: %s\n", cadastro[linha].nome);
			printf("Descrição: %s\n", cadastro[linha].descricao);
			printf("Ano do projeto: %d\n", cadastro[linha].ano); 
			printf("Custo do projeto: R$ %.2f\n", cadastro[linha].custo);
			printf("Empresa solicitante: %s\n", cadastro[linha].empresa);
			printf("Realizado na filial de: %s\n", cadastro[linha].cidade);
			printf("Gerente do projeto: %s\n",cadastro[linha].gerente);
			printf("Status do projeto: %d\n", cadastro[linha].status ); 
			printf("\n\n");
			linha++;
			}system("pause");
		
	}else{
			printf("\n Sem registro cadastrado!\n");
			system("pause");
		}
		system("pause");
}
	
	
void imprimirStatus(projeto cadastro[MAX]){                                 
    int s, status, acha = 0;
    
    system ("cls");
    printf(" |   Status do Projeto  |  \n");
	printf(" -------------------------\n");
	printf(" | 1- Status: A Fazer   |  \n");
	printf(" | 2- Status: Fazendo   |  \n");
	printf(" | 3- Status: Concluído |  \n");
	printf(" -------------------------\n");
    printf("Informe o STATUS para a pesquisa:\n");
    scanf("%d", &status);
    
    while((s <= MAX) && (acha==0)){
        if (status == cadastro[s].status)
			acha = 1;
			else
				s++;
	}
	
	if (acha == 1){
			printf("Código do projeto: %d\n", cadastro[s].codigo); 
			printf("Nome: %s\n", cadastro[s].nome);
			printf("Descrição: %s\n", cadastro[s].descricao);
			printf("Ano do projeto: %d\n", cadastro[s].ano); 
			printf("Custo do projeto: R$ %.2f\n", cadastro[s].custo);
			printf("Empresa solicitante: %s\n", cadastro[s].empresa);
			printf("Realizado na filial de: %s\n", cadastro[s].cidade);
			printf("Gerente do projeto: %s\n",cadastro[s].gerente);
			printf("Status do projeto: %d\n", cadastro[s].status); 
			printf("\n\n");
			system("pause");
	    }
			else{
		  		printf("CÓDIGO %d  INEXISTENTE.\n\n", status);
        		system("pause");
            }
}
		
		
void imprimirCodigo (projeto cadastro[MAX]){
	int busca;
	int aux;
	int acha;
	
	system ("cls");
	printf("\n << PESQUISA POR CODIGO >>\n");
	printf("\nDigite o codigo do projeto: \n");
	scanf("%d", &busca);
	
		
		aux= 0;
		acha= 0;
		
			while((aux<= MAX) && (acha==0))
			{
							
				if (cadastro[aux].codigo==busca)
				acha = 1;
				else
				 aux++;
			}
					if(acha==1)
					{
						printf("Código do projeto: %d\n", cadastro[aux].codigo); 
						printf("Nome: %s\n", cadastro[aux].nome);
						printf("Descrição: %s\n", cadastro[aux].descricao);
						printf("Ano do projeto: %d\n", cadastro[aux].ano); 
						printf("Custo do projeto: R$ %.2f\n", cadastro[aux].custo);
						printf("Empresa solicitante: %s\n", cadastro[aux].empresa);
						printf("Realizado na filial de: %s\n", cadastro[aux].cidade);
						printf("Gerente do projeto: %s\n",cadastro[aux].gerente);
						printf("Status do projeto: %d\n", cadastro[aux].status); 
						printf("\n\n");
						system("pause");
					}
						else
						{
												
								printf("\n Ops! Não encontramos os registros.\n");
								system("pause");
							}
						}	 
											
		





