
#include "payment.h"



double calculatePrice(char row,
                      int isStudent,
                      int isSenior,
                      int numSeats)
{
    double basePrice = 0.0;

    if(row == 'A' || row == 'B')
    {
        basePrice = 500.0;
    }
    else if(row == 'C' || row == 'D')
    {
        basePrice = 750.0;
    }
    else if(row == 'E')
    {
        basePrice = 1000.0;
    }

    double price = basePrice;



    if(isSenior)
    {
        price = price * 0.80;
    }
    else if(isStudent)
    {
        price = price * 0.90;
    }



    if(numSeats >= 4)
    {
        price = price * 0.90;
    }

    return price;
}



void revenueReport()
{
    printf("\n-------------------------------------------------------------\n");
    printf("%-25s %-10s %-10s %-10s\n",
           "Movie",
           "Time",
           "Tickets",
           "Revenue");
    printf("-------------------------------------------------------------\n");

    for(int i = 0; i < NUM_SHOWTIMES; i++)
    {
        Showtime *s = &showtimes[i];

        int ticketsSold = 0;
        double revenue = 0.0;

        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                if(s->seats[r][c].isBooked)
                {
                    ticketsSold++;
                    revenue += s->seats[r][c].pricePaid;
                }
            }
        }

        printf("%-25s %-10s %-10d Rs. %.2f\n",
               s->movieName,
               s->showTime,
               ticketsSold,
               revenue);
    }

    printf("-------------------------------------------------------------\n");
}
