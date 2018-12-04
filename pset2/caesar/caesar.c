// Implement a program that encrypts messages using Caesar’s cipher

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define ALPHABETLENGTH 26
#define UPPERAASCII 65
#define LOWERAASCII 97

int main(int argc, string argv[])
{
    // testing command-line arguments
    if (argc != 2)
    {
        printf("Error, must have 2 command line arguments\n");
        return (1);
    }
    int key = atoi(argv[1]);

    // getting plaintext input
    string plaintext = get_string("plaintext: ");

    // print ciphertext:
    printf("ciphertext: ");
    // iterating through plaintext characters
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // if alpha, preserve case
        if (isalpha(plaintext[i]))
        {
            // convert from ASCII index to alpha index, add key,
            // use modulo to assure wrapping, then reconvert to ASCII
            if (isupper(plaintext[i]))
            {
                printf("%c", (((plaintext[i] + key - UPPERAASCII) % ALPHABETLENGTH)) + UPPERAASCII);
                j++;
            }
            else if (islower(plaintext[i]))
            {
                printf("%c", (((plaintext[i] + key - LOWERAASCII) % ALPHABETLENGTH)) + LOWERAASCII);
                j++;
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }

    }
    printf("\n");
    return (0);
}