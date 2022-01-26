/*Escreva um programa que leia vários números reais positivos e insira-os em um arquivo texto (um número por linha). Em seguida, leia os dados do arquivo e insira-os numa Lista Duplamente Encadeada através da chamada de uma função que retorna ponteiro para o início da lista. Logo após, gere um menu com as seguintes opções:
1- Imprimir a lista
2- Buscar um elemento na lista
3- Remover um valor da lista (lido via teclado)
4- Contar os nós da lista
5- Gerar uma cópia da lista num vetor
6- Sair
Crie funções para cada opção do menu, exceto a opção 6. Após executar a opção 3 ou a opção 5 imprima a lista resultante ou o vetor resultante. O programa acaba quando for digitado a opção 6.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int a, b, c, i, cont=0;
	int n;
	char texto[100];
	char valor[100];
	float aux;

	FILE *fileR, *fileW;
	fileR = fopen("string.txt","r");
	fileW = fopen("string.txt", "a");

	if(!fileR){
		printf("\nERRO! Arquivo nao foi aberto.\n\n");
		return 0;
	}
	if(!fileW){
		printf("\nERRO! Arquivo nao foi aberto.\n\n");
		return 0;
	}

	printf("Digite o numero de termos(termo > 0): ");
	scanf("%d", &n);
	for(int i=0 ; i<n ; i++){
		printf("v[%d]: ", i);
		scanf("%f", &aux);
		if(aux <= 0){
			printf("\nValor invalido.");
			return 0;
		}
		fprintf(fileW, "%.2f\n", aux);
	}
	while((texto[i] = getc(fileR)) != EOF){
		i++;
	}

	texto[i] = '\0';

	printf("%s", texto);		
	
		
	// fscanf(fileR,"")

	


	fclose(fileR);
	fclose(fileW);

	return 0;
}