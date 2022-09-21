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
	int i = 0;
	
	file = fopen("fitas.txt", "r"); // Abre o arquivo TXT
	if (file == NULL){ // Verifica se o ponteiro conseguiu abriu o arquivo
		printf ("Arquivo nao pode ser aberto\n");
		exit(0);
	}
	
	fscanf (file, "%i", &testes); // Faz a leitura da primeira linha do arquivo e guarda o valor na váriavel testes
	while (!feof(file)) // Laço para verificar se o arquivo foi lido até o final
	{
		printf ("Linha %d, Valor armazenado= %i \n", i, testes); // Exibi os demais valores das linhas do arquivo
		fscanf (file, "%i", &testes); // Guarda o valor na váriavel testes
		i++;	
	}
	fclose(file); // Fecha o arquivo
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
