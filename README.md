# Chess validator in pgn format

Programa escrito em C que recebe um arquivo .pgn na linha de comando. Esse arquivo deve conter todas as jogadas de uma partida de xadrez. O programa verifica se cada movimento realizado é válido ou não, atualizando o tabuleiro sempre que uma peça mover corretamente.

Para compilar, comando:
make

Para executar, comando:
./main nomedoarquivo.pgn

Em caso de mensagem "permissao negada", utilizo o comando: "chmod 777 main" e executo a main de novo.