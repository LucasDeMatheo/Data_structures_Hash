// Autor - Lucas De Matheo
// fonte: https://www.youtube.com/watch?v=9OI7h14jN0Y
/*
HASH - Estrutura para buscas -  quando já temos noção do tamnho dos elementos
que iremos guardar.
Este tipo de estrutura não é ideal para inserções!
*/

# include <stdio.h>
# include <stdlib.h>

# define M 19 //Inteiro primo mais proximo do tamanho do dobro que pensamos (10)
// 10 * 2 = 20 -> 19

typedef struct{
	int matricula; // Chave
	char nome[50];
}Pessoa;

Pessoa tabelaHash[M]; // Vetor de tamanho M(19) do tipo Pessoa (struct)

// inicializa a tabela com valor de código -1 | Deve ser chamada no inicio!
void incializarTabela(void){
	int i;
	for(i = 0; i < M; i++){
		tabelaHash[i].matricula = -1;		
	}
}

// Função de Espalhamento
int gerarCodigoHash(int chave){ // Chave será a matricula
	return (chave % M); 	
}

//Função para ler e retornar uma pessoa
Pessoa lerPessoa(){
	Pessoa p;
	printf("Digite a matricula: ");
	scanf("%d", &p.matricula);
	scanf("%*c");
	printf("Digite o nome: ");
	fgets(p.nome, 50, stdin);
	return p;
}

//Inserir uma pessoa na tabela
void inserir(void){
	Pessoa pes = lerPessoa();
	int indice = gerarCodigoHash(pes.matricula);
	while(tabelaHash[indice].matricula != -1){
		indice = gerarCodigoHash(indice + 1);
	}
	tabelaHash[indice] = pes;	
}

Pessoa* buscar(int chave){ // Matrícula do Usuário
	int indice = gerarCodigoHash(chave);
	while(tabelaHash[indice].matricula != -1){
		if(tabelaHash[indice].matricula == chave){
			return &tabelaHash[indice];
		}
		else{
			indice = gerarCodigoHash(indice + 1);
		}
		
	}
	return NULL;
}

void imprimir(void){
	int i;
	printf("\n----------------------------Tabela--------------------------\n");
	for(i = 0; i < M; i++){
		if(tabelaHash[i].matricula != -1){
			printf("%d = %d \t %s", i, tabelaHash[i].matricula, tabelaHash[i].nome);
		}
		else{
			printf("%d = \n", i);
		}		
	}
	printf("\n------------------------------------------------------------\n");	
}

int main(void){
	int op, chave;
	Pessoa *p;
	
	incializarTabela();
	
	do{
		printf("1 - Inserir\n2 - Buscar\n3- Imprimir\n0 - Sair\n");
		scanf("%d", &op);
		
		switch(op){
			case 0:
				printf("Saindo...\n");
				break;
			case 1:
				inserir();
				break;
			case 2:
				printf("Digite a matrícula a ser buscada: ");
				scanf("%d", &chave);
				p = buscar(chave);
				
				if(p){
					printf("\n\tMatricula: %d \tNome: %s\n", p->matricula, p->nome);
				}
				else{
					printf("\nMatricula não encontrada!\n");
				}
				break;
			case 3:
				imprimir();
				break;
			default:
				printf("Opção inválida\n");
				
		}
		
	}while(op != 0);
	
	return 0;
}





























