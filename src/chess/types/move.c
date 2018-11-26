#include <chess/types/move.h>

#include <chess/types.h>
#include <chess/util.h>

chess_Move chess_Move_scan() {
	chess_Move move = (chess_Move) {.all = 0};
	chess_Square square = (chess_Square) {.all = 0};
	char buffer[8];
	if(!fgets(buffer, sizeof(buffer), stdin) || buffer[0] == '-')
		exit(0);
	square.file = buffer[0] - 'a';
	square.rank = buffer[1] - '1';
	move.src = square.all;
	square.file = buffer[2] - 'a';
	square.rank = buffer[3] - '1';
	move.dst = square.all;
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
	printf("Move: %s\n", buffer);
	return move;
}

