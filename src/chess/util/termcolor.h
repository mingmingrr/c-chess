#pragma once

#ifdef TermColor

#define chess_TermColor_Bold   "\x1B[1m"
#define chess_TermColor_Dim    "\x1B[2m"
#define chess_TermColor_Red    "\x1B[91m"
#define chess_TermColor_Blue   "\x1B[94m"
#define chess_TermColor_Reset  "\033[0m"

#else

#define chess_TermColor_Bold   ""
#define chess_TermColor_Dim    ""
#define chess_TermColor_Red    ""
#define chess_TermColor_Blue   ""
#define chess_TermColor_Reset  ""

#endif

