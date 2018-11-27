#pragma once

#include <data/word.h>

typedef union chess_Square {
	Uint8 all;
	struct {
		Uint8 file : 3;
		Uint8 rank : 3;
		Uint8 _pad : 2;
	};
} chess_Square;

#define Sq(x) chess_Square_##x

enum {
Sq(A1), Sq(B1), Sq(C1), Sq(D1), Sq(E1), Sq(F1), Sq(G1), Sq(H1),
Sq(A2), Sq(B2), Sq(C2), Sq(D2), Sq(E2), Sq(F2), Sq(G2), Sq(H2),
Sq(A3), Sq(B3), Sq(C3), Sq(D3), Sq(E3), Sq(F3), Sq(G3), Sq(H3),
Sq(A4), Sq(B4), Sq(C4), Sq(D4), Sq(E4), Sq(F4), Sq(G4), Sq(H4),
Sq(A5), Sq(B5), Sq(C5), Sq(D5), Sq(E5), Sq(F5), Sq(G5), Sq(H5),
Sq(A6), Sq(B6), Sq(C6), Sq(D6), Sq(E6), Sq(F6), Sq(G6), Sq(H6),
Sq(A7), Sq(B7), Sq(C7), Sq(D7), Sq(E7), Sq(F7), Sq(G7), Sq(H7),
Sq(A8), Sq(B8), Sq(C8), Sq(D8), Sq(E8), Sq(F8), Sq(G8), Sq(H8),
};

#undef Sq

#define chess_Square_make(rank, file) (((rank) << 3) | (file))

#define chess_Square_flip(square, color) \
	(((color) == chess_Color_White) ? \
		(square) : \
		((square) ^ (0b111 << 3)) \
	)
