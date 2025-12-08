#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 35
#define MAX_NAME_LENGTH 50

struct Booking
{
    char name[MAX_NAME_LENGTH];
    int seatNo;
    char source[MAX_NAME_LENGTH];
    char destination[MAX_NAME_LENGTH];
};

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

void bookSeat()
{
    if (bookedSeats >= MAX_SEATS)
    {
        printf("No more seats available.\n");
        return;
    }

    struct Booking newBooking;

    printf("Enter name: ");
    scanf(" %[^\n]", newBooking.name);

    while (1)
    {
        printf("Enter seat number: ");
        scanf("%d", &newBooking.seatNo);

        if (newBooking.seatNo < 1 || newBooking.seatNo > MAX_SEATS)
        {
            printf("Invalid seat number. Choose between 1 and %d.\n", MAX_SEATS);
            continue;
        }

        int taken = 0;
        for (int i = 0; i < bookedSeats; i++)
        {
            if (bookings[i].seatNo == newBooking.seatNo)
            {
                printf("Seat %d is already booked. Choose another seat.\n", newBooking.seatNo);
                taken = 1;
                break;
            }
        }

        if (!taken)
        {
            break;
        }
    }

    printf("Enter source: ");
    scanf(" %[^\n]", newBooking.source);

    printf("Enter destination: ");
    scanf(" %[^\n]", newBooking.destination);

    bookings[bookedSeats++] = newBooking;
    printf("Seat booked successfully.\n\n");
}

void viewReservation()
{
    if (bookedSeats == 0)
    {
        printf("No reservations made yet.\n\n");
        return;
    }

    printf("All Reservations:\n");
    printf("%-10s %-15s %-15s %-15s\n", "Seat No.", "Name", "Source", "Destination");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < bookedSeats; i++)
    {
        printf("%-10d %-15s %-15s %-15s\n",
               bookings[i].seatNo,
               bookings[i].name,
               bookings[i].source,
               bookings[i].destination);
    }

    printf("\n");
}

void editReservation()
{
    int seatToEdit;
    printf("Enter seat number to edit: ");
    scanf("%d", &seatToEdit);

    int found = 0;

    for (int i = 0; i < bookedSeats; i++)
    {
        if (bookings[i].seatNo == seatToEdit)
        {
            printf("Enter new Name: ");
            scanf(" %[^\n]", bookings[i].name);

            printf("Enter new Source: ");
            scanf(" %[^\n]", bookings[i].source);

            printf("Enter new Destination: ");
            scanf(" %[^\n]", bookings[i].destination);

            printf("Reservation edited successfully.\n\n");
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Reservation not found.\n\n");
    }
}

void printTicket()
{
    int seatToPrint;
    printf("Enter seat number to print Ticket: ");
    scanf("%d", &seatToPrint);

    int found = 0;

    for (int i = 0; i < bookedSeats; i++)
    {
        if (bookings[i].seatNo == seatToPrint)
        {
            printf("Ticket for Seat No. %d\n", bookings[i].seatNo);
            printf("Passenger Name: %s\n", bookings[i].name);
            printf("Source: %s\n", bookings[i].source);
            printf("Destination: %s\n\n", bookings[i].destination);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Reservation not found.\n\n");
    }
}

int main()
{
    int choice;

    do {
        printf("=================================================\n");
        printf("        TRANSPORT TICKET BOOKING SYSTEM\n");
        printf("=================================================\n\n");

        printf("1. Available Seats\n");
        printf("2. Book a Seat\n");
        printf("3. View Reservation\n");
        printf("4. Edit Reservation\n");
        printf("5. Print a Ticket\n");
        printf("6. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                showAvailableSeats();
                break;

            case 2:
                bookSeat();
                break;

            case 3:
                viewReservation();
                break;

            case 4:
                editReservation();
                break;

            case 5:
                printTicket();
                break;

            case 6:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 6);

    return 0;
}

