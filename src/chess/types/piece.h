#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

#include <data/word.h>

typedef enum chess_PieceT {
	chess_Piece_Empty  = 0,
	chess_Piece_Pawn   = 1,
	chess_Piece_Knight = 2,
	chess_Piece_Bishop = 3,
	chess_Piece_Rook   = 4,
	chess_Piece_Queen  = 5,
	chess_Piece_King   = 6,
} chess_PieceT;

typedef Int8 chess_Piece;

extern char chess_pieceChars[7];

void chess_Piece_print(chess_Piece);

