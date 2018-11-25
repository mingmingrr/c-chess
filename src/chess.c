#include "chess.h"

#include <stdio.h>
#include <stdlib.h>

#include "word.h"
#include "types.h"
#include "move.h"

void chess_run() {
	chess_Board board;
	chess_State state;
	chess_Board_init(&board);
	while(true) {
		chess_Board_print(&board);
		chess_move(&board, chess_Move_scan(), &state);
	}
}

