#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
int tempo_total;  // Tempo total das músicas
int tempo_fita; // Tempo total da fita
int testes; // Qnt de testes a serem executados
int n; // Número de músicas
int *fita; // Ponteiro para vetor guardar musicas
int *disco; // Ponteiro pra vetor permutar musicas
FILE *file; // Ponteiro para file
// ======================================================================================================================================================
void exibiFitas(int* fita, int tempo_fita, int n)
{
	int i=0;
	tempo_fita = tempo_fita * 60; // Tempo total da fita, em segundos
	printf("Lado A \n");
	for(i; i<n; i++)
	{
		if(fita[i]<=tempo_fita/2){
			printf("%d, ", fita[i]);
			printf("\n");
		}
		else{
			break;
		}
	}
	printf("Lado B \n");
	while(i<n)
	{
		printf("%d, ", fita[i]);
		printf("\n");	
		i++;
	}
	printf("\n");
}

// ======================================================================================================================================================
// Função para validar se a permutação de músicas está correta e se não estamos passando músicas repetidas
bool valida (int* fita, int c)
{
	for(int i=0; i < c; i++)
	{
		if(fita[i] == fita [i]){
				return false;
			}
	}
	return true;
}
// ======================================================================================================================================================
// Função valida se as musicas podem ser gravadas nos lados A e B, se o total de tempo de um lado for esgotado o código para execução e vai para o outro lado.
// A função será chamada dentro da função de permutação, onde iremos validar as permutações possíves de musicas para cada lado.
// Caso não seja possível gravar as músicas o código retornará dentro da execução do MAIN
// True para gravar as músicas, False se não puder gravar
bool gravarFita (int* fita, int n, int tempo_fita) 
{
	int valida1 = 0;
	int valida2 = 0;
	tempo_fita = tempo_fita * 60; // Tempo total da fita, em segundos
	for (int i=0; i< n; i++)
	{
		if(valida1+fita[i] <= tempo_fita/2){
			valida1+=fita[i];
		}
		else{
			break; // Não colocamos false aqui, pois ainda há outro lado livre para gravarmos o tempo da música
		}
	}
	for(int i=0; i< n; i++)
	{
		if(valida2+fita[i] <= tempo_fita/2){
			valida2+=fita[i];
		}
		else{
			return false;
		}
	}
	return true;
}
// ======================================================================================================================================================
// Função para analisar o tempo total de todas as musicas que queremos gravar na fita
int tempoGravacao (int tempo_fita, int* disco, int n)
{ 
    tempo_total = 0;
	tempo_fita = tempo_fita * 60; // Tempo total da fita, em segundos
	for ( int i=0; i< n; i++ )
	{
		tempo_total += disco[i];
	}	
	printf ("Tempo total das musicas, em segundos: %d \n", tempo_total);
	printf ("Tempo total da fita, em segundos: %d \n", tempo_fita);
	return tempo_total;
}
// ======================================================================================================================================================
// Função converte o tempo das músicas pra segundos
int minutosParaSegundos(int minutos)
{
	return minutos*60;
}
// ======================================================================================================================================================
// Função exibi o contéudo de qualquer vetor declarado como parâmetro
void exibiVetor(int* vet, int n)
{
	for (int i = 0; i < n; i++)	
	{
		printf("Musica %d =  %d\n", i, vet[i]);
	}
}
// ======================================================================================================================================================
bool permuta (int* disco, int n, int tempo_fita, int* fita)
{
	int i=0;
	if (gravarFita(fita, n, tempo_fita)){
		exibiFitas(fita, tempo_fita, n);
		return true;
	}
	return false;
	for(int j=0; j<n; j++)
	{
		fita[i] = disco[j];
		if(valida(fita,n)){
			if(permuta(disco, n, tempo_fita, fita)){
				return true;
			}
		}
	}
	return false;
}
// ======================================================================================================================================================
int main()
{	
	file = fopen("fitas.txt", "r"); // Abre o arquivo TXT
	if (file == NULL){ // Verifica se o ponteiro conseguiu abriu o arquivo
		printf ("Arquivo nao pode ser aberto\n");
		exit(0);
	}
	
	fscanf (file, "%i", &testes); // Faz a leitura da primeira linha do arquivo e guarda o valor na váriavel testes
	printf("Testes: %d \n", testes);
	for (int i = 0; i < testes; i++)
	{
				
		int guardaInfo[2]; // Vetor para guardar informações de tempo e número de músicas no txt 
		fscanf(file, "%d", &guardaInfo[0]);
		tempo_fita = guardaInfo[0];
		fscanf(file, "%d", &guardaInfo[1]);
		n = guardaInfo[1];
		
		if (i=1){
			printf("Lado A \n");
		}
		else{
			printf("Lado B \n");
		}
		printf("A fita tem %d minutos totais\n", tempo_fita);
		printf("Queremos gravar %d musicas\n", n);
		printf("\n");
		fita = (int*) calloc(n, sizeof(int));
		disco = (int*) calloc(n, sizeof(int));
		for (int j = 0; j < n; j++)
		{
			int minutos;
			fscanf(file, "%d", &minutos);
			disco[j] = minutosParaSegundos(minutos);
			tempoGravacao (tempo_fita, disco, n);
		}
		printf("\n");
		
		exibiVetor(disco, n); // Printa o vetor com a musicas dentro
		if (tempo_total>tempo_fita || !permuta(disco, n, tempo_fita,fita)){
			printf("Impossível gravar as musicas\n");
		}
		
		
		free(fita); // Libera memória alocada para o vetor fita
		free(disco); // libera a memória alocada para o vetor fita_gravada
		fclose(file); // Fecha o arquivo
		
		system("pause");
		exit(0);
	}
}
