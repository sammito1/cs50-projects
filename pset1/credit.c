// This program determines whether a provided credit card number (user-input) is valid according to Luhn's algorithm.
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // user-input for number greater than 0
    long long ccNumber;
    do
    {
        ccNumber = get_long_long("Number: ");
    }
    while (ccNumber <= 0);

    // count number of digits
    int numDigits = 0;
    long long digitValidator = ccNumber;

    while (digitValidator != 0)
    {
        // divides by 10 until the long long is == 0.. i.e: 400/10 -> 40; 40/10 -> 4; 4/10 -> 0
        // this digit counter works by counting the number of times it takes to divide by 10 to get to 0.
        digitValidator = digitValidator / 10;
        numDigits++;
    }

    // first checksum on the first set of digits
    long long firstDigitSet = ccNumber;
    int digits = 2 * ((firstDigitSet / 10) % 10);
    firstDigitSet /= 10;
    int sum = (digits / 10) + (digits % 10);

    for (int i = 0; i < numDigits; i++)
    {
        // isolating the necessary digits and multiplying by 2
        digits = 2 * ((firstDigitSet / 100) % 10);
        firstDigitSet /= 100;
        // adding the products' digits
        sum += (digits / 10) + (digits % 10);
    }

    // second checksum on second set of digits
    long long secondDigitSet = ccNumber;
    sum += secondDigitSet % 10;
    for (int i = 0; i < numDigits; i++)
    {
        // isolating the other digits
        digits = ((secondDigitSet / 100) % 10);
        sum += (digits / 10) + (digits % 10);
        secondDigitSet /= 100;
    }

    // Isolating first two digits for use in final check
    int firstTwoDigits = 0;

    // Checking for digit length and company specs
    if (numDigits == 15 && sum % 10 == 0)
    {
        firstTwoDigits = ccNumber / 10000000000000;
        switch (firstTwoDigits)
        {
            case 34:
            case 37:
                printf("AMEX\n");
                break;

            default:
                printf("INVALID\n");
                break;
        }
    }
    else if (numDigits == 13 && sum % 10 == 0)
    {
        firstTwoDigits = ccNumber / 100000000000;
        if ((firstTwoDigits / 10) % 10 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (numDigits == 16 && sum % 10 == 0)
    {
        firstTwoDigits = ccNumber / 100000000000000;
        if ((firstTwoDigits / 10) % 10 == 4)
        {
            printf("VISA\n");
        }
        else if (firstTwoDigits == 51 || firstTwoDigits == 52 || firstTwoDigits == 53 || firstTwoDigits == 54
                 || firstTwoDigits == 55)
        {
            printf("MASTERCARD\n");
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