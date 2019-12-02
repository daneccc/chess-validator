/*prototipos das funcoes do arquivo movimentos.c*/

matriz_t * mover_peao(matriz_t * m, int col, int linha, int cor_peca, int movimento, char *jogadaAtual, int *junk);
matriz_t * mover_cavalo(matriz_t * m, int col, int linha, int cor_peca, int movimento, char *jogadaAtual, int *junk);
matriz_t * mover_rei(matriz_t * m, int col, int linha, int cor_peca, int movimento, char *jogadaAtual, int *junk);
matriz_t * mover_torre(matriz_t * m, int col, int linha, int cor_peca, int movimento, char *jogadaAtual, int *junk);
matriz_t * mover_bispo(matriz_t * m, int col, int linha, int cor_peca, int movimento, char *jogadaAtual, int *junk);
matriz_t * mover_rainha(matriz_t * m, int col, int linha, int cor_peca, int movimento, char *jogadaAtual, int *junk);
matriz_t * roque_menor(matriz_t * m, int cor_peca, int *junk);
matriz_t * roque_maior(matriz_t * m, int cor_peca, int *junk);

elemento_t * percorre_abaixo(matriz_t * m, elemento_t * e, int cor_peca, int max_casas, int movimento, char *jogadaAtual);
elemento_t * percorre_direita(matriz_t * m, elemento_t * e, int cor_peca, int max_casas, int movimento, char *jogadaAtual);
elemento_t * percorre_esquerda(matriz_t * m, elemento_t * e, int cor_peca, int max_casas, int movimento, char *jogadaAtual);
elemento_t * percorre_cima(matriz_t * m, elemento_t * e, int cor_peca, int max_casas, int movimento, char *jogadaAtual);

elemento_t * percorre_diagonalBaixoDireita(matriz_t * m, elemento_t * e, int cor_peca, int max_casas, int movimento, char *jogadaAtual);
elemento_t * percorre_diagonalBaixoEsquerda(matriz_t * m, elemento_t * e, int cor_peca, int max_casas, int movimento, char *jogadaAtual);
elemento_t * percorre_diagonalCimaEsquerda(matriz_t * m, elemento_t * e, int cor_peca, int max_casas, int movimento, char *jogadaAtual);
elemento_t * percorre_diagonalCimaDireita(matriz_t * m, elemento_t * e, int cor_peca, int max_casas, int movimento, char *jogadaAtual);
