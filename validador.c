#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "validador.h"
#include "movimentos.h"
#include "xadrez.h"


/*funcao para verificar a jogada*/
int valida_jogada(char *jogadaAtual, matriz_t * m, int cor_peca, int *junk, char *punct) {

    /*verifica se eh fim de jogo e printa na tela algumas informacoes*/
    if(cor_peca == 99) {
        if(punct[0] == '/') {
            printf("Empate. FIM DE JOGO.\n");
            exit(1);
        } else if (*junk == 0) {
            printf("\n%lc Pretas vencem. FIM DE JOGO. %lc\n", 0x2605, 0x2605);
            exit(1);
        }
        printf("\n===> Rodada %d:\n", *junk); //printa a rodada da vez antes da branca jogar
        printf("\nBrancas jogam!\n");
    }
    else {
        if(jogadaAtual[0] == '1') {
            printf("\n%lc Brancas vencem. FIM DE JOGO. %lc\n", 0x2605, 0x2605);
            exit(1);
        }
        printf("\nPretas jogam!\n");
    }

    identifica_peca(jogadaAtual, m, cor_peca, junk);
    return 1;
}


/*funcao que identifica a peca de acordo com o primeiro caractere*/
void identifica_peca(char *jogadaAtual, matriz_t * m, int cor_peca, int *junk) {
    char c = jogadaAtual[0], *cor; //o primeiro caractere vai identificar qual a peca
    
    int linha, coluna, movimento;

    if(cor_peca == 99)
        cor = "brancas";
    else
        cor = "pretas";

    /*chama a funcao para identificar o tipo de movimento da jogadaAtual*/
    movimento = identifica_movimento(jogadaAtual); 

    linha = gera_linha(jogadaAtual, movimento); /*identifica qual a linha da matriz vai receber a jogada*/
    coluna = gera_coluna(jogadaAtual, movimento); /*identifica qual a coluna da matriz vai receber a jogada*/


    if (c == 'a' || c == 'b' || c == 'c' || c == 'd' ||c == 'e' ||c == 'f' || c == 'g' || c == 'h') { //identifica o PEAO se o primeiro char for letra minuscula
        mover_peao(m, coluna, linha, cor_peca, movimento, jogadaAtual, junk);
        
    } else {

        switch(c) {
            case 'R': //identifica a TORRE
                mover_torre(m, coluna, linha, cor_peca, movimento, jogadaAtual, junk);
                break;

            case 'N': //identifica o CAVALO
                mover_cavalo(m, coluna, linha, cor_peca, movimento, jogadaAtual, junk);
                break;

            case 'B': //identifica o BISPO
                mover_bispo(m, coluna, linha, cor_peca, movimento, jogadaAtual, junk);
                break;

            case 'K': //identifica o REI
                mover_rei(m, coluna, linha, cor_peca, movimento, jogadaAtual, junk);
                break;

            case 'Q': //identifica a RAINHA
                mover_rainha(m, coluna, linha, cor_peca, movimento, jogadaAtual, junk);
                break;

            case 'O': //identifica o movimento ROQUE
                if(jogadaAtual[3] == '-') {
                    roque_maior(m, cor_peca, junk);
                    break;
                }
                roque_menor(m, cor_peca, junk);
                break;

            default:
                printf("Erro na jogada de numero %d das pecas %s!\n", *junk, cor);
                exit(1);                
        }
    }
}


/*funcao que vai identificar o tipo de movimento que qualquer peca realiza*/
int identifica_movimento(char *jogadaAtual) {
    /*
        retorna 1 se o movimento for normal
        retorna 2 se o mov for amb coluna
        retorna 3 se o mov for amb linha     
        retorna 4 se o mov for captura
        retorna 5 se o mov for captura amb coluna
        retorna 6 se o mov for captura amb linha
        retorna 7 se o mov for captura com promocao de peao
        retorna 8 se o mov for normal com promocao de peao
    */
   char c0, c1, c2, c3, c4, c5;

    c0 = jogadaAtual[0];
    c1 = jogadaAtual[1];
    c2 = jogadaAtual[2];
    c3 = jogadaAtual[3];
    c4 = jogadaAtual[4];
    c5 = jogadaAtual[5];

    if(islower(c0)) { //SE A JOGADA FOR DE PEAO
        if(c2 == '=') //se eh um movimento tipo b8=R
            return 8;
        else if(c4 == '=') //se eh um movimento tipo cxb1=Q
            return 7;
        else if(isdigit(c1)) //se eh um movimento tipo e4
            return 1;
        else if(c1 == 'x')  //se eh um movimento tipo exd5
            return 4;
      
    }

    else {
        if(isdigit(c2)) { //entao eh tipo Nh3 ou Kd5
            return 1;
        }
        else if(isdigit(c3)) {
            if(c1 == 'x') //caso em que Nxd3
                return 4;
            else if(isdigit(c1)) //caso em que N4f7
                return 3;
            else if(islower(c1)) //caso em que Ncd3
                return 2;
        }
        else if(isdigit(c4)) {
            if(isdigit(c1) && c2 == 'x') //caso em que N4xf7
                return 6;
            else if(islower(c1) && c2 == 'x') //caso em que Ncxd3
                return 5;
        }
    }
}


/*funcao que vai converter a linha representada no vetor jogadaAtual para a linha da matriz*/
int gera_linha(char *jogadaAtual, int movimento) {
    int linha, i = 0;

    if(movimento == 3)  //N3f7
        i = 3;
    if(movimento == 6)  //N4xg4
        i = 4;

    if(i == 0) {
        while(!isdigit(jogadaAtual[i])) {
            i++;
        } 
    }

    printf("Linha: %c ||", jogadaAtual[i]);
    linha = '8' - jogadaAtual[i]; 
    
    return linha;
}


/*funcao que vai converter a coluna representada no vetor jogadaAtual para a coluna da matriz*/
int gera_coluna(char *jogadaAtual, int movimento) {
    int coluna, i = 0;

    if(movimento == 3) //N3f7    Ngg5   R8b7 
        i = 2;
    if(movimento == 6) //N4xg4   N6xd4
        i = 3;

    if(i == 0) {
        while(!isdigit(jogadaAtual[i])) {
            i++;
        }
        i--;
    }

    printf(" Coluna: %c\n\n", jogadaAtual[i]);
    coluna = (jogadaAtual[i] - 'a');
    
    return coluna;
}
