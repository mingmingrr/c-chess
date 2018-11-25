#include "chess.h"

#define chess_abs(x) (x >= 0 ? x : -x)
#define chess_sgn(x) ((0 < x) - (x < 0))

#include <stdio.h>
#include <stdlib.h>

#include "word.h"

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

typedef enum chess_PromotionT {
	chess_Promotion_Knight = chess_Piece_Knight - chess_Piece_Knight,
	chess_Promotion_Bishop = chess_Piece_Bishop - chess_Piece_Knight,
	chess_Promotion_Rook   = chess_Piece_Rook   - chess_Piece_Knight,
	chess_Promotion_Queen  = chess_Piece_Queen  - chess_Piece_Knight,
} chess_PromotionT;

typedef Int8 chess_ValueS;

chess_ValueS chess_position_value[6][64] = {
	{
		0   , 0   , 0   , 0  , 0  , 0   , 0   , 0   ,
		-11 , 7   , 7   , 17 , 17 , 7   , 7   , -11 ,
		-16 , -3  , 23  , 23 , 23 , 23  , -3  , -16 ,
		-14 , -7  , 20  , 24 , 24 , 20  , -7  , -14 ,
		-5  , -2  , -1  , 12 , 12 , -1  , -2  , -5  ,
		-11 , -12 , -2  , 4  , 4  , -2  , -12 , -11 ,
		-2  , 20  , -10 , -2 , -2 , -10 , 20  , -2
	}, {
		-127 , -96 , -80 , -79 , -79 , -80 , -96 , -127 ,
		-79  , -39 , -24 , -9  , -9  , -24 , -39 , -79  ,
		-64  , -20 , 4   , 19  , 19  , 4   , -20 , -64  ,
		-28  , 5   , 41  , 47  , 47  , 41  , 5   , -28  ,
		-29  , 13  , 42  , 52  , 52  , 42  , 13  , -29  ,
		-11  , 28  , 63  , 55  , 55  , 63  , 28  , -11  ,
		-67  , -21 , 6   , 37  , 37  , 6   , -21 , -67  ,
		-127 , -80 , -53 , -32 , -32 , -53 , -80 , -127
	}, {
		-49 , -7  , -10 , -34 , -34 , -10 , -7  , -49 ,
		-24 , 9   , 15  , 1   , 1   , 15  , 9   , -24 ,
		-9  , 22  , -3  , 12  , 12  , -3  , 22  , -9  ,
		4   , 9   , 18  , 40  , 40  , 18  , 9   , 4   ,
		-8  , 27  , 13  , 30  , 30  , 13  , 27  , -8  ,
		-17 , 14  , -6  , 6   , 6   , -6  , 14  , -17 ,
		-19 , -13 , 7   , -11 , -11 , 7   , -13 , -19 ,
		-47 , -7  , -17 , -29 , -29 , -17 , -7  , -47
	}, {
		-24 , -15 , -8  , 0  , 0  , -8  , -15 , -24 ,
		-18 , -5  , -1  , 1  , 1  , -1  , -5  , -18 ,
		-19 , -10 , 1   , 0  , 0  , 1   , -10 , -19 ,
		-21 , -7  , -4  , -4 , -4 , -4  , -7  , -21 ,
		-21 , -12 , -1  , 4  , 4  , -1  , -12 , -21 ,
		-23 , -10 , 1   , 6  , 6  , 1   , -10 , -23 ,
		-11 , 8   , 9   , 12 , 12 , 9   , 8   , -11 ,
		-25 , -18 , -11 , 2  , 2  , -11 , -18 , -25
	}, {
		3  , -5 , -5 , 4  , 4  , -5 , -5 , 3  ,
		-3 , 5  , 8  , 12 , 12 , 8  , 5  , -3 ,
		-3 , 6  , 13 , 7  , 7  , 13 , 6  , -3 ,
		4  , 5  , 9  , 8  , 8  , 9  , 5  , 4  ,
		0  , 14 , 12 , 5  , 5  , 12 , 14 , 0  ,
		-4 , 10 , 6  , 8  , 8  , 6  , 10 , -4 ,
		-5 , 6  , 10 , 8  , 8  , 10 , 6  , -5 ,
		-2 , -2 , 1  , -2 , -2 , 1  , -2 , -2
	}, {
		91 , 109 , 91 , 64 , 64 , 91 , 109 , 91 ,
		93 , 102 , 81 , 61 , 61 , 81 , 102 , 93 ,
		66 , 85  , 56 , 40 , 40 , 56 , 85  , 66 ,
		57 , 64  , 46 , 36 , 36 , 46 , 64  , 57 ,
		49 , 59  , 38 , 23 , 23 , 38 , 59  , 49 ,
		41 , 53  , 29 , 12 , 12 , 29 , 53  , 41 ,
		29 , 40  , 22 , 9  , 9  , 22 , 40  , 29 ,
		22 , 29  , 17 , 0  , 0  , 17 , 29  , 22
	}
};

typedef Int16 chess_Value;

chess_Value chess_piece_value[] = {
	0,
	100,
	320,
	330,
	510,
	880,
	0x3fff
};

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

typedef union chess_Move {
	Uint16 all;
	struct {
		Uint16 src : 6;
		Uint16 dst : 6;
		Uint16 type : 2;
		Uint16 promotion : 2;
	};
} chess_Move;

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

char chess_pieceChars[] = "-PNBRQK";

void chess_print(chess_Board* board) {
	chess_Posn posn = (chess_Posn) {.all = 0};
	for(Uint8 rank = 8; rank; --rank) {
		posn.rank = rank - 1;
		for(Uint8 file = 0; file != 8; ++file) {
			posn.file = file;
			chess_Piece piece = board->board[posn.all];
			char chr = chess_pieceChars[chess_abs(piece)];
			if(chess_sgn(piece) == chess_Color_Black) chr += 32;
			/* printf("%c%c ", 'a' + file, '0' + rank); */
			printf("%c ", chr);
		}
		printf("\n");
	}
	switch(board->color) {
		case chess_Color_Black:
			printf("Black to move  ");
			break;
		case chess_Color_White:
			printf("White to move  ");
			break;
	}
	if(board->castle.whiteShort) printf("K");
	if(board->castle.whiteLong)  printf("Q");
	if(board->castle.blackShort) printf("k");
	if(board->castle.blackLong)  printf("q");
	printf("\n");
}

chess_Move chess_scan() {
	chess_Move move = (chess_Move) {.all = 0};
	chess_Posn posn = (chess_Posn) {.all = 0};
	char buffer[8];
	printf("Enter a move (Smith) > ");
	if(!fgets(buffer, sizeof(buffer), stdin))
		exit(0);
	posn.file = buffer[0] - 'a';
	posn.rank = buffer[1] - '1';
	move.src = posn.all;
	posn.file = buffer[2] - 'a';
	posn.rank = buffer[3] - '1';
	move.dst = posn.all;
	switch(buffer[4]) {
		case '\n' : case '\0' : move.type = chess_MoveType_Normal; break;
		case 'e' : case 'E' : move.type = chess_MoveType_EnPassant; break;
		case 'c' : case 'C' : move.type = chess_MoveType_Castling; break;
		default:
			move.type = chess_MoveType_Promotion;
			switch(buffer[4]) {
				case 'q' : case 'Q' : move.promotion = chess_Promotion_Queen; break;
				case 'n' : case 'N' : move.promotion = chess_Promotion_Knight; break;
				case 'r' : case 'R' : move.promotion = chess_Promotion_Rook; break;
				case 'b' : case 'B' : move.promotion = chess_Promotion_Bishop; break;
			}
	}
	return move;
}

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
	printf("target : %d\n", chess_Posn_make(dst.rank, 5));
	printf("source : %d\n", chess_Posn_make(dst.rank, 7));
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

void chess_Board_init(chess_Board* board) {
	static const chess_Piece backRank[] = {4, 2, 3, 5, 6, 3, 2, 4};
	board->color = chess_Color_White;
	board->castle.all = chess_Castle_All;
	chess_Posn posn = (chess_Posn) {.all = 0};
	chess_Color color = chess_Color_White;
	for(Uint8 rank = 0; rank < 8; rank += 7, color *= -1) {
		posn.rank = rank;
		for(Uint8 file = 0; file < 8; ++file) {
			posn.file = file;
			board->board[posn.all] = color * backRank[file];
		}
	}
	for(Uint8 rank = 1; rank < 8; rank += 5, color *= -1) {
		posn.rank = rank;
		for(Uint8 file = 0; file < 8; ++file) {
			posn.file = file;
			board->board[posn.all] = color * chess_Piece_Pawn;
		}
	}
	for(Uint8 rank = 2; rank < 6; ++rank) {
		posn.rank = rank;
		for(Uint8 file = 0; file < 8; ++file) {
			posn.file = file;
			board->board[posn.all] = chess_Piece_Empty;
		}
	}
}

void chess_run() {
	chess_Board board;
	chess_State state;
	chess_Board_init(&board);
	while(true) {
		chess_print(&board);
		chess_move(&board, chess_scan(), &state);
	}
}

