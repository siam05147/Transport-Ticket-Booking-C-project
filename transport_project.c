#include<stdio.h
#include<stdlib.h>
#include<string.h>

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
    for(int i = 1; i <= MAX_SEATS; i++) {
        int booked = 0;
        for(int j = 0; j < bookedSeats; j++) {
            if(bookings[j].seatNo == i) {
                booked = 1;
                break;
            }
        }
        if(!booked) printf("%d ", i);
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

    printf("\n");
    printf("Enter name: ");
    scanf("%s", newBooking.name);
    printf("Enter seat number: ");
    scanf("%d", &newBooking.seatNo);
    
    
    if (newBooking.seatNo < 1 || newBooking.seatNo > MAX_SEATS)
    {
        printf("Invalid seat number. Please choose between 1 to %d.\n", MAX_SEATS);
        return;
        
    }
    
    
    for (int i = 0; i < bookedSeats; i++)
    {
        if (bookings[i].seatNo == newBooking.seatNo)
        {
            printf("Seat %d is already booked.\n", newBooking.seatNo);
            return;
            
        }
    }

    printf("Enter source: ");
    scanf("%s", newBooking.source);
    printf("Enter destination: ");
    scanf("%s", newBooking.destination);

    bookings[bookedSeats++] = newBooking;
    printf("Seat booked successfully.\n");
    printf("\n");
}


void viewReservation()
{
    if(bookedSeats == 0)
    {
        printf("No reservations made yet.\n");
        printf("\n");
        return;
    }
    printf("All reservations:\n");
    printf("Seat No.     Name     Source     Destination\n");
    printf("--------   --------  --------   ------------\n");
    for(int i = 0; i < bookedSeats; ++i)
    {
        printf("   %d       %s       %s      %s\n", 
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
    for(int i = 0; i< bookedSeats; ++i)
    {
        if(bookings[i].seatNo == seatToEdit)
        {
            printf("Enter new Name: ");
            scanf("%s", bookings[i].name);
            printf("Enter new Source: ");
            scanf("%s", bookings[i].source);
            printf("Enter new Destination: ");
            scanf("%s", bookings[i].destination);
  
            printf("Reservation edited successfully.\n");
            printf("\n");
            found = 1;
            break;
            
        }
    }
    if(!found)
    {
        printf("Reservation not found.\n");
        printf("\n");
    }
}

void printTicket()
{
    int seatToPrint;
    printf("Enter seat number to print Ticket: ");
    scanf("%d", &seatToPrint);

    int found = 0;
    for(int i = 0; i< bookedSeats; ++i)
    {
        if (bookings[i].seatNo == seatToPrint)
        {
            printf("Ticket for Seat No. %d\n", bookings[i].seatNo);
            printf("Passenger Name: %s\n", bookings[i].name);
            printf("Passenger Source: %s\n", bookings[i].source);
            printf("Passenger Destination: %s\n", bookings[i].destination);

            printf("\n");
            found = 1;
            break;
         
            
        }
    }
    if(!found)
    {
        printf("Reservation not found.\n");
        printf("\n");
    }
}

int main()

{
    int choice;
    do {
   
    printf("     =================================================\n");
    
    printf("     |      TRANSPORT TICKET BOOKING SYSTEM          |\n");
   
    printf("     =================================================\n");
        printf("\n");
        printf("       1. Available Seats\n");
        printf("       2. Book a Seat\n");
        printf("       3. View Reservation\n");
        printf("       4. Edit Reservation\n");
        printf("       5. Print a Ticket\n");
        printf("       6. Exit\n");
        printf("\n");
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
            printf("Exiting. . . .");
            break;
            default:
            printf("Invalid Choice. Please enter a valid option.\n");
        }
       
    }while (choice !=6);

    return 0;

}
