#ifndef PAYMENT_H
#define PAYMENT_H

#include "data.h"

/* Payment Functions */

double calculatePrice(char row,
                      int isStudent,
                      int isSenior,
                      int numSeats);

void revenueReport();

#endif
