#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "word.h"

#define chess_abs(x) (x >= 0 ? x : -x)
#define chess_sgn(x) ((0 < x) - (x < 0))

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

extern char chess_pieceChars[];

typedef enum chess_PromotionT {
	chess_Promotion_Knight = chess_Piece_Knight - chess_Piece_Knight,
	chess_Promotion_Bishop = chess_Piece_Bishop - chess_Piece_Knight,
	chess_Promotion_Rook   = chess_Piece_Rook   - chess_Piece_Knight,
	chess_Promotion_Queen  = chess_Piece_Queen  - chess_Piece_Knight,
} chess_PromotionT;

typedef Int8 chess_ValueS;

typedef Int16 chess_Value;

typedef enum chess_ColorT {
	chess_Color_White = 1,
	chess_Color_Empty = 0,
	chess_Color_Black = -1,
} chess_ColorT;

typedef Int8 chess_Color;

typedef enum chess_CastleT {
	chess_Castle_White_Short = 1 << 0,
	chess_Castle_White_Long  = 1 << 1,
	chess_Castle_White_All   = 3 << 0,
	chess_Castle_Black_Short = 1 << 2,
	chess_Castle_Black_Long  = 1 << 3,
	chess_Castle_Black_All   = 3 << 2,
	chess_Castle_Short_All   = 5 << 0,
	chess_Castle_Long_All    = 5 << 1,
	chess_Castle_All         = 0xf,
} chess_CastleT;

typedef union chess_Castle {
	Uint8 all;
	struct {
		Uint8 whiteShort : 1;
		Uint8 whiteLong  : 1;
		Uint8 blackShort : 1;
		Uint8 blackLong  : 1;
		Uint8 _pad1 : 4;
	};
	struct {
		Uint8 whiteAll : 2;
		Uint8 blackAll : 2;
		Uint8 _pad2 : 4;
	};
} chess_Castle;

typedef Uint64 chess_Bits;

enum {
	chess_Bits_File  = 0x00000000000000ff,
	chess_Bits_Rank  = 0x0101010101010101,
	chess_Bits_Diag1 = 0x8040201008040201,
	chess_Bits_Diag2 = 0x0102040810204080,
};

#define chess_Bits_FileN(n) (chess_Bits_File << n)
#define chess_Bits_RankN(n) (chess_Bits_Rank << (4 * n))

typedef union chess_Posn {
	Uint8 all;
	struct {
		Uint8 file : 3;
		Uint8 rank : 3;
		Uint8 _pad : 2;
	};
} chess_Posn;

#define chess_Posn_make(rank, file) ((rank << 3) | file)

typedef struct chess_Board {
	chess_Piece  board[64];
	chess_Color  color;
	chess_Castle castle;
	chess_Value  value;
	chess_Posn   enPassant;
} chess_Board;

void chess_Board_init(chess_Board* board);

void chess_Board_print(chess_Board* board);

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

typedef struct chess_State {
	chess_Move   move;
	chess_Castle castle;
	chess_Posn   enPassant;
	chess_Piece  capture;
} chess_State;
