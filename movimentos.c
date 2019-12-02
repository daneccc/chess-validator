#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "validador.h"
#include "movimentos.h"
#include "xadrez.h"


/*funcao que, a partir da casa que vai receber a peca, percorre para baixo procurando a peca do movimento*/
elemento_t * percorre_abaixo(matriz_t * m, elemento_t * e, int cor_peca, int max_casas, int movimento, char *jogadaAtual) {
    elemento_t * aux = NULL;
    int casas_percorridas = 0;

    aux = e->abaixo; 

    while(aux != NULL && casas_percorridas < max_casas){
        if(aux->macro_peca == cor_peca) { //se for a peca procurada
            if(movimento == 1 || movimento == 4 || movimento == 7 || movimento == 8) {
                return aux;
            }

            else if(movimento == 3 || movimento == 6) {
                if(aux->linhaT == jogadaAtual[1])
                    return aux;
                else return 0;
            } 

            else if(movimento == 2 || movimento == 5) {
                if(aux->colunaT == jogadaAtual[1])
                    return aux;
                else return 0;
            }
            
        } else if(aux->macro_peca != aux->cor) {
            return 0;
        }
        //continua percorrendo pra baixo
        aux = aux->abaixo;
        casas_percorridas++;
    }

    return 0;
}


/*funcao que, a partir da casa que vai receber a peca, percorre para direita procurando a peca do movimento*/
elemento_t * percorre_direita(matriz_t * m, elemento_t * e, int cor_peca, int max_casas, int movimento, char *jogadaAtual) {
    elemento_t * aux = NULL;
    int casas_percorridas = 0;

    aux = e->direita;

    while(aux != NULL && casas_percorridas < max_casas){
        if(aux->macro_peca == cor_peca) {
            if(movimento == 1 || movimento == 4 || movimento == 7 || movimento == 8) {
                return aux;
            }

            else if(movimento == 3 || movimento == 6) {
                if(aux->linhaT == jogadaAtual[1])
                    return aux;
                else return 0;
            } 

            else if(movimento == 2 || movimento == 5) {
                if(aux->colunaT == jogadaAtual[1])
                    return aux;
                else return 0;
            }
        } else if(aux->macro_peca != aux->cor) {
            return 0;
        }
        //continua percorrendo pra direita
        aux = aux->direita;
        casas_percorridas++;
    }

    return 0;
}


/*funcao que, a partir da casa que vai receber a peca, percorre para esquerda procurando a peca do movimento*/
elemento_t * percorre_esquerda(matriz_t * m, elemento_t * e, int cor_peca, int max_casas, int movimento, char *jogadaAtual) {
    elemento_t * aux = NULL;
    int casas_percorridas = 0;

    aux = e->esquerda;

    while(aux != NULL && casas_percorridas < max_casas) {
        if(aux->macro_peca == cor_peca) {
            if(movimento == 1 || movimento == 4 || movimento == 7 || movimento == 8) {
                return aux;
            }

            else if(movimento == 3 || movimento == 6) {
                if(aux->linhaT == jogadaAtual[1])
                    return aux;
                else return 0;
            } 

            else if(movimento == 2 || movimento == 5) {
                if(aux->colunaT == jogadaAtual[1])
                    return aux;
                else return 0;
            }
        } else if(aux->macro_peca != aux->cor) {
            return 0;
        }
        //continua percorrendo pra esquerda
        aux = aux->esquerda;
        casas_percorridas++;
    }
    
    return 0;
}


/*funcao que, a partir da casa que vai receber a peca, percorre para cima procurando a peca do movimento*/
elemento_t * percorre_cima(matriz_t * m, elemento_t * e, int cor_peca, int max_casas, int movimento, char *jogadaAtual) {
    elemento_t * aux = NULL;
    int casas_percorridas = 0;
   
    aux = e->cima;

    while(aux != NULL && casas_percorridas < max_casas){
        if(aux->macro_peca == cor_peca) {
            if(movimento == 1 || movimento == 4 || movimento == 7 || movimento == 8) {
                return aux;
            }
            else if(movimento == 3 || movimento == 6) {
                // if((aux->linhaT + '0') == jogadaAtual[1])
                if(aux->linhaT == jogadaAtual[1]) //AAAAAAAAAAAAAAAAAAAAAAAAaaaaaaaaaaaaaaaaaa
                    return aux;
                else return 0;
            } 

            else if(movimento == 2 || movimento == 5) {
                if(aux->colunaT == jogadaAtual[1])
                    return aux;
                else return 0;
            }
        } else if(aux->macro_peca != aux->cor) {
            return 0;
        }
        //continua percorrendo pra cima
        aux = aux->cima;
        casas_percorridas++;
    }

    return 0;
}


/*funcao que, a partir da casa que vai receber a peca, percorre para diagonal cima direita procurando a peca do movimento*/
elemento_t * percorre_diagonalCimaDireita(matriz_t * m, elemento_t * e, int cor_peca, int max_casas, int movimento, char *jogadaAtual) {
    elemento_t * aux = NULL;
    int casas_percorridas = 0;

    // aux = e->cima->direita;
    aux = e->cima;
    if(aux != NULL) {
        aux = aux->direita;
    }

    while(aux != NULL && casas_percorridas < max_casas) {
        if(aux->macro_peca == cor_peca) {
            if(movimento == 1 || movimento == 4 || movimento == 7 || movimento == 8) {
                return aux;
            }
            else if(movimento == 3 || movimento == 6) {

                if(aux->linhaT == jogadaAtual[1]) 
                    return aux;
                else return 0;
            } 

            else if(movimento == 2 || movimento == 5) {
                if(aux->colunaT == jogadaAtual[1])
                    return aux;
                else return 0;
            }
        } else if (aux->macro_peca != aux->cor) {
            return 0;
        }
        //continua percorrendo pra cima direita (diagonal)
        // aux = aux->cima->direita;
        aux = aux->cima;
        if(aux != NULL) {
            aux = aux->direita;
        }
        casas_percorridas++;
    }

    return 0;
}


/*funcao que, a partir da casa que vai receber a peca, percorre para diagonal cima esquerda procurando a peca do movimento*/
elemento_t * percorre_diagonalCimaEsquerda(matriz_t * m, elemento_t * e, int cor_peca, int max_casas, int movimento, char *jogadaAtual) {
    elemento_t * aux = NULL;
    int casas_percorridas = 0;

    // aux = e->cima->esquerda;
    aux = e->cima;
    if(aux != NULL) {
        aux = aux->esquerda;
    }

    while(aux != NULL && casas_percorridas < max_casas) {
        if(aux->macro_peca == cor_peca) {
            if(movimento == 1 || movimento == 4 || movimento == 7 || movimento == 8) {
                return aux;
            }

            else if(movimento == 3 || movimento == 6) {
                if(aux->linhaT == jogadaAtual[1])
                    return aux;
                else return 0;
            } 

            else if(movimento == 2 || movimento == 5) {
                if(aux->colunaT == jogadaAtual[1])
                    return aux;
                else return 0;
            }
        } else if (aux->macro_peca != aux->cor) {
            return 0;
        }
        //continua percorrendo pra cima esquerda (diagonal)
        // aux = aux->cima->esquerda;
        aux = aux->cima;
        if(aux != NULL) {
            aux = aux->esquerda;
        }
        casas_percorridas++;
    }

    return 0;
}


/*funcao que, a partir da casa que vai receber a peca, percorre para diagonal baixo esquerda procurando a peca do movimento*/
elemento_t * percorre_diagonalBaixoEsquerda(matriz_t * m, elemento_t * e, int cor_peca, int max_casas, int movimento, char *jogadaAtual) {
    elemento_t * aux = NULL;
    int casas_percorridas = 0;

    // aux = e->abaixo->esquerda;
    aux = e->abaixo;
    if(aux != NULL) {
        aux = aux->esquerda;
    }

    while(aux != NULL && casas_percorridas < max_casas) {
        if(aux->macro_peca == cor_peca) {
            if(movimento == 1 || movimento == 4 || movimento == 7 || movimento == 8) {
                return aux;
            }

            else if(movimento == 3 || movimento == 6) {
                if(aux->linhaT == jogadaAtual[1])
                    return aux;
                else return 0;
            } 

            else if(movimento == 2 || movimento == 5) {
                if(aux->colunaT == jogadaAtual[1])
                    return aux;
                else return 0;
            }
        } else if (aux->macro_peca != aux->cor) {
            return 0;
        }
        //continua percorrendo pra baixo esquerda (diagonal)
        // aux = aux->abaixo->esquerda;
        aux = aux->abaixo;
        if(aux != NULL) {
            aux = aux->esquerda;
        }
        casas_percorridas++;
    }
    
    return 0;
}


/*funcao que, a partir da casa que vai receber a peca, percorre para diagonal baixo direita procurando a peca do movimento*/
elemento_t * percorre_diagonalBaixoDireita(matriz_t * m, elemento_t * e, int cor_peca, int max_casas, int movimento, char *jogadaAtual) {
    elemento_t * aux = NULL;
    int casas_percorridas = 0;
    
    // aux = e->abaixo->direita;
    aux = e->abaixo;
    if(aux != NULL) {
        aux = aux->direita;
    }
    while(aux != NULL && casas_percorridas < max_casas) {
        if(aux->macro_peca == cor_peca) {
            if(movimento == 1 || movimento == 4 || movimento == 7 || movimento == 8) {
                return aux;
            }

            else if(movimento == 3 || movimento == 6) {
                if(jogadaAtual[1] == aux->linhaT)
                    return aux;
                else return 0;
            } 

            else if(movimento == 2 || movimento == 5) {
                if(jogadaAtual[1] == aux->colunaT)
                    return aux;
                else return 0;
            }
        } else if (aux->macro_peca != aux->cor) {
            return 0;
        }
        //continua percorrendo pra baixo direita (diagonal)
        // aux = aux->abaixo->direita;
        aux = aux->abaixo;
        if(aux != NULL) {
            aux = aux->direita;
        }
        
        casas_percorridas++;
    }

    return 0;
}


/*============================================================================================================*/
/*============================================================================================================*/
/*============================================================================================================*/


/*funcao que move a torre ao receber a linha e coluna de destino na matriz, se eh jogada da branca ou preta, o tipo de movimento, e o vetor da jogada para analise*/
matriz_t * mover_torre(matriz_t * m, int col, int linha, int cor_peca, int movimento, char *jogadaAtual) {
    elemento_t * e = matriz_obter_elemento(m, col, linha); //recebe o endereco da casa destino do movimento 
    elemento_t * aux = NULL;

    int cor_torre;
    char cor_adversario, cor_dele;

    if(cor_peca == 99) {
        cor_torre = TORRE_BRANCA;
        cor_adversario = 'P';
        cor_dele = 'B';
    } else {
        cor_torre = TORRE_PRETA;
        cor_adversario = 'B';
        cor_dele = 'P';
    }

    /*primeiro deve-se checar qual o conteudo da casa de destino de acordo com o movimento a ser realizado*/
    if(movimento == 1 || movimento == 2 || movimento == 3) { /*se for movimento normal, a casa deve estar vazia*/
        if(e->macro_peca != e->cor) /*se a casa nao tiver vazia*/
            exit(1);
        
    } else if (movimento == 4 || movimento == 5 || movimento == 6) { /*se for captura, a casa deve estar com o adversario*/
        if(e->peca != cor_adversario) /*se na casa de destino nao tem uma peca adversaria*/
            exit(1); 
    }

    /*o aux chama a funcao parar percorrer, se houver algum retorno, a peca foi encontrada, entao eh realizado a troca entre a casa de destino e a casa da peca*/

    aux = percorre_abaixo(m, e, cor_torre, 8, movimento, jogadaAtual);
    if(aux != 0) {
        e->macro_peca = aux->macro_peca;
        e->peca = cor_dele;
        aux->macro_peca = aux->cor;
        aux->peca = ' ';
        return m; 
    }

    aux = percorre_direita(m, e, cor_torre, 8, movimento, jogadaAtual);
    if(aux != 0) {
        e->macro_peca = aux->macro_peca;
        e->peca = cor_dele;
        aux->macro_peca = aux->cor;
        aux->peca = ' ';
        return m; 
    }

    aux = percorre_esquerda(m, e, cor_torre, 8, movimento, jogadaAtual);
    if(aux != 0) {
        e->macro_peca = aux->macro_peca;
        e->peca = cor_dele;
        aux->macro_peca = aux->cor;
        aux->peca = ' ';
        return m;
    }

    aux = percorre_cima(m, e, cor_torre, 8, movimento, jogadaAtual);
    if(aux != 0) {
        e->macro_peca = aux->macro_peca;
        e->peca = cor_dele;
        aux->macro_peca = aux->cor;
        aux->peca = ' ';
        return m;
    }

    /*se nenhuma torre for encontrada depois de percorrer todos os lados*/
    if(aux == NULL) {
        printf("ATENCAO: Torre nao pode realizar o movimento!\n");
        exit(1);
    }
}


/*funcao que move o bispo ao receber a linha e coluna de destino na matriz, se eh jogada da branca ou preta, o tipo de movimento, e o vetor da jogada para analise*/
matriz_t * mover_bispo(matriz_t * m, int col, int linha, int cor_peca, int movimento, char *jogadaAtual) {
    elemento_t * e = matriz_obter_elemento(m, col, linha);
    elemento_t * aux = NULL;
    int c = col;
    int l = linha;
    int cor_bispo;
    char cor_adversario, cor_dele;

    if(cor_peca == 99) {
        cor_bispo = BISPO_BRANCO;
        cor_adversario = 'P';
        cor_dele = 'B';
    } else {
        cor_bispo = BISPO_PRETO;
        cor_adversario = 'B';
        cor_dele = 'P';
    }

    //primeiro vou checar qual o conteudo da casa de destino de acordo com o movimento a ser realizado
    if(movimento == 1 || movimento == 2 || movimento == 3) { //se for movimento normal
        if(e->macro_peca != e->cor) //se a casa nao tiver vazia
            exit(1);
        
    } else if (movimento == 4 || movimento == 5 || movimento == 6) { //se for captura
        if(e->peca != cor_adversario) //se na casa de destino nao tem uma peca adversaria
            exit(1); 
    }

    /*o aux chama a funcao parar percorrer, se houver algum retorno, a peca foi encontrada, entao eh realizado a troca entre a casa de destino e a casa da peca*/

    aux = percorre_diagonalBaixoDireita(m, e, cor_bispo, 8, movimento, jogadaAtual);
    if(aux != 0) { 
        e->macro_peca = aux->macro_peca;
        e->peca = cor_dele;
        aux->macro_peca = aux->cor;
        aux->peca = ' ';
        return m; 
    }

    aux = percorre_diagonalBaixoEsquerda(m, e, cor_bispo, 8, movimento, jogadaAtual);
    if(aux != 0) {
        e->macro_peca = aux->macro_peca;
        e->peca = cor_dele;
        aux->macro_peca = aux->cor;
        aux->peca = ' ';
        return m; 
    }
 
    aux = percorre_diagonalCimaDireita(m, e, cor_bispo, 8, movimento, jogadaAtual);
    if(aux != 0) {
        e->macro_peca = aux->macro_peca;
        e->peca = cor_dele;
        aux->macro_peca = aux->cor;
        aux->peca = ' ';
        return m;
    }
  
    aux = percorre_diagonalCimaEsquerda(m, e, cor_bispo, 8, movimento, jogadaAtual);
    if(aux != 0) { 
        e->macro_peca = aux->macro_peca;
        e->peca = cor_dele;
        aux->macro_peca = aux->cor;
        aux->peca = ' ';
        return m;
    }

    if(aux == NULL) {
        printf("ATENCAO: Bispo nao pode realizar o movimento!\n");
        exit(1);
    }

}


/*funcao que move a rainha ao receber a linha e coluna de destino na matriz, se eh jogada da branca ou preta, o tipo de movimento, e o vetor da jogada para analise*/
matriz_t * mover_rainha(matriz_t * m, int col, int linha, int cor_peca, int movimento, char *jogadaAtual) {
    elemento_t * e = matriz_obter_elemento(m, col, linha);
    elemento_t * aux = NULL;
    int c = col;
    int l = linha;
    int cor_rainha;
    char cor_adversario, cor_dele;

    if(cor_peca == 99) {
        cor_rainha = RAINHA_BRANCA;
        cor_adversario = 'P';
        cor_dele = 'B';
    } else {
        cor_rainha = RAINHA_PRETA;
        cor_adversario = 'B';
        cor_dele = 'P';
    }

    //primeiro vou checar qual o conteudo da casa de destino de acordo com o movimento a ser realizado
    if(movimento == 1 || movimento == 2 || movimento == 3) { //se for movimento normal, a casa de destino deve estar vazia
        if(e->macro_peca != e->cor) //se a casa nao tiver vazia
            exit(1);
        
    } else if (movimento == 4 || movimento == 5 || movimento == 6) { //se for captura
        if(e->peca != cor_adversario) //se na casa de destino nao tem uma peca adversaria
            exit(1); 
    }

    /*o aux chama a funcao parar percorrer, se houver algum retorno, a peca foi encontrada, entao eh realizado a troca entre a casa de destino e a casa da peca*/

    aux = percorre_abaixo(m, e, cor_rainha, 8, movimento, jogadaAtual);
    if(aux != 0) {
        e->macro_peca = aux->macro_peca;
        e->peca = cor_dele;
        aux->macro_peca = aux->cor;
        aux->peca = ' ';
        return m; 
    }

    aux = percorre_direita(m, e, cor_rainha, 8, movimento, jogadaAtual);
    if(aux != 0) {
        e->macro_peca = aux->macro_peca;
        e->peca = cor_dele;
        aux->macro_peca = aux->cor;
        aux->peca = ' ';
        return m; 
    }

    aux = percorre_esquerda(m, e, cor_rainha, 8, movimento, jogadaAtual);
    if(aux != 0) {
        e->macro_peca = aux->macro_peca;
        e->peca = cor_dele;
        aux->macro_peca = aux->cor;
        aux->peca = ' ';
        return m;
    }

    aux = percorre_cima(m, e, cor_rainha, 8, movimento, jogadaAtual);
    if(aux != 0) {
        e->macro_peca = aux->macro_peca;
        e->peca = cor_dele;
        aux->macro_peca = aux->cor;
        aux->peca = ' ';
        return m;
    }

    aux = percorre_diagonalBaixoDireita(m, e, cor_rainha, 8, movimento, jogadaAtual);
    if(aux != 0) {
        e->macro_peca = aux->macro_peca;
        e->peca = cor_dele;
        aux->macro_peca = aux->cor;
        aux->peca = ' ';
        return m; 
    }

    aux = percorre_diagonalBaixoEsquerda(m, e, cor_rainha, 8, movimento, jogadaAtual);
    if(aux != 0) {
        e->macro_peca = aux->macro_peca;
        e->peca = cor_dele;
        aux->macro_peca = aux->cor;
        aux->peca = ' ';
        return m; 
    }

    aux = percorre_diagonalCimaDireita(m, e, cor_rainha, 8, movimento, jogadaAtual);
    if(aux != 0) {
        e->macro_peca = aux->macro_peca;
        e->peca = cor_dele;
        aux->macro_peca = aux->cor;
        aux->peca = ' ';
        return m;
    }

    aux = percorre_diagonalCimaEsquerda(m, e, cor_rainha, 8, movimento, jogadaAtual);
    if(aux != 0) {
        e->macro_peca = aux->macro_peca;
        e->peca = cor_dele;
        aux->macro_peca = aux->cor;
        aux->peca = ' ';
        return m;
    }


    if(aux == NULL) {
        printf("ATENCAO: Rainha nao pode realizar o movimento!\n");
        exit(1);
    }

}


/*funcao que move o cavalo ao receber a linha e coluna de destino na matriz, se eh jogada da branca ou preta, o tipo de movimento, e o vetor da jogada para analise*/
matriz_t * mover_cavalo(matriz_t * m, int col, int linha, int cor_peca, int movimento, char *jogadaAtual) {
    elemento_t * e = matriz_obter_elemento(m, col, linha);
    elemento_t * aux = NULL, * aux1;
    int c = col;
    int l = linha;
    int cor_cavalo;
    char cor_adversario, cor_dele;

    if(cor_peca == 99) {
        cor_cavalo = CAVALO_BRANCO;
        cor_adversario = 'P';
        cor_dele = 'B';
    } else {
        cor_cavalo = CAVALO_PRETO;
        cor_adversario = 'B';
        cor_dele = 'P';
    }

    //primeiro vou checar qual o conteudo da casa de destino de acordo com o movimento a ser realizado
    if(movimento == 1 || movimento == 2 || movimento == 3) { //se for movimento normal
        if(e->macro_peca != e->cor) //se a casa tiver vazia
            exit(1);
        
    } else if (movimento == 4 || movimento == 5 || movimento == 6) { //se for captura
        if(e->peca != cor_adversario) //se na casa de destino tem uma peca adversaria
            exit(1); 
    }

    /*  logica para percorrer a partir da casa de destino procurando o cavalo: 
        se nao sai fora do tabuleiro (para nao dar falha de segmentacao)
            se a macro_peca do endereco apontado for o CAVALO procurado
                se estiver o cavalo encontrado estiver ok com o tipo do movimento
                    o aux recebe o endereco que contem o cavalo encontrado
        isso se repete para todos os tipos de movimento, porem so ha uma unica possibilidade que vai fazer o aux receber o endereco
        ao final, verifica se o movimento eh valido, ou seja, se o aux recebeu algum valor
        se sim, realiza a troca entre o aux e a casa de destino
        retorna a matriz
    */

    if(l-2>=0 && c-1>=0) {
        if(e->cima->cima->esquerda->macro_peca == cor_cavalo) {
            if(movimento == 1 || movimento == 4) {
                aux = e->cima->cima->esquerda;
            }
            else if(movimento == 3 || movimento == 6) {
                aux1 = e->cima->cima->esquerda;
                if(aux1->linhaT == jogadaAtual[1])
                    aux = aux1;
            }
            else if(movimento == 2 || movimento == 5) {
                aux1 = e->cima->cima->esquerda;
                if(aux1->colunaT == jogadaAtual[1])
                    aux = aux1;
            }
        }
    }
    if(l-2>=0 && c+1<=7) {
        if(e->cima->cima->direita->macro_peca == cor_cavalo) {
            // aux = e->cima->cima->direita;
            if(movimento == 1 || movimento == 4) {
                aux = e->cima->cima->direita;
            }
            else if(movimento == 3 || movimento == 6) {
                aux1 = e->cima->cima->direita;
                if(aux1->linhaT == jogadaAtual[1])
                    aux = aux1;
            }
            else if(movimento == 2 || movimento == 5) {
                aux1 = e->cima->cima->direita;
                if(aux1->colunaT == jogadaAtual[1])
                    aux = aux1;
            }
        }
    }
    if(l-1>=0 && c+2<=7) {
        if(e->direita->direita->cima->macro_peca == cor_cavalo) {
            // aux = e->direita->direita->cima;
            if(movimento == 1 || movimento == 4) {
                aux = e->direita->direita->cima;
            }
            else if(movimento == 3 || movimento == 6) {
                aux1 = e->direita->direita->cima;
                if(aux1->linhaT == jogadaAtual[1])
                    aux = aux1;
            }
            else if(movimento == 2 || movimento == 5) {
                aux1 = e->direita->direita->cima;
                if(aux1->colunaT == jogadaAtual[1])
                    aux = aux1;
            }
        }
    }
    if(l+1<=7 && c+2<=7) {
        if(e->direita->direita->abaixo->macro_peca == cor_cavalo) {
            // aux = e->direita->direita->abaixo;
            if(movimento == 1 || movimento == 4) {
                aux = e->direita->direita->abaixo;
            }
            else if(movimento == 3 || movimento == 6) {
                aux1 = e->direita->direita->abaixo;
                if(aux1->linhaT == jogadaAtual[1])
                    aux = aux1;
            }
            else if(movimento == 2 || movimento == 5) {
                aux1 = e->direita->direita->abaixo;
                if(aux1->colunaT == jogadaAtual[1])
                    aux = aux1;
            }
        }
    }
    if(l+2<=7 && c-1>=0) {    
        if(e->abaixo->abaixo->esquerda->macro_peca == cor_cavalo) {
            // aux = e->abaixo->abaixo->esquerda;
            if(movimento == 1 || movimento == 4) {
                aux = e->abaixo->abaixo->esquerda;
            }
            else if(movimento == 3 || movimento == 6) {
                aux1 = e->abaixo->abaixo->esquerda;
                if(aux1->linhaT == jogadaAtual[1])
                    aux = aux1;
            }
            else if(movimento == 2 || movimento == 5) {
                aux1 = e->abaixo->abaixo->esquerda;
                if(aux1->colunaT == jogadaAtual[1])
                    aux = aux1;
            }
        }
    }
    if(l+2<=7 && c+1<=7) {
        if(e->abaixo->abaixo->direita->macro_peca == cor_cavalo) {
            // aux = e->abaixo->abaixo->direita;
            if(movimento == 1 || movimento == 4) {
                aux = e->abaixo->abaixo->direita;
            }
            else if(movimento == 3 || movimento == 6) {
                aux1 = e->abaixo->abaixo->direita;
                if(aux1->linhaT == jogadaAtual[1])
                    aux = aux1;
            }
            else if(movimento == 2 || movimento == 5) {
                aux1 = e->abaixo->abaixo->direita;
                if(aux1->colunaT == jogadaAtual[1])
                    aux = aux1;
            }
        }
    }
    if(l-1>=0 && c-2>=0) {
        if(e->esquerda->esquerda->cima->macro_peca == cor_cavalo) {
            // aux = e->esquerda->esquerda->cima;
            if(movimento == 1 || movimento == 4) {
                aux = e->esquerda->esquerda->cima;
            }
            else if(movimento == 3 || movimento == 6) {
                aux1 = e->esquerda->esquerda->cima;
                if(aux1->linhaT == jogadaAtual[1])
                    aux = aux1;
            }
            else if(movimento == 2 || movimento == 5) {
                aux1 = e->esquerda->esquerda->cima;
                if(aux1->colunaT == jogadaAtual[1])
                    aux = aux1;
            }
        }
    }
    if(l+1<=7 && c-2>=0) {
        if(e->esquerda->esquerda->abaixo->macro_peca == cor_cavalo) {
            // aux = e->esquerda->esquerda->abaixo;
            if(movimento == 1 || movimento == 4) {
                aux = e->esquerda->esquerda->abaixo;
            }
            else if(movimento == 3 || movimento == 6) {
                aux1 = e->esquerda->esquerda->abaixo;
                if(aux1->linhaT == jogadaAtual[1])
                    aux = aux1;
            }
            else if(movimento == 2 || movimento == 5) {
                aux1 = e->esquerda->esquerda->abaixo;
                if(aux1->colunaT == jogadaAtual[1])
                    aux = aux1;
            }
        }
    }

    if(aux == NULL) {
        printf("ATENCAO: Cavalo nao pode realizar o movimento!\n");
        exit(1);
    }

    aux->macro_peca = aux->cor;
    aux->peca = ' ';
    e->macro_peca = cor_cavalo;
    e->peca = cor_dele;
    
    return m;
}


/*funcao que move o rei ao receber a linha e coluna de destino na matriz, se eh jogada da branca ou preta, o tipo de movimento, e o vetor da jogada para analise*/
matriz_t * mover_rei(matriz_t * m, int col, int linha, int cor_peca, int movimento, char *jogadaAtual) {
    elemento_t * e = matriz_obter_elemento(m, col, linha);
    elemento_t * aux = NULL;
    int c = col;
    int l = linha;
    int cor_rei;
    char cor_adversario, cor_dele;

    if(cor_peca == 99) {
        cor_rei = REI_BRANCO;
        cor_adversario = 'P';
        cor_dele = 'B';
    } else {
        cor_rei = REI_PRETO;
        cor_adversario = 'B';
        cor_dele = 'P';
    }

    //primeiro vou checar qual o conteudo da casa de destino de acordo com o movimento a ser realizado
    if(movimento == 1 || movimento == 2 || movimento == 3) { //se for movimento normal
        if(e->macro_peca != e->cor) //se a casa nao tiver vazia
            exit(1);
        
    } else if (movimento == 4 || movimento == 5 || movimento == 6) { //se for captura
        if(e->peca != cor_adversario) //se na casa de destino nao tem uma peca adversaria
            exit(1); 
    }

    /*o aux chama a funcao parar percorrer, se houver algum retorno, a peca foi encontrada, entao eh realizado a troca entre a casa de destino e a casa da peca*/

    aux = percorre_abaixo(m, e, cor_rei, 1, movimento, jogadaAtual);
    if(aux != 0) {
        e->macro_peca = aux->macro_peca;
        e->peca = cor_dele;
        aux->macro_peca = aux->cor;
        aux->peca = ' ';
        return m; 
    }

    aux = percorre_direita(m, e, cor_rei, 1, movimento, jogadaAtual);
    if(aux != 0) {
        e->macro_peca = aux->macro_peca;
        e->peca = cor_dele;
        aux->macro_peca = aux->cor;
        aux->peca = ' ';
        return m; 
    }

    aux = percorre_esquerda(m, e, cor_rei, 1, movimento, jogadaAtual);
    if(aux != 0) {
        e->macro_peca = aux->macro_peca;
        e->peca = cor_dele;
        aux->macro_peca = aux->cor;
        aux->peca = ' ';
        return m;
    }

    aux = percorre_cima(m, e, cor_rei, 1, movimento, jogadaAtual);
    if(aux != 0) {
        e->macro_peca = aux->macro_peca;
        e->peca = cor_dele;
        aux->macro_peca = aux->cor;
        aux->peca = ' ';
        return m;
    }

    aux = percorre_diagonalBaixoDireita(m, e, cor_rei, 1, movimento, jogadaAtual);
    if(aux != 0) {
        e->macro_peca = aux->macro_peca;
        e->peca = cor_dele;
        aux->macro_peca = aux->cor;
        aux->peca = ' ';
        return m; 
    }

    aux = percorre_diagonalBaixoEsquerda(m, e, cor_rei, 1, movimento, jogadaAtual);
    if(aux != 0) {
        e->macro_peca = aux->macro_peca;
        e->peca = cor_dele;
        aux->macro_peca = aux->cor;
        aux->peca = ' ';
        return m; 
    }

    aux = percorre_diagonalCimaDireita(m, e, cor_rei, 1, movimento, jogadaAtual);
    if(aux != 0) {
        e->macro_peca = aux->macro_peca;
        e->peca = cor_dele;
        aux->macro_peca = aux->cor;
        aux->peca = ' ';
        return m;
    }

    aux = percorre_diagonalCimaEsquerda(m, e, cor_rei, 1, movimento, jogadaAtual);
    if(aux != 0) {
        e->macro_peca = aux->macro_peca;
        e->peca = cor_dele;
        aux->macro_peca = aux->cor;
        aux->peca = ' ';
        return m;
    }

    /*se nao foi encontrado nenhum rei, entao a jogada eh invalida*/
    if(aux == NULL) {
        printf("ATENCAO: Rei nao pode realizar o movimento!\n");
        exit(1);
    }
}


/*funcao que move o peao ao receber a linha e coluna de destino na matriz, se eh jogada da branca ou preta, o tipo de movimento, e o vetor da jogada para analise*/
matriz_t * mover_peao(matriz_t * m, int col, int linha, int cor_peca, int movimento, char *jogadaAtual) {
    elemento_t * e = matriz_obter_elemento(m, col, linha);
    elemento_t * aux = NULL;
    int qtd_casas = 0;
    char cor_adversario, cor_dele;

    if(movimento == 1 || movimento == 8) { // se for MOVIMENTO NORMAL

        if(cor_peca == 99) { //se for movimento do PEAO BRANCO
            cor_adversario = 'P';
            cor_dele = 'B';

            if(linha == 4)  //se o peao pode pular duas casas ainda
                qtd_casas = 2;    
            else 
                qtd_casas = 1;
            
            aux = percorre_abaixo(m, e, PEAO_BRANCO, qtd_casas, movimento, jogadaAtual);
            if(aux != 0) { 
                aux->macro_peca = aux->cor;
                aux->peca = ' ';
                e->macro_peca = PEAO_BRANCO;
                e->peca = cor_dele;

                //PROMOCAO DO PEAO
                if(movimento == 8) {
                    if(jogadaAtual[3] == 'R') {
                        e->macro_peca = TORRE_BRANCA;
                    }
                    else if(jogadaAtual[3] == 'Q') {
                        e->macro_peca = RAINHA_BRANCA;
                    }
                    else if(jogadaAtual[3] == 'B') {
                        e->macro_peca = BISPO_BRANCO;
                    }
                    else if(jogadaAtual[3] == 'N') {
                        e->macro_peca = CAVALO_BRANCO;
                    }
                    else { 
                        printf("Nao foi possivel realizar a promocao do peao.\n");
                        exit(1);
                    }
                }
                return m;
            }

        } else { //se for movimento normal do PEAO PRETO
            cor_adversario = 'B';
            cor_dele = 'P';

            if(linha == 3)
                qtd_casas = 2;
            else
                qtd_casas = 1;
            
            aux = percorre_cima(m, e, PEAO_PRETO, qtd_casas, movimento, jogadaAtual);
            if(aux != 0) {
                aux->macro_peca = aux->cor;
                aux->peca = ' ';
                e->macro_peca = PEAO_PRETO;
                e->peca = cor_dele;

                if(movimento == 8) {
                    if(jogadaAtual[3] == 'R') {
                        e->macro_peca = TORRE_PRETA;
                    }
                    else if(jogadaAtual[3] == 'Q') {
                        e->macro_peca = RAINHA_PRETA;
                    }
                    else if(jogadaAtual[3] == 'B') {
                        e->macro_peca = BISPO_PRETO;
                    }
                    else if(jogadaAtual[3] == 'N') {
                        e->macro_peca = CAVALO_PRETO;
                    }
                    else { 
                        printf("Nao foi possivel realizar a promocao do peao.\n");
                        exit(1);
                    }
                }
                return m;
            }
        }

        //verifica se algum peao nao foi encontrado
        if(aux == NULL) {
            printf("ATENCAO: Peao nao pode realizar o movimento!\n");
            exit(1);
        }
    }

    else if(movimento == 4 || movimento == 7) { // se for CAPTURA DE PEAO
        //primeiro identifica de qual coluna o peao que come vai vir

        if(cor_peca == 99) { //se for jogada de BRANCO
            cor_adversario = 'P';
            cor_dele = 'B';

            aux = percorre_diagonalBaixoDireita(m, e, PEAO_BRANCO, 1, movimento, jogadaAtual);
            if(aux != 0) {
                if (jogadaAtual[0] == aux->colunaT) {
                    aux->macro_peca = aux->cor;
                    aux->peca = ' ';
                    e->macro_peca = PEAO_BRANCO;
                    e->peca = cor_dele;

                    //PROMOCAO DE PEAO
                    if(movimento == 7) {
                        if(jogadaAtual[5] == 'R') {
                            e->macro_peca = TORRE_BRANCA;
                            return m;
                        }
                        else if(jogadaAtual[5] == 'Q') {
                            e->macro_peca = RAINHA_BRANCA;
                            return m;
                        }
                        else if(jogadaAtual[5] == 'B') {
                            e->macro_peca = BISPO_BRANCO;
                            return m;
                        }
                        else if(jogadaAtual[5] == 'N') {
                            e->macro_peca = CAVALO_BRANCO;
                            return m;
                        }
                        else { 
                            printf("Nao foi possivel realizar a promocao do peao.\n");
                            exit(1);
                        }
                    }

                    return m;
                }
            } 

            aux = percorre_diagonalBaixoEsquerda(m, e, PEAO_BRANCO, 1, movimento, jogadaAtual);
            if(aux != 0) {            
                if (jogadaAtual[0] == aux->colunaT) {
                    aux->macro_peca = aux->cor;
                    aux->peca = ' ';
                    e->macro_peca = PEAO_BRANCO;
                    e->peca = cor_dele;

                    //PROMOCAO DE PEAO
                    if(movimento == 7) {
                        if(jogadaAtual[5] == 'R') {
                            e->macro_peca = TORRE_BRANCA;
                            return m;
                        }
                        else if(jogadaAtual[5] == 'Q') {
                            e->macro_peca = RAINHA_BRANCA;
                            return m;
                        }
                        else if(jogadaAtual[5] == 'B') {
                            e->macro_peca = BISPO_BRANCO;
                            return m;
                        }
                        else if(jogadaAtual[5] == 'N') {
                            e->macro_peca = CAVALO_BRANCO;
                            return m;
                        }
                        else { 
                            printf("Nao foi possivel realizar a promocao do peao.\n");
                            exit(1);
                        }
                    }

                    return m;
                }
            } 

        } else { //senao eh peao PRETO
            cor_adversario = 'B';
            cor_dele = 'P';

            aux = percorre_diagonalCimaDireita(m, e, PEAO_PRETO, 1, movimento, jogadaAtual);

            if(aux != 0) {
                if (jogadaAtual[0] == aux->colunaT) {
                    aux->macro_peca = aux->cor;
                    aux->peca = ' ';
                    e->macro_peca = PEAO_PRETO;
                    e->peca = cor_dele;

                    //PROMOCAO DE PEAO
                    if(movimento == 7) {
                        if(jogadaAtual[5] == 'R') {
                            e->macro_peca = TORRE_PRETA;
                            return m;
                        }
                        else if(jogadaAtual[5] == 'Q') {
                            e->macro_peca = RAINHA_PRETA;
                            return m;
                        }
                        else if(jogadaAtual[5] == 'B') {
                            e->macro_peca = BISPO_PRETO;
                            return m;
                        }
                        else if(jogadaAtual[5] == 'N') {
                            e->macro_peca = CAVALO_PRETO;
                            return m;
                        }
                        else { 
                            printf("Nao foi possivel realizar a promocao do peao.\n");
                            exit(1);
                        }
                    }

                    return m;
                }
            } 

            aux = percorre_diagonalCimaEsquerda(m, e, PEAO_PRETO, 1, movimento, jogadaAtual);
            if(aux != 0) {
                if (jogadaAtual[0] == aux->colunaT) {
                    aux->macro_peca = aux->cor;
                    aux->peca = ' ';
                    e->macro_peca = PEAO_PRETO;
                    e->peca = cor_dele;

                    //PROMOCAO DE PEAO
                    if(movimento == 7) {
                        if(jogadaAtual[5] == 'R') {
                            e->macro_peca = TORRE_PRETA;
                        }
                        else if(jogadaAtual[5] == 'Q') {
                            e->macro_peca = RAINHA_PRETA;
                        }
                        else if(jogadaAtual[5] == 'B') {
                            e->macro_peca = BISPO_PRETO;
                        }
                        else if(jogadaAtual[5] == 'N') {
                            e->macro_peca = CAVALO_PRETO;
                        }
                        else { 
                            printf("Nao foi possivel realizar a promocao do peao.\n");
                            exit(1);
                        }
                    }
                    return m;
                }
            } 
        }
        
    }

    //verifica de nenhum peao foi encontrado
    if(aux == NULL) {
        printf("ATENCAO: Peao nao pode realizar o movimento!\n");
        exit(1);
    }
}



/*
o rei BRANCO deve estar na coluna E e a torre BRANCA na coluna H, ambos linha 1
se g1 e f1 estiverem vazios e e1 for rei e h1 for torre
o rei branco move para g1
a torre branca move para f1
================================
o rei PRETO deve estar na coluna E e a torre PRETA na coluna H, ambos linha 1
se g8 e f8 estiverem vazios e e8 for rei e h8 for torre
o rei preto move para g8
a torre preta move para f8
*/
matriz_t * roque_menor(matriz_t * m, int cor_peca) {
    //se for jogada da peca BRANCA
    if(cor_peca == 99) {

        elemento_t * e1 = matriz_obter_elemento(m, 4, 7);
        elemento_t * f1 = matriz_obter_elemento(m, 5, 7);
        elemento_t * g1 = matriz_obter_elemento(m, 6, 7);
        elemento_t * h1 = matriz_obter_elemento(m, 7, 7);

        //verifica se o rei a torre estao na posicao correta e se o espaco eles entre ta vazio
        if(e1->macro_peca == REI_BRANCO && h1->macro_peca == TORRE_BRANCA) {
            if(f1->macro_peca == f1->cor && g1->macro_peca == g1->cor) {
                g1->macro_peca = REI_BRANCO;
                g1->peca = 'B';
                f1->macro_peca = TORRE_BRANCA;
                f1->peca = 'B';
                e1->macro_peca = e1->cor;
                e1->peca = ' ';
                h1->macro_peca = h1->cor;
                h1->peca = ' ';

                return m;
            }
        }
        printf("Roque invalido.\n");
        exit(1);

    //se for jogada da peca PRETA
    } else {

        elemento_t * e8 = matriz_obter_elemento(m, 4, 0);
        elemento_t * f8 = matriz_obter_elemento(m, 5, 0);
        elemento_t * g8 = matriz_obter_elemento(m, 6, 0);
        elemento_t * h8 = matriz_obter_elemento(m, 7, 0);

        //verifica se o rei a torre estao na posicao correta e se o espaco eles entre ta vazio
        if(e8->macro_peca == REI_PRETO && h8->macro_peca == TORRE_PRETA) {
            if(f8->macro_peca == f8->cor && g8->macro_peca == g8->cor) {
                g8->macro_peca = REI_PRETO;
                g8->peca = 'P';
                f8->macro_peca = TORRE_PRETA;
                f8->peca = 'P';
                e8->macro_peca = e8->cor;
                e8->peca = ' ';
                h8->macro_peca = h8->cor;
                h8->peca = ' ';

                return m;
            }
        }
        printf("Roque invalido.\n");
        exit(1);
    }
} 


matriz_t * roque_maior(matriz_t * m, int cor_peca) {
    //se for jogada da peca BRANCA
    if(cor_peca == 99) {

        elemento_t * a1 = matriz_obter_elemento(m, 0, 7);
        elemento_t * b1 = matriz_obter_elemento(m, 1, 7);
        elemento_t * c1 = matriz_obter_elemento(m, 2, 7);
        elemento_t * d1 = matriz_obter_elemento(m, 3, 7);
        elemento_t * e1 = matriz_obter_elemento(m, 4, 7);

        //verifica se o rei a torre estao na posicao correta e se o espaco eles entre ta vazio
        if(e1->macro_peca == REI_BRANCO && a1->macro_peca == TORRE_BRANCA) {
            if(b1->macro_peca == b1->cor && c1->macro_peca == c1->cor && d1->macro_peca == d1->cor) {
                c1->macro_peca = REI_BRANCO;
                c1->peca = 'B';
                d1->macro_peca = TORRE_BRANCA;
                d1->peca = 'B';
                e1->macro_peca = e1->cor;
                e1->peca = ' ';
                a1->macro_peca = a1->cor;
                a1->peca = ' ';
                //e o b1 continua vazio

                return m;
            }
        }
        printf("Roque invalido.\n");
        exit(1);

    //se for jogada da peca PRETA
    } else {

        elemento_t * a8 = matriz_obter_elemento(m, 0, 0);
        elemento_t * b8 = matriz_obter_elemento(m, 1, 0);
        elemento_t * c8 = matriz_obter_elemento(m, 2, 0);
        elemento_t * d8 = matriz_obter_elemento(m, 3, 0);
        elemento_t * e8 = matriz_obter_elemento(m, 4, 0);

        //verifica se o rei a torre estao na posicao correta e se o espaco eles entre ta vazio
        if(e8->macro_peca == REI_PRETO && a8->macro_peca == TORRE_PRETA) {
            if(b8->macro_peca == b8->cor && c8->macro_peca == c8->cor && d8->macro_peca == d8->cor) {
                c8->macro_peca = REI_PRETO;
                c8->peca = 'P';
                d8->macro_peca = TORRE_PRETA;
                d8->peca = 'P';
                e8->macro_peca = e8->cor;
                e8->peca = ' ';
                a8->macro_peca = a8->cor;
                a8->peca = ' ';

                return m;
            }
        }
        printf("Roque invalido.\n");
        exit(1);
    }
} 

