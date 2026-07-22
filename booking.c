#include "booking.h"
#include "payment.h"

void bookSeat()
{
    int id = getValidShowtimeId();

    if (id == -1)
        return;

    Showtime *s = &showtimes[id];

    int numSeats;

    printf("How many seats are you booking in this transaction (for group discount)? ");
    scanf("%d",&numSeats);

    if (numSeats < 1)
    {
        printf("Invalid number of seats.\n");
        return;
    }

    char name[50];

    printf("Enter customer name: ");
    scanf(" %49[^\n]", name);

    int isStudent = 0;
    int isSenior = 0;

    printf("Is the customer a student? (1 = Yes, 0 = No): ");

    if (scanf("%d", &isStudent) != 1)
    {
        while (getchar() != '\n');
        return;
    }

    if (!isStudent)
    {
        printf("Is the customer a senior citizen? (1 = Yes, 0 = No): ");

        if (scanf("%d", &isSenior) != 1)
        {
            while (getchar() != '\n');
            return;
        }
    }

    char rowCh;
    int seatNum;

    printf("Enter seat row (A-E): ");
    scanf(" %c", &rowCh);

    printf("Enter seat number (1-%d): ", COLS);

    if (scanf("%d", &seatNum) != 1)
    {
        printf("Invalid seat number.\n");

        while (getchar() != '\n');

        return;
    }

    int r = rowCh - 'A';
    int c = seatNum - 1;

    if (r < 0 || r >= ROWS || c < 0 || c >= COLS)
    {
        printf("Error: Seat out of range.\n");
        return;
    }

    if (s->seats[r][c].isBooked)
    {
        printf("Error: Seat %c%d is already booked.\n",
               rowLetter(r), seatNum);
        return;
    }

    double price = calculatePrice(rowLetter(r),
                                  isStudent,
                                  isSenior,
                                  numSeats);

    s->seats[r][c].isBooked = 1;
    s->seats[r][c].pricePaid = price;
    s->seats[r][c].isStudent = isStudent;
    s->seats[r][c].isSenior = isSenior;

    strcpy(s->seats[r][c].customerName, name);

    printf("\nBooking Successful!\n");

    printf("Movie : %s\n", s->movieName);
    printf("Time  : %s\n", s->showTime);
    printf("Seat  : %c%d\n", rowLetter(r), seatNum);
    printf("Name  : %s\n", name);
    printf("Price : Rs. %.2f\n", price);
}

void cancelBooking()
{
    int id = getValidShowtimeId();

    if (id == -1)
        return;

    Showtime *s = &showtimes[id];

    char rowCh;
    int seatNum;

    printf("Enter seat row (A-E): ");
    scanf(" %c", &rowCh);

    printf("Enter seat number (1-%d): ", COLS);

    if (scanf("%d", &seatNum) != 1)
    {
        printf("Invalid seat number.\n");

        while (getchar() != '\n');

        return;
    }

    int r = rowCh - 'A';
    int c = seatNum - 1;

    if (r < 0 || r >= ROWS || c < 0 || c >= COLS)
    {
        printf("Error: Seat out of range.\n");
        return;
    }

    if (!s->seats[r][c].isBooked)
    {
        printf("Error: Seat is not booked.\n");
        return;
    }

    s->seats[r][c].isBooked = 0;
    s->seats[r][c].pricePaid = 0.0;
    s->seats[r][c].isStudent = 0;
    s->seats[r][c].isSenior = 0;

    strcpy(s->seats[r][c].customerName, "");

    printf("Booking cancelled successfully.\n");
}

void searchBooking()
{
    int mode;

    printf("\nSearch By\n");
    printf("1. Customer Name\n");
    printf("2. Seat Number\n");
    printf("Enter choice: ");

    if (scanf("%d", &mode) != 1)
    {
        while (getchar() != '\n');
        return;
    }

    int found = 0;

    if (mode == 1)
    {
        char name[50];

        printf("Enter customer name: ");
        scanf(" %49[^\n]", name);

        for (int i = 0; i < NUM_SHOWTIMES; i++)
        {
            Showtime *s = &showtimes[i];

            for (int r = 0; r < ROWS; r++)
            {
                for (int c = 0; c < COLS; c++)
                {
                    Seat *seat = &s->seats[r][c];

                    if (seat->isBooked &&
                        strcmp(seat->customerName, name) == 0)
                    {
                        printf("\nCustomer : %s\n", seat->customerName);
                        printf("Movie    : %s\n", s->movieName);
                        printf("Showtime : %s\n", s->showTime);
                        printf("Seat     : %c%d\n",
                               rowLetter(r),
                               c + 1);
                        printf("Price    : Rs. %.2f\n",
                               seat->pricePaid);

                        found = 1;
                    }
                }
            }
        }
    }
    else if (mode == 2)
    {
        int id = getValidShowtimeId();

        if (id == -1)
            return;

        Showtime *s = &showtimes[id];

        char rowCh;
        int seatNum;

        printf("Enter seat row (A-E): ");
        scanf(" %c", &rowCh);

        printf("Enter seat number (1-%d): ", COLS);
        scanf("%d", &seatNum);

        int r = rowCh - 'A';
        int c = seatNum - 1;

        if (r < 0 || r >= ROWS || c < 0 || c >= COLS)
        {
            printf("Seat out of range.\n");
            return;
        }

        Seat *seat = &s->seats[r][c];

        if (seat->isBooked)
        {
            printf("\nCustomer : %s\n", seat->customerName);
            printf("Movie    : %s\n", s->movieName);
            printf("Showtime : %s\n", s->showTime);
            printf("Seat     : %c%d\n",
                   rowLetter(r),
                   seatNum);
            printf("Price    : Rs. %.2f\n",
                   seat->pricePaid);

            found = 1;
        }
    }
    else
    {
        printf("Invalid choice.\n");
        return;
    }

    if (!found)
    {
        printf("No booking found.\n");
    }
}
