#include <stdio.h>
#include "movie.h"
#include "booking.h"
#include "user.h"
#include "admin.h"

int main() {
    initializeSystem();
    int choice;
    int dicide1, dicide2;

    while (1) {
        displayMenu();

        do {
            if (scanf("%d", &choice) != 1) {
                while (getchar() != '\n');
                printf("Invalid input. Please enter a number between 1 and 8.\n");
                continue;
            }

            if (choice < 1 || choice > 8) {
                printf("Please enter a number between 1 and 8.\n");
            }

        } while (choice < 1 || choice > 8);

        switch (choice) {
            case 1:
                viewShowtimes();
                printf("Do you want to book a ticket? (1 = yes, 0 = no): ");
                do {
                    if (scanf("%d", &dicide1) != 1) {
                        while (getchar() != '\n');
                        printf("Invalid input. Enter 0 or 1: ");
                        dicide1 = -1; 
                    }
                } while (dicide1 < 0 || dicide1 > 1);

                if (dicide1 == 1) {
                    bookSeat();  
                }
                break;

            case 2:
                viewSeatMap();
                printf("Do you want to book a ticket? (1 = yes, 0 = no): ");
                do {
                    if (scanf("%d", &dicide2) != 1) {
                        while (getchar() != '\n');
                        printf("Invalid input. Enter 0 or 1: ");
                        dicide2 = -1;
                    }
                } while (dicide2 < 0 || dicide2 > 1);

                if (dicide2 == 1) {
                    bookSeat();
                }
                break;

            case 3: 
                bookSeat(); 
                break;
            case 4: 
                cancelBooking(); 
                break;
            case 5: 
                searchBooking(); 
                break;
            case 6: 
                revenueReport(); 
                break;
            case 7: 
                adminMenu(); 
                break;
            case 8:
                printf("Exiting. Goodbye!\n");
                return 0;
        }
    }
    return 0;
}