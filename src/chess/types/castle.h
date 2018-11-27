#pragma once

#include <data/word.h>

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

