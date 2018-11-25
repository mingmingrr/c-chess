#include "types.h"

#include <stdlib.h>
#include <stdio.h>

#include "word.h"

char chess_Piece_chars[] = "-PNBRQK";

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

void chess_Board_print(chess_Board* board) {
	chess_Posn posn = (chess_Posn) {.all = 0};
	for(Uint8 rank = 8; rank; --rank) {
		posn.rank = rank - 1;
		for(Uint8 file = 0; file != 8; ++file) {
			posn.file = file;
			chess_Piece piece = board->board[posn.all];
			char chr = chess_Piece_chars[chess_abs(piece)];
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

chess_Move chess_Move_scan() {
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
