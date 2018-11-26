#include <chess/types/board.h>

#include <chess/types.h>

const chess_Piece chess_Board_starting[] = {
	4, 2, 3, 5, 6, 3, 2, 4,
	1, 1, 1, 1, 1, 1, 1, 1,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	-1,-1,-1,-1,-1,-1,-1,-1,
	-4,-2,-3,-5,-6,-3,-2,-4,
};

void chess_Board_init(chess_Board* board) {
	board->color = chess_Color_White;
	board->castle.all = chess_Castle_All;
	board->enPassant.all = 0;
	board->value = 0;
	for(Uint8 i = 0; i < 64; ++i)
		board->board[i] = chess_Board_starting[i];
}

void chess_Board_print(chess_Board* board) {
	chess_Square square = (chess_Square) {.all = 0};
	printf("+---+---+---+---+---+---+---+---+\n");
	for(Uint8 rank = 8; rank; --rank) {
		square.rank = rank - 1;
		for(Uint8 file = 0; file != 8; ++file) {
			square.file = file;
			chess_Piece piece = board->board[square.all];
			printf("| "); chess_Piece_print(piece); putchar(' ');
		}
		printf("| %d\n+---+---+---+---+---+---+---+---+\n", rank);
	}
	for(char file = 'A'; file <= 'H'; ++file)
		printf("  %c ", file);
	putchar('\n');
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

