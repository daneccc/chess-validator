#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "validador.h"
#include "movimentos.h"
#include "xadrez.h"

/* ESTRUTURA DE DADOS */

/* cria a matriz e aponta cada elemento (casa) pra baixo, cima, esquerda e direita */
matriz_t * matriz_criar(int linhas, int colunas) {
    setlocale(LC_CTYPE, ""); 

    int linha = 0;
    int coluna = 0;
    
    /* ponteiros auxiliares para setar as structs*/
    elemento_t * temp = NULL;
    elemento_t * prim = NULL; 
    elemento_t * aux_baixo = NULL; 
    elemento_t * aux_cima = NULL;
    elemento_t * inicio = NULL; //vai apontar pra primeira posicao da matriz posteriormente

    for( linha = 0; linha < linhas; linha++ ) {
        temp= NULL;

        for( coluna = 0; coluna < colunas; coluna++ ) {
            elemento_t * elemento = (elemento_t*) calloc( 1, sizeof(elemento_t) ); //aloca espaco para elemento


            if(!inicio) //se o inicio for null, inicio recebe o primeiro elemento
                inicio = elemento;
                elemento->esquerda = NULL;
            if(temp)
                temp->direita = elemento;
                
            elemento->esquerda = temp;
            temp = elemento;

        
            if( aux_baixo ) {
                int i = 0;
                elemento_t * aux = aux_baixo; //auxiliar recebe o primeiro da linha de cima

                for( i = 0; i < coluna; i++ )
                    aux = aux->direita;

                aux->abaixo = elemento;
                elemento->cima = aux;
            }

            if( coluna == 0 )
                prim = elemento;

            if(linha == 0)
                temp->cima = NULL;
                     
        }
        //ao pular de linha, o aux_baixo aponta para o primeiro elemento da linha de cima
        aux_baixo = prim;
    }

    matriz_t * m = (matriz_t*) calloc( 1, sizeof(matriz_t) );

    m->inicio = inicio;
    m->colunas = colunas;
    m->linhas = linhas;

    return m;
}

/*funcao para liberar a matriz*/
void matriz_destruir(matriz_t * m) {
    elemento_t * ec = m->inicio; 
    elemento_t * el = NULL;
    elemento_t * aux = NULL;

    while(ec) {
        el = ec->direita;

        while(el) {
            aux = el->direita;
            free(el);
            el = aux;
        }

        aux = ec->abaixo;
        free(ec);
        ec = aux;
    }

    free(m);
}


/*funcao que retorna o endereco de um elemento ao passar a linha e coluna da matriz*/
elemento_t * matriz_obter_elemento(matriz_t * m, int col, int linha) {
    int i = 0;
    elemento_t * e = m->inicio;

    for(i = 0; i < linha; i++)
        e = e->abaixo;

    for(i = 0; i < col; i++)
        e = e->direita;

    return e;
}


/* funcao que faz a struct elemento apontar para cada valor passado como paramentro */
void matriz_setar_elemento( matriz_t * m, int col, int linha, int cor, int macro_peca, char peca, char colunaT, char linhaT) {
    elemento_t * e = matriz_obter_elemento( m, col, linha );
    
    e->cor = cor; //cor da casa
    e->macro_peca = macro_peca; //macro da peca
    e->peca = peca; //recebe um char B se for branca ou char P se for preta
    e->linhaT = linhaT; //armazena a linha da matriz que o elemento se encontra
    e->colunaT = colunaT; //armazena a coluna da matriz que o elemento se encontra
}


/* funcao que printa todos os enderecos que os ponteiros apontam*/
void matriz_debug( matriz_t * m) {
    int l, c;

    printf("matriz=%p, colunas=%d, linhas=%d, inicio=%p\n", m, m->colunas, m->linhas, m->inicio );

    for(l = 0; l < m->linhas; l++) {
        for(c = 0; c < m->colunas; c++) {
            elemento_t * e = matriz_obter_elemento( m, c, l );
            printf("[%d][%d] # elemento=%p # abaixo=%p # cima=%p # dir=%p # esq=%p # peca=%c \n", l, c, e, e->abaixo, e->cima, e->direita, e->esquerda, e->peca);
        }
    }

}


/*funcao que printa o tabuleiro no terminal*/
void mostrar_tabuleiro(matriz_t * m) {
    int l, c, laux = 8;
        
    for(l = 0; l < m->linhas; l++) {
        printf("%d ", laux); //printa a linha na lateral esquerda do tabuleiro

        for(c = 0; c < m->colunas; c++) {
            elemento_t * e = matriz_obter_elemento(m, c, l);
            printf("%lc%lc%lc", e->cor, e->macro_peca, e->cor);
        } printf("\n");

        laux--;
    }
    printf("   a  b  c  d  e  f  g  h  \n"); //printa as colunas na parte de baixo do tabuleiro
}


/*funcao que preenche a matriz com as cores, pecas, cor da peca, coluna e linha*/
void iniciar_tabuleiro(matriz_t * m) {

    /*lembrando que a matriz 8x8 comeca com a linha e coluna de indice 0 ate 7*/ 
    /* preenchendo elementos da linha 0 (linha 8 no tabuleiro xadrez) */
    matriz_setar_elemento( m, 0, 0, CASA_CLARA, TORRE_PRETA, 'P', 'a', '8');
    matriz_setar_elemento( m, 1, 0, CASA_ESCURA, CAVALO_PRETO, 'P', 'b', '8');
    matriz_setar_elemento( m, 2, 0, CASA_CLARA, BISPO_PRETO, 'P', 'c', '8');
    matriz_setar_elemento( m, 3, 0, CASA_ESCURA, RAINHA_PRETA , 'P', 'd', '8');
    matriz_setar_elemento( m, 4, 0, CASA_CLARA, REI_PRETO , 'P', 'e', '8');
    matriz_setar_elemento( m, 5, 0, CASA_ESCURA, BISPO_PRETO, 'P', 'f', '8');
    matriz_setar_elemento( m, 6, 0, CASA_CLARA, CAVALO_PRETO , 'P', 'g', '8');
    matriz_setar_elemento( m, 7, 0, CASA_ESCURA, TORRE_PRETA, 'P', 'h', '8');

    /*preenchendo elementos da linha 1 (linha 7 no tabuleiro xadrez)*/
    matriz_setar_elemento( m, 0, 1, CASA_ESCURA, PEAO_PRETO, 'P', 'a', '7');
    matriz_setar_elemento( m, 1, 1, CASA_CLARA, PEAO_PRETO, 'P', 'b', '7');
    matriz_setar_elemento( m, 2, 1, CASA_ESCURA, PEAO_PRETO, 'P', 'c', '7');
    matriz_setar_elemento( m, 3, 1, CASA_CLARA, PEAO_PRETO, 'P', 'd', '7');
    matriz_setar_elemento( m, 4, 1, CASA_ESCURA, PEAO_PRETO, 'P', 'e', '7');
    matriz_setar_elemento( m, 5, 1, CASA_CLARA, PEAO_PRETO, 'P', 'f', '7');
    matriz_setar_elemento( m, 6, 1, CASA_ESCURA, PEAO_PRETO, 'P', 'g', '7');
    matriz_setar_elemento( m, 7, 1, CASA_CLARA, PEAO_PRETO, 'P', 'h', '7');

    /*preenchendo os elementos da linha 2 (linha 6 no tabuleiro xadrez)*/
    matriz_setar_elemento( m, 0, 2, CASA_CLARA, CASA_CLARA, ' ', 'a', '6');
    matriz_setar_elemento( m, 1, 2, CASA_ESCURA, CASA_ESCURA, ' ', 'b', '6');
    matriz_setar_elemento( m, 2, 2, CASA_CLARA, CASA_CLARA, ' ', 'c', '6');
    matriz_setar_elemento( m, 3, 2, CASA_ESCURA, CASA_ESCURA, ' ', 'd', '6');
    matriz_setar_elemento( m, 4, 2, CASA_CLARA, CASA_CLARA, ' ', 'e', '6');
    matriz_setar_elemento( m, 5, 2, CASA_ESCURA, CASA_ESCURA, ' ', 'f', '6');
    matriz_setar_elemento( m, 6, 2, CASA_CLARA, CASA_CLARA, ' ', 'g', '6');
    matriz_setar_elemento( m, 7, 2, CASA_ESCURA, CASA_ESCURA, ' ', 'h', '6');

    /*preenchendo os elementos da linha 3 (linha 5 no tabuleiro xadrez)*/
    matriz_setar_elemento( m, 0, 3, CASA_ESCURA, CASA_ESCURA, ' ', 'a', '5');
    matriz_setar_elemento( m, 1, 3, CASA_CLARA, CASA_CLARA, ' ', 'b', '5');
    matriz_setar_elemento( m, 2, 3, CASA_ESCURA, CASA_ESCURA, ' ', 'c', '5');
    matriz_setar_elemento( m, 3, 3, CASA_CLARA, CASA_CLARA, ' ', 'd', '5');
    matriz_setar_elemento( m, 4, 3, CASA_ESCURA, CASA_ESCURA, ' ', 'e', '5');
    matriz_setar_elemento( m, 5, 3, CASA_CLARA, CASA_CLARA, ' ', 'f', '5');
    matriz_setar_elemento( m, 6, 3, CASA_ESCURA, CASA_ESCURA, ' ', 'g', '5');
    matriz_setar_elemento( m, 7, 3, CASA_CLARA, CASA_CLARA, ' ', 'h', '5');

    /*preenchendo os elementos da linha 4 (linha 4 no tabuleiro xadrez)*/
    matriz_setar_elemento( m, 0, 4, CASA_CLARA, CASA_CLARA, ' ', 'a', '4');
    matriz_setar_elemento( m, 1, 4, CASA_ESCURA, CASA_ESCURA, ' ', 'b', '4');
    matriz_setar_elemento( m, 2, 4, CASA_CLARA, CASA_CLARA, ' ', 'c', '4');
    matriz_setar_elemento( m, 3, 4, CASA_ESCURA, CASA_ESCURA, ' ', 'd', '4');
    matriz_setar_elemento( m, 4, 4, CASA_CLARA, CASA_CLARA, ' ', 'e', '4');
    matriz_setar_elemento( m, 5, 4, CASA_ESCURA, CASA_ESCURA, ' ', 'f', '4');
    matriz_setar_elemento( m, 6, 4, CASA_CLARA, CASA_CLARA, ' ', 'g', '4');
    matriz_setar_elemento( m, 7, 4, CASA_ESCURA, CASA_ESCURA, ' ', 'h', '4');

    /*preenchendo os elementos da linha 5 (linha 3 no tabuleiro xadrez)*/
    matriz_setar_elemento( m, 0, 5, CASA_ESCURA, CASA_ESCURA, ' ', 'a', '3');
    matriz_setar_elemento( m, 1, 5, CASA_CLARA, CASA_CLARA, ' ', 'b', '3');
    matriz_setar_elemento( m, 2, 5, CASA_ESCURA, CASA_ESCURA, ' ', 'c', '3');
    matriz_setar_elemento( m, 3, 5, CASA_CLARA, CASA_CLARA, ' ', 'd', '3');
    matriz_setar_elemento( m, 4, 5, CASA_ESCURA, CASA_ESCURA, ' ', 'e', '3');
    matriz_setar_elemento( m, 5, 5, CASA_CLARA, CASA_CLARA, ' ', 'f', '3');
    matriz_setar_elemento( m, 6, 5, CASA_ESCURA, CASA_ESCURA, ' ', 'g', '3');
    matriz_setar_elemento( m, 7, 5, CASA_CLARA, CASA_CLARA, ' ', 'h', '3');     

    /*preenchendo os elementos da linha 6 (linha 2 no tabuleiro xadrez)*/
    matriz_setar_elemento( m, 0, 6, CASA_CLARA, PEAO_BRANCO, 'B', 'a', '2');
    matriz_setar_elemento( m, 1, 6, CASA_ESCURA, PEAO_BRANCO, 'B', 'b', '2');
    matriz_setar_elemento( m, 2, 6, CASA_CLARA, PEAO_BRANCO, 'B', 'c', '2');
    matriz_setar_elemento( m, 3, 6, CASA_ESCURA, PEAO_BRANCO, 'B', 'd', '2');
    matriz_setar_elemento( m, 4, 6, CASA_CLARA, PEAO_BRANCO, 'B', 'e', '2');
    matriz_setar_elemento( m, 5, 6, CASA_ESCURA, PEAO_BRANCO, 'B', 'f', '2');
    matriz_setar_elemento( m, 6, 6, CASA_CLARA, PEAO_BRANCO, 'B', 'g', '2');
    matriz_setar_elemento( m, 7, 6, CASA_ESCURA, PEAO_BRANCO, 'B', 'h', '2');

    /*preenchendo os elementos da linha 7 (linha 1 no tabuleiro xadrez)*/
    matriz_setar_elemento( m, 0, 7, CASA_ESCURA, TORRE_BRANCA, 'B', 'a', '1');
    matriz_setar_elemento( m, 1, 7, CASA_CLARA, CAVALO_BRANCO, 'B', 'b', '1');
    matriz_setar_elemento( m, 2, 7, CASA_ESCURA, BISPO_BRANCO, 'B', 'c', '1');
    matriz_setar_elemento( m, 3, 7, CASA_CLARA, RAINHA_BRANCA , 'B', 'd', '1');
    matriz_setar_elemento( m, 4, 7, CASA_ESCURA, REI_BRANCO, 'B', 'e', '1');
    matriz_setar_elemento( m, 5, 7, CASA_CLARA, BISPO_BRANCO, 'B', 'f', '1');
    matriz_setar_elemento( m, 6, 7, CASA_ESCURA, CAVALO_BRANCO, 'B', 'g', '1');
    matriz_setar_elemento( m, 7, 7, CASA_CLARA, TORRE_BRANCA, 'B', 'h', '1');

}