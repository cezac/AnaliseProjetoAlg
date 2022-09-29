#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int tempo_total;  // Tempo total das musicas
int tempo_fita; // Tempo total da fita
int testes; // Qnt de testes a serem executados
int n; // Numero de musicas
int *fita; // Ponteiro para vetor guardar musicas
int *disco; // Ponteiro pra vetor permutar musicas
FILE *file; // Ponteiro para file

// ======================================================================================================================================================
// Funcao valida se as musicas podem ser gravadas nos lados A e B, se o total de tempo de um lado for esgotado o codigo para execucao e vai para o outro lado.
// A funcao sera chamada dentro da funcao de permutacao, onde iremos validar as permutacoes possiveis de musicas para cada lado.
// Caso Nao seja possivel gravar as musicas o codigo retornar dentro da execucao do MAIN
// True para gravar as musicas
// False se Nao puder gravar
bool gravarFita (int* fita, int n, int tempo_fita) 
{
	
}
// ======================================================================================================================================================
bool permuta (int* disco, int n, int tempo_fita, int* fita)
{
	
}
// ======================================================================================================================================================
void exibiFitas(int* fita, int tempo_fita, int n)
{
	
}

// ======================================================================================================================================================
// funcao para validar se a permutacao de musicas esta correta e se nao estamos passando musicas repetidas
bool valida (int* fita, int c)
{
	for(int i=0; i < c; i++)
	{
		if(fita[c] == fita [i])
		{
			return false;
		}
	}

	return true;
}
// ======================================================================================================================================================
// funcao para analisar o tempo total de todas as musicas que queremos gravar na fita
int tempoGravacao (int tempo_fita, int* disco, int n)
{ 
    tempo_total=0;
	tempo_fita=tempo_fita*60; // Tempo total da fita, em segundos
	for (int i=0; i< n; i++)
	{
		tempo_total+=disco[i];
	}	
	printf ("Tempo total da fita = %d\n", tempo_fita);
	printf ("Tempo total das musicas = %d\n", tempo_total);
	return tempo_total;
}
// ======================================================================================================================================================
// funcao converte o tempo das musicas pra segundos
int minutosParaSegundos(int minutos)
{
	return minutos*60;
}
// ======================================================================================================================================================
// funcao exibi o conteudo de qualquer vetor declarado como par�metro
void exibiVetor(int* vet, int n)
{
	for (int i=0; i < n; i++)	
	{
		printf("Musica %d =  %d\n", i, vet[i]);
	}
}
// ======================================================================================================================================================
int main()
{	
	file = fopen("fitas.txt", "r"); // Abre o arquivo TXT
	if (file == NULL)
	{ // Verifica se o ponteiro conseguiu abriu o arquivo
		printf ("Arquivo nao pode ser aberto\n");
		exit(0);
	}
	
	fscanf (file, "%i", &testes); // Faz a leitura da primeira linha do arquivo e guarda o valor na variavel testes
	printf("Testes: %d \n", testes);
	for (int i = 0; i < testes; i++)
	{
				
		int guardaInfo[2]; // Vetor para guardar informacoes de tempo e numero de musicas no txt 
		fscanf(file, "%d", &guardaInfo[0]);
		tempo_fita=guardaInfo[0];
		fscanf(file, "%d", &guardaInfo[1]);
		n=guardaInfo[1];

		printf("A fita tem %d minutos totais\n", tempo_fita);
		printf("Queremos gravar %d musicas\n", n);

		printf("\n");
		fita=(int*) calloc(n, sizeof(int));
		disco=(int*) calloc(n, sizeof(int));

		for (int j=0; j < n; j++)
		{
			int minutos;
			fscanf(file, "%d", &minutos);
			disco[j]=minutosParaSegundos(minutos);
			tempoGravacao (tempo_fita, disco, n);
		}

		printf("\n");
		exibiVetor(disco, n); // Printa o vetor com a musicas dentro

		if (tempo_total<tempo_fita) // Se o tempo total das musicas for maior que o tempo da fita
		{
			printf ("Impossivel gravar todas as músicas nessa fita\n");
		}
		
		system("pause");	
	}
}
