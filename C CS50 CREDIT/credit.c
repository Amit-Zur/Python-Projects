#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // Prompot for input (GET LONG)
    // Calculate checksum of the card
    // Check for card length and starting digits
    // Print AMEX / VISA / MASTER CARD / INVALID

    long user_card_number = get_long("Please enter a valid credit card number: ");

    int credit_card_sum = 0;
    int credit_card_count = 0;
    int first_credit_digit = 0;
    int second_credit_digit = 0;

    while (user_card_number > 0)
    {
        int last_credit_digit = user_card_number % 10;

        if (credit_card_count % 2 == 0)
        {
            credit_card_sum += last_credit_digit;
        }
        else
        {
            int digit_multi = last_credit_digit * 2;
            credit_card_sum += digit_multi / 10 + digit_multi % 10;
        }

        if (user_card_number < 100 && user_card_number >= 10)
        {
            second_credit_digit = last_credit_digit;
        }
        else if (user_card_number < 10)
        {
            first_credit_digit = last_credit_digit;
        }

        user_card_number /= 10;
        credit_card_count++;
    }

    if (credit_card_sum % 10 == 0)
    {
        // AMEX
        if (credit_card_count == 15 && first_credit_digit == 3 && (second_credit_digit == 4 || second_credit_digit == 7))
        {
            printf("AMEX\n");
        }
        // MASTERCARD
        else if (credit_card_count == 16 && first_credit_digit == 5 && (second_credit_digit >= 1 && second_credit_digit <= 5))
        {
            printf("MASTERCARD\n");
        }
        // VISA
        else if ((credit_card_count == 13 || credit_card_count == 16) && first_credit_digit == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
