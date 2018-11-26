#include <chess/types/piece.h>

#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

#include <word.h>

#include <chess/util.h>
#include <chess/types/color.h>

char chess_Piece_chars[] = " PNBRQK";

#define Co(x) chess_TermColor_##x

void chess_Piece_print(chess_Piece piece) {
	char chr = chess_Piece_chars[chess_abs(piece)];
	switch(chess_sgn(piece)) {
		case chess_Color_White:
			printf(Co(Bold) Co(Blue) "%c" Co(Reset), chr);
			break;
		case chess_Color_Black:
			printf(Co(Bold) Co(Red) "%c" Co(Reset), chr + 32);
			break;
		default:
			putchar(' ');
	}
}

#undef Co

