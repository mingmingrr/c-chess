#include <chess/valid.h>

#include <word.h>

#include <chess/types.h>
#include <chess/util/math.h>

Bool chess_valid_pawn(chess_Board* board, chess_Move move) {
	chess_Square src; src.all = move.src;
	chess_Square dst; dst.all = move.dst;
	Uint8 rank = (Int8)(dst.rank - src.rank) * board->color;
	Uint8 file = chess_abs(dst.file - src.file);
	if(rank != 1) return (rank == 2) &&
		(board->board[chess_Square_make((src.rank + board->color), src.file)]
			== chess_Piece_Empty) &&
		(src.rank == (board->color == chess_Color_White ? 1 : 6));
	if(file > 1) return false;
	return (file == 0) ^ (board->board[dst.all] != chess_Piece_Empty);
}

Bool chess_valid_knight(chess_Board* board, chess_Move move) {
	chess_Square src; src.all = move.src;
	chess_Square dst; dst.all = move.dst;
	Uint8 file = chess_abs(dst.file - src.file);
	Uint8 rank = chess_abs(dst.rank - src.rank);
	return (file + rank == 3) && file && rank;
}

Bool chess_valid_bishop(chess_Board* board, chess_Move move) {
	chess_Square src; src.all = move.src;
	chess_Square dst; dst.all = move.dst;
	Uint8 file = chess_abs(dst.file - src.file);
	Uint8 rank = chess_abs(dst.rank - src.rank);
	Uint8 fileSgn = chess_sgn(dst.file - src.file);
	Uint8 rankSgn = chess_sgn(dst.rank - src.rank);
	if(file != rank) return false;
	src.file += fileSgn, src.rank += rankSgn;
	for(; src.all != dst.all; src.file += fileSgn, src.rank += rankSgn)
		if(board->board[src.all] != chess_Piece_Empty) return false;
	return true;
}

Bool chess_valid_rook(chess_Board* board, chess_Move move) {
	chess_Square src; src.all = move.src;
	chess_Square dst; dst.all = move.dst;
	Uint8 file = chess_abs(dst.file - src.file);
	Uint8 rank = chess_abs(dst.rank - src.rank);
	Uint8 fileSgn = chess_sgn(dst.file - src.file);
	Uint8 rankSgn = chess_sgn(dst.rank - src.rank);
	if((file != 0) == (rank != 0)) return false;
	src.file += fileSgn, src.rank += rankSgn;
	for(; src.all != dst.all; src.file += fileSgn, src.rank += rankSgn)
		if(board->board[src.all] != chess_Piece_Empty) return false;
	return true;
}

Bool chess_valid_queen(chess_Board* board, chess_Move move) {
	return chess_valid_bishop(board, move) ||
		chess_valid_rook(board, move);
}

Bool chess_valid_king(chess_Board* board, chess_Move move) {
	chess_Square src; src.all = move.src;
	chess_Square dst; dst.all = move.dst;
	Uint8 file = chess_abs(dst.file - src.file);
	Uint8 rank = chess_abs(dst.rank - src.rank);
	return file <= 1 && rank <= 1;
}

Bool chess_valid_normal(chess_Board* board, chess_Move move) {
	static Bool (*const funcs[6])(chess_Board*, chess_Move) = {
		&chess_valid_pawn,
		&chess_valid_knight,
		&chess_valid_bishop,
		&chess_valid_rook,
		&chess_valid_queen,
		&chess_valid_king,
	};
	return funcs[chess_abs(board->board[move.src]) - 1](board, move);
}

Bool chess_validate(chess_Board* board, chess_Move move) {
	chess_Color srcColor = chess_sgn(board->board[move.src]);
	chess_Color dstColor = chess_sgn(board->board[move.dst]);
	if(srcColor != board->color) return false;
	if(srcColor == dstColor) return false;
	if(move.src == move.dst) return false;
	switch(move.type) {
		case chess_MoveType_Normal:
			return chess_valid_normal(board, move);
		case chess_MoveType_Promotion:
			return chess_valid_pawn(board, move);
		case chess_MoveType_Castling: break;
		case chess_MoveType_EnPassant: break;
	}
	return true;
}


