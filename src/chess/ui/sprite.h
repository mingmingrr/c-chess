#pragma once

#include <data/word.h>

typedef struct chess_Sprite_Row {
	Uint32 color;
	Uint32 alpha;
} chess_Sprite_Row;

typedef chess_Sprite_Row chess_Sprite[30];

typedef chess_Sprite_Row* chess_SpriteP;

typedef enum chess_Sprite_AlphaT {
	chess_Sprite_Alpha_Opaque = 1,
	chess_Sprite_Alpha_Transparent = 0,
} chess_Sprite_AlphaT;

typedef enum chess_Sprite_ColorT {
	chess_Sprite_Color_Black = 0,
	chess_Sprite_Color_White = 1,
} chess_Sprite_ColorT;

extern const chess_Sprite chess_sprites[13];

