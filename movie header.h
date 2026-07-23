#ifndef MOVIE_H
#define MOVIE_H

#include "data.h"

/* Movie Functions */

void initializeSystem();

void viewShowtimes();

void viewSeatMap();

char rowLetter(int r);

char tierLabel(int r);

int getValidShowtimeId();

#endif
