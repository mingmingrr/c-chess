#pragma once

#include <chess/types/piece.h>
#include <chess/types/value.h>
#include <chess/types/castle.h>
#include <chess/types/square.h>
#include <chess/types/board.h>
#include <chess/types/move.h>

typedef struct chess_State {
	chess_Move   move;
	chess_Castle castle;
	chess_Square enPassant;
	chess_Piece  capture;
	chess_ValueL value;
} chess_State;

