#pragma once

#define chess_popcount __builtin_popcountll
#define chess_lsb      __builtin_ctzll
#define chess_msb(x)   (63 ^ __builtin_clzll(x))

