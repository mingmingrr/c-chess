#pragma once

#include <word.h>

#include <chess/types/piece.h>

typedef enum chess_PromotionT {
	chess_Promotion_Knight = chess_Piece_Knight - chess_Piece_Knight,
	chess_Promotion_Bishop = chess_Piece_Bishop - chess_Piece_Knight,
	chess_Promotion_Rook   = chess_Piece_Rook   - chess_Piece_Knight,
	chess_Promotion_Queen  = chess_Piece_Queen  - chess_Piece_Knight,
} chess_PromotionT;

