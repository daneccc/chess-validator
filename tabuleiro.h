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


/*prototipos das funcoes do arquivo tabuleiro.c*/
matriz_t * matriz_criar(int linhas, int colunas);
void matriz_destruir(matriz_t * m);
elemento_t * matriz_obter_elemento(matriz_t * m, int col, int linha);
void matriz_setar_elemento( matriz_t * m, int col, int linha, int cor, int macro_peca, char peca, char colunaT, char linhaT);
void matriz_debug( matriz_t * m);
void mostrar_tabuleiro(matriz_t * m);
void iniciar_tabuleiro(matriz_t * m);


