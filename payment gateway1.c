#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void processPayment(float amount) {
    printf("\nProcessing payment...\n");

    // simulate delay
    for(int i = 0; i < 1000000000; i++);

    srand(time(0));
    int success = rand() % 2;

    if(success) {
        printf("Payment Successful!\n");
        printf("Amount Paid: Rs. %.2f\n", amount);
    } else {
        printf("Payment Failed! Try again.\n");
    }
}

void upiPayment(float amount) {
    char upi[50];

    printf("Enter UPI ID: ");
    scanf("%s", upi);

    if(strchr(upi, '@') != NULL) {
        printf("Valid UPI ID\n");
        processPayment(amount);
    } else {
        printf("Invalid UPI ID\n");
    }
}

void cardPayment(float amount) {
    char card[20];
    char cvv[5];

    printf("Enter Card Number: ");
    scanf("%s", card);

    printf("Enter CVV: ");
    scanf("%s", cvv);

    if(strlen(card) == 16 && strlen(cvv) == 3) {
        printf("Card details valid\n");
        processPayment(amount);
    } else {
        printf("Invalid Card Details\n");
    }
}

int main() {
    int choice;
    float amount;

    printf("===== PAYMENT GATEWAY =====\n");
    printf("Enter Amount: Rs. ");
    scanf("%f", &amount);

    printf("\nSelect Payment Method:\n");
    printf("1. UPI\n");
    printf("2. Card\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            upiPayment(amount);
            break;
        case 2:
            cardPayment(amount);
            break;
        default:
            printf("Invalid Choice\n");
    }

    return 0;
}