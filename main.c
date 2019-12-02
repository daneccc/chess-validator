#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xadrez.h"
#include "validador.h"


#define TAM 10

int main(int argc, char *argv[]) {

	matriz_t * m = matriz_criar(8, 8); //chama a funcao para criar uma matriz 8x8

	iniciar_tabuleiro(m);
	system("clear");
	printf("\n===> Tabuleiro inicial:\n\n");
    mostrar_tabuleiro(m);
	
	char branca[TAM], preta[TAM], jogadaAtual[TAM], punct[1];
	int rodada[1]; /*variavel lixo para armazenar a rodada*/

	FILE *f = fopen(argv[1], "r");

    if(f == NULL) {
        printf("Nao foi possivel ler o arquivo.\n");
        return EXIT_FAILURE;
    }

	/*remove lixo de memoria*/
	memset(branca, 0x0, TAM); 
	memset(preta, 0x0, TAM);

	/*ignora as informacoes do cabecalho do arquivo pgn baixados no site chesstempo.com/game-database.html */
	char info_lixo[256];
    int n=1;
    while(n<=10) {
	    fgets(info_lixo, 256, f);
        n++;
    }

	/*le a linha das jogadas do arquivo e salva no vetor*/
	while(!feof(f)) {
		int i;

		fscanf(f, "%d%c%s %s", rodada, punct, branca, preta);

		getc(stdin); //espera teclar ENTER pra continuar
		system("clear");

	 	for(i = 0; i < TAM; ++i) {
			jogadaAtual[i] = branca[i];
		}
        /*passa o valor 99 para identificar que foi uma jogada das brancas*/
		valida_jogada(jogadaAtual, m, 99, rodada, punct);

		mostrar_tabuleiro(m);

		getc(stdin);  //espera teclar ENTER para continuar
		system("clear");

		for(i = 0; i < TAM; ++i) {
			jogadaAtual[i] = preta[i];
		}
        /*passa o valor 100 para identificar que foi uma jogada das pretas*/
        valida_jogada(jogadaAtual, m, 100, rodada, punct);

		mostrar_tabuleiro(m);
	}

	matriz_destruir(m); //destroi a matriz
	fclose(f); //fecha o arquivo

	return 0;
}