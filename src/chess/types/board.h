#pragma once

#include <chess/types/piece.h>
#include <chess/types/color.h>
#include <chess/types/value.h>
#include <chess/types/castle.h>
#include <chess/types/square.h>

extern const chess_Piece chess_Board_starting[64];

typedef struct chess_Board {
	chess_Piece  board[64];
	chess_Color  color;
	chess_Castle castle;
	chess_ValueL value;
	chess_Square enPassant;
} chess_Board;

void chess_Board_init(chess_Board*);

void chess_Board_print(chess_Board*);

