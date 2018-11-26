#pragma once

#include <word.h>

typedef union chess_Move {
	Uint16 all;
	struct {
		Uint16 src : 6;
		Uint16 dst : 6;
		Uint16 type : 2;
		Uint16 promotion : 2;
	};
} chess_Move;

chess_Move chess_Move_scan();

typedef enum chess_MoveTypeT {
	chess_MoveType_Normal    = 0,
	chess_MoveType_Promotion = 1,
	chess_MoveType_EnPassant = 2,
	chess_MoveType_Castling  = 3
} chess_MoveTypeT;

