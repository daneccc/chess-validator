typedef struct elemento_s elemento_t;
typedef struct matriz_s matriz_t;

/* cria struct com todos os campos uteis */ 
struct elemento_s {
    elemento_t *abaixo;
    elemento_t *direita;
    elemento_t *esquerda;
    elemento_t *cima; 
    int cor, macro_peca; //cor eh a cor da casa do tabuleiro, macro peca eh a peca
    char peca; //se eh preta ou branca
    char colunaT; //guarda a coluna de cada struct
    char linhaT; //guarda a linha de cada struct
};

/* cria struct matriz */
struct matriz_s {
    elemento_t *inicio;
    int linhas;
    int colunas;
};

/*funcao que cria a estrutura de dados da matriz*/
matriz_t * matriz_criar(int linhas, int colunas);

void matriz_destruir(matriz_t * m);

elemento_t * matriz_obter_elemento(matriz_t * m, int col, int linha);

void matriz_setar_elemento( matriz_t * m, int col, int linha, int cor, int macro_peca, char peca, char colunaT, char linhaT);

void matriz_debug( matriz_t * m);

void mostrar_tabuleiro(matriz_t * m);

void iniciar_tabuleiro(matriz_t * m);




int valida_jogada(char *jogadaAtual, matriz_t * m, int cor_peca);

void identifica_peca(char *jogadaAtual, matriz_t * m, int cor_peca);

int identifica_movimento(char *jogadaAtual);

int gera_coluna(char *jogadaAtual, int movimento);

int gera_linha(char *jogadaAtual, int movimento);



matriz_t * mover_peao(matriz_t * m, int col, int linha, int cor_peca, int movimento, char *jogadaAtual);
matriz_t * mover_cavalo(matriz_t * m, int col, int linha, int cor_peca, int movimento, char *jogadaAtual);
matriz_t * mover_rei(matriz_t * m, int col, int linha, int cor_peca, int movimento, char *jogadaAtual);
matriz_t * mover_torre(matriz_t * m, int col, int linha, int cor_peca, int movimento, char *jogadaAtual);
matriz_t * mover_bispo(matriz_t * m, int col, int linha, int cor_peca, int movimento, char *jogadaAtual);
matriz_t * mover_rainha(matriz_t * m, int col, int linha, int cor_peca, int movimento, char *jogadaAtual);
matriz_t * roque_menor(matriz_t * m, int cor_peca);
matriz_t * roque_maior(matriz_t * m, int cor_peca);

elemento_t * percorre_abaixo(matriz_t * m, elemento_t * e, int cor_peca, int max_casas, int movimento, char *jogadaAtual);
elemento_t * percorre_direita(matriz_t * m, elemento_t * e, int cor_peca, int max_casas, int movimento, char *jogadaAtual);
elemento_t * percorre_esquerda(matriz_t * m, elemento_t * e, int cor_peca, int max_casas, int movimento, char *jogadaAtual);
elemento_t * percorre_cima(matriz_t * m, elemento_t * e, int cor_peca, int max_casas, int movimento, char *jogadaAtual);

elemento_t * percorre_diagonalBaixoDireita(matriz_t * m, elemento_t * e, int cor_peca, int max_casas, int movimento, char *jogadaAtual);
elemento_t * percorre_diagonalBaixoEsquerda(matriz_t * m, elemento_t * e, int cor_peca, int max_casas, int movimento, char *jogadaAtual);
elemento_t * percorre_diagonalCimaEsquerda(matriz_t * m, elemento_t * e, int cor_peca, int max_casas, int movimento, char *jogadaAtual);
elemento_t * percorre_diagonalCimaDireita(matriz_t * m, elemento_t * e, int cor_peca, int max_casas, int movimento, char *jogadaAtual);
