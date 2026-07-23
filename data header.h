#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <string.h>

#define ROWS 5
#define COLS 10

#define NUM_MOVIES 3
#define NUM_SHOWTIMES_PER_MOVIE 2
#define NUM_SHOWTIMES (NUM_MOVIES * NUM_SHOWTIMES_PER_MOVIE)

typedef struct
{
    char customerName[50];
    int isBooked;
    double pricePaid;
    int isStudent;
    int isSenior;
} Seat;

typedef struct
{
    char movieName[50];
    char showTime[20];
    Seat seats[ROWS][COLS];
} Showtime;

/* Global Variable */

extern Showtime showtimes[NUM_SHOWTIMES];

#endif
