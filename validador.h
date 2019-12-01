#include "tabuleiro.h"

/*prototipos das funcoes do arquivo validador.c*/

int valida_jogada(char *jogadaAtual, matriz_t * m, int cor_peca);
void identifica_peca(char *jogadaAtual, matriz_t * m, int cor_peca);
int identifica_movimento(char *jogadaAtual);
int gera_coluna(char *jogadaAtual, int movimento);
int gera_linha(char *jogadaAtual, int movimento);