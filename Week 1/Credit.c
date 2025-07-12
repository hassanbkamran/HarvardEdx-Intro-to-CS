#include <stdio.h>

int main(void) {
    long long number;
    int length = 0;

    do {
        printf("Card Number: ");
        scanf("%lld", &number);

        length = 0;
        long long temp_num = number;
        while (temp_num != 0) {
            temp_num /= 10;
            length++;
        }
    } while (length < 13 || length > 19);

    long long num = number;

    while (num >= 100) {
        num = num / 10;
    }

    char* card;

    if ((num == 34 || num == 37) && (length == 15)) {
        card = "AMEX";
    } else if ((num >= 51 && num <= 55) && (length == 16)) {
        card = "MasterCard";
    } else if ((num / 10 == 4) && (length == 13 || length == 16)) {
        card = "VISA";
    } else {
        card = "Could not Identify";
    }

    int digit, multiple, odd = 0, even = 0, pos = 1, validation;

    while (number > 0) {
        digit = number % 10;

        if (pos % 2 == 0) { 
            multiple = digit * 2;
            if (multiple >= 10) {
                even += (multiple % 10) + (multiple / 10);
            } else {
                even += multiple;
            }
        } else {
            odd += digit;
        }

        number = number / 10;
        pos++;
        }
    validation = (odd + even) % 10;

    if (validation == 0) {
        printf("Card Validated\nCard Name: %s", card);
    } else {
        printf("Card Invalid");
    }
}

