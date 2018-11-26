#pragma once

#include <word.h>

typedef Uint64 chess_BitBoard;

enum {
	chess_BitBoard_File  = 0x00000000000000ff,
	chess_BitBoard_Rank  = 0x0101010101010101,
	chess_BitBoard_Diag1 = 0x8040201008040201,
	chess_BitBoard_Diag2 = 0x0102040810204080,
};

#define chess_BitBoard_FileN(n) (chess_BitBoard_File << n)
#define chess_BitBoard_RankN(n) (chess_BitBoard_Rank << (4 * n))
