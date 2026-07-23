
#include "movie.h"

/* Global Data */

Showtime showtimes[NUM_SHOWTIMES];

/* Initialize Movies and Seats */

void initializeSystem()
{
    const char *movieNames[NUM_MOVIES] =
    {
        "The Great Adventure",
        "Mystery Manor",
        "Space Odyssey X"
    };

    const char *times[NUM_SHOWTIMES_PER_MOVIE] =
    {
        "10:00 AM",
        "6:30 PM"
    };

    int idx = 0;

    for (int m = 0; m < NUM_MOVIES; m++)
    {
        for (int t = 0; t < NUM_SHOWTIMES_PER_MOVIE; t++)
        {
            strcpy(showtimes[idx].movieName, movieNames[m]);
            strcpy(showtimes[idx].showTime, times[t]);

            for (int r = 0; r < ROWS; r++)
            {
                for (int c = 0; c < COLS; c++)
                {
                    showtimes[idx].seats[r][c].isBooked = 0;
                    showtimes[idx].seats[r][c].pricePaid = 0.0;
                    showtimes[idx].seats[r][c].isStudent = 0;
                    showtimes[idx].seats[r][c].isSenior = 0;

                    strcpy(showtimes[idx].seats[r][c].customerName, "");
                }
            }

            idx++;
        }
    }
}

/* Display All Showtimes */

void viewShowtimes()
{
    printf("\n%-4s %-25s %-10s\n", "ID", "Movie", "Time");

    for (int i = 0; i < NUM_SHOWTIMES; i++)
    {
        printf("%-4d %-25s %-10s\n",
               i,
               showtimes[i].movieName,
               showtimes[i].showTime);
    }
}

/* Convert Row Number to Letter */

char rowLetter(int r)
{
    return (char)('A' + r);
}

/* Display Seat Tier */

char tierLabel(int r)
{
    if (r == 0 || r == 1)
        return 'R';

    if (r == 2 || r == 3)
        return 'P';

    return 'V';
}

/* Validate Showtime */

int getValidShowtimeId()
{
    int id;

    viewShowtimes();

    printf("Enter showtime ID: ");

    if (scanf("%d", &id) != 1)
    {
        while (getchar() != '\n');

        return -1;
    }

    if (id < 0 || id >= NUM_SHOWTIMES)
    {
        printf("Invalid showtime ID.\n");

        return -1;
    }

    return id;
}

/* Display Seat Map */

void viewSeatMap()
{
    int id = getValidShowtimeId();

    if (id == -1)
        return;

    Showtime *s = &showtimes[id];

    printf("\nSeat Map for %s (%s)\n",
           s->movieName,
           s->showTime);

    printf("Legend: . = Free   X = Booked\n");
    printf("R = Regular  P = Premium  V = VIP\n\n");

    printf("     ");

    for (int c = 0; c < COLS; c++)
        printf("%2d ", c + 1);

    printf("\n");

    for (int r = 0; r < ROWS; r++)
    {
        printf("Row %c(%c) ",
               rowLetter(r),
               tierLabel(r));

        for (int c = 0; c < COLS; c++)
        {
            if (s->seats[r][c].isBooked)
                printf(" X ");
            else
                printf(" . ");
        }

        printf("\n");
    }
}
