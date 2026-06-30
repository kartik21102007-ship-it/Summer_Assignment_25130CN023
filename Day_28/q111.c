#include <stdio.h>
#include <string.h>

struct Ticket {
    int booking_id;
    char passenger_name[50];
    int seat_number;
    char travel_class[20];
    double ticket_price;
};

int main() {
    struct Ticket bookings[100];
    int seat_status[100] = {0};
    int count = 0;
    int next_booking_id = 1001;
    int choice;
    int search_id;
    int requested_seat;
    int found;

    do {
        printf("\n========================================\n");
        printf("         TICKET BOOKING SYSTEM          \n");
        printf("========================================\n");
        printf("1. Book a Ticket\n");
        printf("2. View All Bookings\n");
        printf("3. Cancel a Ticket\n");
        printf("4. Exit\n");
        printf("Select an option (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid option! Please enter a number.\n");
            while (getchar() != '\n');
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1:
                if (count >= 100) {
                    printf("❌ Booking full! No seats available.\n");
                    break;
                }

                printf("\nEnter Passenger Name: ");
                while (getchar() != '\n');
                fgets(bookings[count].passenger_name, sizeof(bookings[count].passenger_name), stdin);
                bookings[count].passenger_name[strcspn(bookings[count].passenger_name, "\n")] = '\0';

                printf("Enter Desired Seat Number (1-100): ");
                if (scanf("%d", &requested_seat) != 1 || requested_seat < 1 || requested_seat > 100) {
                    printf("❌ Invalid seat number!\n");
                    while (getchar() != '\n');
                    break;
                }

                if (seat_status[requested_seat - 1] == 1) {
                    printf("❌ Seat %d is already booked! Please select another seat.\n", requested_seat);
                    break;
                }

                printf("Select Travel Class:\n1. Economy ($150.00)\n2. Business ($400.00)\nEnter choice (1-2): ");
                int class_choice;
                if (scanf("%d", &class_choice) != 1 || (class_choice != 1 && class_choice != 2)) {
                    printf("❌ Invalid class selection!\n");
                    while (getchar() != '\n');
                    break;
                }

                if (class_choice == 1) {
                    strcpy(bookings[count].travel_class, "Economy");
                    bookings[count].ticket_price = 150.00;
                } else {
                    strcpy(bookings[count].travel_class, "Business");
                    bookings[count].ticket_price = 400.00;
                }

                bookings[count].booking_id = next_booking_id;
                bookings[count].seat_number = requested_seat;
                seat_status[requested_seat - 1] = 1;

                printf("\n✅ Booking Successful!\n");
                printf("Booking ID: %d | Seat: %d | Class: %s | Paid: $%.2f\n", 
                       bookings[count].booking_id, bookings[count].seat_number, 
                       bookings[count].travel_class, bookings[count].ticket_price);

                count++;
                next_booking_id++;
                break;

            case 2:
                if (count == 0) {
                    printf("\n📭 No active ticket bookings found.\n");
                    break;
                }
                printf("\n--- ACTIVE PASSENGER BOOKINGS ---\n");
                for (int i = 0; i < count; i++) {
                    printf("ID: %d | Name: %s | Seat: %d | Class: %s | Fare: $%.2f\n", 
                           bookings[i].booking_id, bookings[i].passenger_name, 
                           bookings[i].seat_number, bookings[i].travel_class, bookings[i].ticket_price);
                }
                break;

            case 3:
                if (count == 0) {
                    printf("\n📭 No bookings available to cancel.\n");
                    break;
                }
                printf("\nEnter Booking ID to cancel: ");
                if (scanf("%d", &search_id) != 1) {
                    printf("❌ Invalid ID format!\n");
                    while (getchar() != '\n');
                    break;
                }

                found = 0;
                for (int i = 0; i < count; i++) {
                    if (bookings[i].booking_id == search_id) {
                        found = 1;
                        seat_status[bookings[i].seat_number - 1] = 0;
                        printf("✅ Success! Booking ID %d for %s has been cancelled.\n", 
                               bookings[i].booking_id, bookings[i].passenger_name);

                        for (int j = i; j < count - 1; j++) {
                            bookings[j] = bookings[j + 1];
                        }
                        count--;
                        break;
                    }
                }
                if (!found) {
                    printf("❌ Booking ID %d not found.\n", search_id);
                }
                break;

            case 4:
                printf("\nExiting system. Goodbye!\n");
                break;

            default:
                printf("❌ Invalid selection! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
