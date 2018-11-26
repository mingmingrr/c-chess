#pragma once

#include <word.h>

typedef union chess_Square {
	Uint8 all;
	struct {
		Uint8 file : 3;
		Uint8 rank : 3;
		Uint8 _pad : 2;
	};
} chess_Square;

enum {
	chess_Square_A1, chess_Square_A2, chess_Square_A3, chess_Square_A4,
	chess_Square_A5, chess_Square_A6, chess_Square_A7, chess_Square_A8,
	chess_Square_B1, chess_Square_B2, chess_Square_B3, chess_Square_B4,
	chess_Square_B5, chess_Square_B6, chess_Square_B7, chess_Square_B8,
	chess_Square_C1, chess_Square_C2, chess_Square_C3, chess_Square_C4,
	chess_Square_C5, chess_Square_C6, chess_Square_C7, chess_Square_C8,
	chess_Square_D1, chess_Square_D2, chess_Square_D3, chess_Square_D4,
	chess_Square_D5, chess_Square_D6, chess_Square_D7, chess_Square_D8,
	chess_Square_E1, chess_Square_E2, chess_Square_E3, chess_Square_E4,
	chess_Square_E5, chess_Square_E6, chess_Square_E7, chess_Square_E8,
	chess_Square_F1, chess_Square_F2, chess_Square_F3, chess_Square_F4,
	chess_Square_F5, chess_Square_F6, chess_Square_F7, chess_Square_F8,
	chess_Square_G1, chess_Square_G2, chess_Square_G3, chess_Square_G4,
	chess_Square_G5, chess_Square_G6, chess_Square_G7, chess_Square_G8,
	chess_Square_H1, chess_Square_H2, chess_Square_H3, chess_Square_H4,
	chess_Square_H5, chess_Square_H6, chess_Square_H7, chess_Square_H8,
};

#define chess_Square_make(rank, file) ((rank << 3) | file)

