#include <stdio.h>
#include "header.h"

struct Booking bookings[MAX_SEATS];
int bookedSeats = 0;

void showAvailableSeats() {
    printf("Available seats: ");
    for (int i = 1; i <= MAX_SEATS; i++) {
        int booked = 0;

        for (int j = 0; j < bookedSeats; j++) {
            if (bookings[j].seatNo == i) {
                booked = 1;
                break;
            }
        }

        if (!booked) {
            printf("%d ", i);
        }
    }
    printf("\n");
}