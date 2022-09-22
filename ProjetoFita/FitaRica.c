#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int tempo_total;  // Tempo total das músicas
int tempo_fita = 30; // Tempo total da fita
int testes; // Quant de testes a serem executados
int n = 4; // Número de músicas
int *fita; // Ponteiro para vetor
FILE *file; // Ponteiro para file

// Vetores
int musicas[] = {3,4,10,3}; // Músicas a serem gravadas

// Funções
bool permuta (int a[], int n, int c, int b[]);
bool valida (int a[], int c);
int converteMinutosParaSegundos(int minutos, int segundos);
void printVetor(int vet[], int n);

// ======================================================================================================================================================
int gravarFita (int fita[], int n)
{
	fita = (int *)(calloc(n, sizeof(int))); // Aloca dinâmicamente o vetor
    printf ("\n");
    for (int i=0; i < n; i++)
    {
        printf ("Valor armazenado no elemento de indice [%d] = %d \n", i, fita[i]); // Exibi os valores de cada elemento do vetor 
    }
    printf ("\n");
}
// ======================================================================================================================================================
int segundos (int tempo_total, int tempo_fita, int a[]) // Função para conversão dos minutos das musicas para segundos
    { 
    tempo_total = 0;
	tempo_fita = tempo_fita * 60; // Tempo total da fita, em segundos
	
	for (int i=0; i< n; i++){
		printf("Tempo da musica %d, em segundos = %d\n", i, musicas[i]*60); // Tempo de cada musica no vetor, alterada para segundos
		musicas[i] = musicas[i] *60;
		tempo_total += musicas[i];
	}
	
	printf ("\n");
	printf ("Tempo total da fita, em segundos= %d\n", tempo_fita); 
	printf ("Tempo de cada lado da fita, em segundos= %d\n", tempo_fita/2);
	printf ("Tempo total das musicas, em segundos= %d\n", tempo_total);
}
// ======================================================================================================================================================
void lerArquivo (FILE *file) // Função para ler o arquivo
{
	printf ("\n");
	
	file = fopen("fitas.txt", "r"); // Abre o arquivo TXT
	if (file == NULL){ // Verifica se o ponteiro conseguiu abriu o arquivo
		printf ("Arquivo nao pode ser aberto\n");
		exit(0);
	}
	
	fscanf (file, "%i", &testes); // Faz a leitura da primeira linha do arquivo e guarda o valor na váriavel testes
	for (int i = 0; i < testes; i++)
	{
		// tape info [0] -> duracao da fita
		// tape info [1] -> total de musicas		
		int tapeInfo[2];
		fscanf(file, "%d", &tapeInfo[0]);
		fscanf(file, "%d", &tapeInfo[1]);
		printf("Fita %d:\n", i);
		printf("Minutos capturados: %d\n", tapeInfo[0]);
		printf("Musicas capturadas: %d\n", tapeInfo[1]);
		int* musicas = (int*) calloc(tapeInfo[1], sizeof(int));
		for (int j = 0; j < tapeInfo[1]; j++)
		{
			int minutos;
			int segundos;
			fscanf(file, "%d", &minutos);
			fscanf(file, "%d", &segundos);
			musicas[j] = converteMinutosParaSegundos(minutos, segundos);
		}
		printf("Finalizacao da leitura. Fita %d: \n", i);
		printVetor(musicas, tapeInfo[1]);
		free(musicas);
	}
	fclose(file); // Fecha o arquivo
}
int converteMinutosParaSegundos(int minutos, int segundos)
{
	return segundos + (minutos * 60);
}
void printVetor(int vet[], int n)
{
	for (int i = 0; i < n; i++)	
	{
		printf("%d ", vet[i]);
	}
	printf("\n");
}
// ======================================================================================================================================================
int main()
{	
	segundos (tempo_total, tempo_fita, musicas);
	lerArquivo (file);
	gravarFita(fita, n);
    
    system ("pause");
	return 0;
}
