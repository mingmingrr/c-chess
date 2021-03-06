#include <chess/value.h>

#include <chess/types.h>

chess_ValueS chess_Square_value[6][64] = {
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

chess_ValueL chess_Piece_value[] = {
	100,
	320,
	330,
	510,
	880,
	0x3fff
};

