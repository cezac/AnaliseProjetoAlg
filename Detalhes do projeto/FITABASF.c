#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//Variaveis globais
int tempo_fita = 30; // Tempo total da fita
int testes = 1; // Número de testes que serão executados
int n = 4; // Número de músicas


// Funções
bool permuta (int m[], int n, int c, int g[]);
bool valida (int m[], int c);
bool gravar_fita (int m[], int n);


// Vetores
int m[] = {3,4,10,3}; // Músicas a serem gravadas
int g[] = {0,0,0,0}; // Vetor de gravação


int main()

{
	// Conversão dos minutos das musicas para segundos
	int tempo_total = 0; // Tempo total das músicas
	tempo_fita = tempo_fita * 60; // Tempo total da fita, em segundos
	
	for (int i=0; i< n; i++){
		printf("Tempo da musica %d, em minutos = %d\n", i, m[i]);
		m[i] = m[i] *60;
		tempo_total += m[i];
	}
	
	printf ("\n");
	printf ("Tempo total da fita, em segundos= %d\n", tempo_fita);
	printf ("Tempo de cada lado da fita, em segundos= %d\n", tempo_fita/2);
	printf ("Tempo total das musicas, em segundos= %d\n", tempo_total);
	
	exit (0);
}
