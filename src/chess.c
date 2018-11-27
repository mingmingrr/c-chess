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
	printf(
		"Moves are in Smith notation (e2e4 e7e5 g1f3 b8c6 f1b5)\n"
		"Suffix with 'c' if castling (e1g1c)\n"
		"Suffix with 'e' if capturing en passant (e5f6e)\n"
		"Suffix with 'q' 'n' 'r' or 'b' if promoting (e7e8n)\n"
		"| P : Pawn | N : Knight | B : Bishop |\n"
		"| R : Rook | Q : Queen  | K : King   |\n"
		"Uppercase for white pieces, lowercase for black\n\n"
	);
	while(true) {
		printf("Ply: %d\n", ply++);
		chess_Board_print(&board);
		chess_Move move;
		printf("Move > ");
		while(true) {
			move = chess_Move_scan();
			if(chess_valid_move(&board, move)) break;
			printf("Retry > ");
		}
		chess_move_do(&board, move, &state);
	}
}

