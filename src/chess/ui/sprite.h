#pragma once

#include <word.h>

typedef Uint8 chess_Sprite[20][5];

typedef enum chess_Sprite_AlphaT {
	chess_Sprite_Alpha_Opaque = 1,
	chess_Sprite_Alpha_Transparent = 0,
} chess_Sprite_AlphaT;

typedef enum chess_Sprite_ColorT {
	chess_Sprite_Color_Black = 0,
	chess_Sprite_Color_White = 1,
} chess_Sprite_ColorT;

typedef union chess_Sprite_Color {
	struct {
		Uint8 all : 2;
		Uint8 _pad1 : 6;
	};
	struct {
		Uint8 alpha : 1;
		Uint8 color : 1;
		Uint8 _pad2 : 6;
	};
} chess_Sprite_Color;

extern const chess_Sprite chess_sprites[13];

