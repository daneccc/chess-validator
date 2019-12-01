#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xadrez.h"
#include "tabuleiro.h"
#include "validador.h"
#include "movimentos.h"

#define TAM 10
// #define ADV_BRANCO 99
// #define ADV_PRETO 100

int main(int argc, char *argv[]) {

	matriz_t * m = matriz_criar(8, 8);
	char temp;
	iniciar_tabuleiro(m);
    
    mostrar_tabuleiro(m);
	

	char branca[TAM], preta[TAM], jogadaAtual[TAM];
	int junk[3]; /*variavel lixo para armazenar a rodada*/

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
	fgets(info_lixo, 256, f);
	fgets(info_lixo, 256, f);
	fgets(info_lixo, 256, f);
	fgets(info_lixo, 256, f);
	fgets(info_lixo, 256, f);
	fgets(info_lixo, 256, f);
	fgets(info_lixo, 256, f);
	fgets(info_lixo, 256, f);
	fgets(info_lixo, 256, f);
	fgets(info_lixo, 256, f);


	/*le a linha das jogadas do arquivo e salva no vetor*/
	while(!feof(f)) {
		int i;

		fscanf(f, "%d.%s %s", junk, branca, preta);

		// if(junk[1] == '-') {
		// 	printf("terminou\n");
		// 	exit(1);
		// }

		getc(stdin); //espera teclar ENTER pra continuar

		printf("\n===> Rodada %d: \n", *junk); //printa a rodada da vez
			
	 	for(i = 0; i < TAM; ++i) {
			jogadaAtual[i] = branca[i];
		}

		if(!(valida_jogada(jogadaAtual, m, 99))) {
			printf("A jogada nao é valida.\n");
			exit(1);
		}

		mostrar_tabuleiro(m);

		getc(stdin);  //espera teclar ENTER para continuar

		for(i = 0; i < TAM; ++i) {
			jogadaAtual[i] = preta[i];
		}
		if(!(valida_jogada(jogadaAtual, m, 100))) {
			printf("A jogada nao é valida.\n");
			exit(1);
		}
		mostrar_tabuleiro(m);

	}


	matriz_destruir(m);
	fclose(f); 

	return 0;
}