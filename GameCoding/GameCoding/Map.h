#pragma once

const int MAP_WIDTH = 5;
const int MAP_HEIGHT = 5;
const int MAP_SIZE = MAP_WIDTH * MAP_HEIGHT;

void PrintMap1D();
void PrintMap2D();

extern int GMap1D[MAP_SIZE];
extern int GMap2D[MAP_HEIGHT][MAP_WIDTH];