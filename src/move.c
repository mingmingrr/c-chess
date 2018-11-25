#include "move.h"

#include "types.h"

void chess_move_normal(chess_Board* board, chess_Move move) {
	chess_Posn src; src.all = move.src;
	chess_Posn dst; dst.all = move.dst;
	switch(chess_abs(board->board[dst.all])) {
		case chess_Piece_Pawn:
			if((dst.rank - src.rank) * board->color == 2)
				board->enPassant.all = dst.all;
			break;
		case chess_Piece_Rook:
			switch(src.all) {
				case chess_Posn_make(0, 0): board->castle.whiteLong  = 0; break;
				case chess_Posn_make(0, 7): board->castle.whiteShort = 0; break;
				case chess_Posn_make(7, 0): board->castle.blackLong  = 0; break;
				case chess_Posn_make(7, 7): board->castle.blackShort = 0; break;
			}
			break;
		case chess_Piece_King:
			if(board->color == chess_Color_White)
				board->castle.whiteAll = 0;
			else
				board->castle.blackAll = 0;
			break;
	}
}

void chess_move_castle(chess_Board* board, chess_Move move) {
	chess_Posn dst; dst.all = move.dst;
	if(dst.file == 6) { // castle short
		board->board[chess_Posn_make(dst.rank, 5)] = chess_Piece_Rook;
		board->board[chess_Posn_make(dst.rank, 7)] = chess_Piece_Empty;
	} else { // castle long
		board->board[chess_Posn_make(dst.rank, 3)] = chess_Promotion_Rook;
		board->board[chess_Posn_make(dst.rank, 0)] = chess_Piece_Empty;
	}
	if(board->color == chess_Color_White)
		board->castle.whiteAll = 0;
	else
		board->castle.blackAll = 0;
}

void chess_move(chess_Board* board, chess_Move move, chess_State* state) {
	state->castle = board->castle;
	state->enPassant = board->enPassant;
	state->move.all = move.all;
	state->capture = board->board[move.dst];
	chess_Posn src; src.all = move.src;
	chess_Posn dst; dst.all = move.dst;
	board->board[dst.all] = board->board[src.all];
	board->board[src.all] = chess_Piece_Empty;
	board->enPassant.all = 0;
	switch(move.type) {
		case chess_MoveType_Normal:
			chess_move_normal(board, move);
			break;
		case chess_MoveType_Promotion:
			board->board[move.dst] = chess_Piece_Queen;
			break;
		case chess_MoveType_Castling:
			chess_move_castle(board, move);
			break;
		case chess_MoveType_EnPassant:
			state->capture = chess_Piece_Pawn;
			board->board[move.dst - board->color * 8] = chess_Piece_Empty;
			break;
	}
	board->color = -board->color;
}

