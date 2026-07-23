#include "admin.h"

void adminMenu()
{
    int choice;

    while(1)
    {
        printf("\n========== ADMIN PANEL ==========\n");
        printf("1. View Revenue Report\n");
        printf("2. Back to Main Menu\n");
        printf("Enter choice: ");

        if(scanf("%d",&choice)!=1)
        {
            while(getchar()!='\n');
            printf("Invalid input.\n");
            continue;
        }

        switch(choice)
        {
            case 1:
                revenueReport();
                break;

            case 2:
                return;

            default:
                printf("Invalid choice.\n");
        }
    }
}
