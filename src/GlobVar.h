#ifndef GLOBVAR_H
#define GLOBVAR_H


#include <iostream>
#include <conio.h>
#include <time.h>
#include <array>
#include <chrono>
#include <vector>
#include "Windows.h"

extern std::chrono::system_clock::time_point start,end;

extern int score;

extern const int mapHeight;
extern const int mapWidth;

extern const int tanksCount;
extern const int wallCount;

extern int totalTime;

extern int x;
extern int y;

extern std::array<std::array<char, 50>, 50> map;


enum Direction { UP, DOWN, LEFT, RIGHT };

#endif // !GLOBVAR_H
