// This program encrypts messages using Vigenère's cipher

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define ALPHABETLENGTH 26

int main(int argc, string argv[])
{
    // second argument assigned to keyword "k"
    string keyword = argv[1];

    // checking number of arguments, if valid, continues to character validation
    if (argc == 2)
    {
        // iterating through characters in string, checking if they are alphabetical
        for (int i = 0; i < strlen(keyword); i++)
        {
            if (isalpha(keyword[i]) == false) // why does this break if I use != true insted of == false?
            {
                printf("Error, keyword is not composed of entirely alphabetical characters\n");
                // if any character k[i] is not alphabetical, return 1 to main
                return (1);
            }
        }
    }
    else
    {
        printf("Error, argument count not equal to 2\n");
        return (1);
    }

    // Prompt user for a string of plaintext, storing it as variable "p"
    string plaintext = get_string("plaintext: ");

    // print "ciphertext: "
    printf("ciphertext: ");

    // encrypt plaintext according to cypher with respect to the keyword
    // iterating through plaintext characters
    for (int i = 0, j = 0; i < strlen(plaintext); i++)
    {
        // if alpha, preserve case
        if (isalpha(plaintext[i]))
        {
            // convert from ASCII index to alpha index, add key,
            // use modulo to assure wrapping around alphabet, then reconvert to ASCII
            if (isupper(plaintext[i]) && isupper(keyword[j % strlen(keyword)]))
            {
                printf("%c", ((((plaintext[i] - 'A') + (keyword[j % strlen(keyword)] - 'A')) % 26) + 'A'));
                j++;
            }
            else if (islower(plaintext[i]) && islower(keyword[j % strlen(keyword)]))
            {
                printf("%c", ((((plaintext[i] - 'a') + (keyword[j % strlen(keyword)] - 'a')) % 26) + 'a'));
                j++;
            }
            else if (isupper(plaintext[i]) && islower(keyword[j % strlen(keyword)]))
            {
                printf("%c", ((((plaintext[i] - 'A') + (keyword[j % strlen(keyword)] - 'a')) % 26) + 'A'));
                j++;
            }
            else if (islower(plaintext[i]) && isupper(keyword[j % strlen(keyword)]))
            {
                printf("%c", ((((plaintext[i] - 'a') + (keyword[j % strlen(keyword)] - 'A')) % 26) + 'a'));
                j++;
            }
        }
        // if not alpha, simply print
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return (0);
}