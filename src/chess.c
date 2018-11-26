#include <chess.h>

#include <stdio.h>
#include <stdlib.h>

#include <word.h>
#include <chess/types.h>
#include <chess/move.h>
#include <chess/valid.h>

void chess_run() {
	chess_Board board;
	chess_State state;
	chess_Board_init(&board);
	int ply = 0;
	while(true) {
		printf("Ply: %d\n", ply++);
		chess_Board_print(&board);
		chess_Move move;
		while(true) {
			move = chess_Move_scan();
			if(chess_validate(&board, move)) break;
		}
		chess_move_do(&board, move, &state);
	}
}

