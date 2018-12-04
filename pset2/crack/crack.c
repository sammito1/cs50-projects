#define _XOPEN_SOURCE // for crypt() functionality

#include <stdio.h> // library for standard in/out (i.e printf() function)
#include <cs50.h> // introduces some string functionality (vartype string)
#include <string.h> // library to introduce more string related functionality (i.e strlen(), strcmp(), etc)
#include <unistd.h> // library for crypt() function

// this defined constant ALPHALENGTH is simply the length of the alphabet when comprised of both lower and uppercase letters
// on line 27, the array alphabet[] stores these char values.
// however, I will be using this defined constant to avoid constantly calling the strlen() function in loops ...
// along with having to make a new variable for this integer that I need to remain constant.
#define ALPHALENGTH 52

// main function will enable us access to two key variables:
// the argument count of type int, and  the argument vector of type string
int main(int argc, string argv[])
{
    // if argument count is not 2, terminate with error
    if (argc != 2)
    {
        printf("usage: ./crack hash");
        return (1);
    }

    string givenHash = argv[1];

    // set array of type char equal to every letter of the alphabet
    // included \0 at the end (nul terminator) in order to ensure string functionality
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\0";
    char unhashed[6];
    string generatedHash;

    // preparing the unhashed[] array (which can hold UP TO 5 chars not including the null terminator)
    // for this, the null terminator will be at position [1], as only the first letter will be generated next
    unhashed[1] =  '\0';

    // generate all possible single digit alphabetical characters
    // furthermore, the 1-letter strings are hashed and compared to the given hash.
    for (int i = 0; i < ALPHALENGTH; i++)
    {
        unhashed[0] = alphabet[i];
        generatedHash = crypt(unhashed, "50");
        // this if statement ensures that the program will terminate if the generatedHash is == the givenHash
        if (strcmp(generatedHash, givenHash) == 0)
        {
            printf("%s\n", unhashed);
            return (0);
        }
    }

    // resetting all data in array to default ('a' in each spot)
    unhashed[0] = alphabet[0];
    unhashed[1] = alphabet[0];
    unhashed[2] = '\0';

    // generating and comparing all possible combinations of two digit alphabetical characters
    for (int i = 0; i < ALPHALENGTH; i++)
    {
        for (int j = 0; j < ALPHALENGTH; j++)
        {
            unhashed[1] = alphabet[j];
            generatedHash = crypt(unhashed, "50");
            if (strcmp(generatedHash, givenHash) == 0)
            {
                printf("%s\n", unhashed);
                return (0);
            }
        }
        unhashed[0] = alphabet[i];
        generatedHash = crypt(unhashed, "50");
        if (strcmp(generatedHash, givenHash) == 0)
        {
            printf("%s\n", unhashed);
            return (0);
        }
    }

    // resetting all data in array to default ('a' in each spot)
    unhashed[0] = alphabet[0];
    unhashed[1] = alphabet[0];
    unhashed[2] = alphabet[0];
    unhashed[3] = '\0';

    // generating all possible combinations of three digit letters
    for (int i = 0; i < ALPHALENGTH; i++)
    {
        for (int j = 0; j < ALPHALENGTH; j++)
        {
            for (int k = 0; k < ALPHALENGTH; k++)
            {
                unhashed[2] = alphabet[k];
                generatedHash = crypt(unhashed, "50");
                if (strcmp(generatedHash, givenHash) == 0)
                {
                    printf("%s\n", unhashed);
                    return (0);
                }
            }
            unhashed[1] = alphabet[j];
            generatedHash = crypt(unhashed, "50");
            if (strcmp(generatedHash, givenHash) == 0)
            {
                printf("%s\n", unhashed);
                return (0);
            }
        }
        unhashed[0] = alphabet[i];
        generatedHash = crypt(unhashed, "50");
        if (strcmp(generatedHash, givenHash) == 0)
        {
            printf("%s\n", unhashed);
            return (0);
        }
    }

    // resetting all data in array to default ('a' in each spot)
    unhashed[0] = alphabet[0];
    unhashed[1] = alphabet[0];
    unhashed[2] = alphabet[0];
    unhashed[3] = alphabet[0];
    unhashed[4] = '\0';

    // generating all possible combinations of four digit letters
    for (int i = 0; i < ALPHALENGTH; i++)
    {
        for (int j = 0; j < ALPHALENGTH; j++)
        {
            for (int k = 0; k < ALPHALENGTH; k++)
            {
                for (int l = 0; l < ALPHALENGTH; l++)
                {
                    unhashed[3] = alphabet[l];
                    generatedHash = crypt(unhashed, "50");
                    if (strcmp(generatedHash, givenHash) == 0)
                    {
                        printf("%s\n", unhashed);
                        return (0);
                    }
                }
                unhashed[2] = alphabet[k];
                generatedHash = crypt(unhashed, "50");
                if (strcmp(generatedHash, givenHash) == 0)
                {
                    printf("%s\n", unhashed);
                    return (0);
                }
            }
            unhashed[1] = alphabet[j];
            generatedHash = crypt(unhashed, "50");
            if (strcmp(generatedHash, givenHash) == 0)
            {
                printf("%s\n", unhashed);
                return (0);
            }
        }
        unhashed[0] = alphabet[i];
        generatedHash = crypt(unhashed, "50");
        if (strcmp(generatedHash, givenHash) == 0)
        {
            printf("%s\n", unhashed);
            return (0);
        }
    }

    // resetting all data in array to default ('a' in each spot)
    unhashed[0] = alphabet[0];
    unhashed[1] = alphabet[0];
    unhashed[2] = alphabet[0];
    unhashed[3] = alphabet[0];
    unhashed[4] = alphabet[0];
    unhashed[5] = '\0';

    // generating all possible combinations of five digit letters
    for (int i = 0; i < ALPHALENGTH; i++)
    {
        for (int j = 0; j < ALPHALENGTH; j++)
        {
            for (int k = 0; k < ALPHALENGTH; k++)
            {
                for (int l = 0; l < ALPHALENGTH; l++)
                {
                    for (int m = 0; m < ALPHALENGTH; m++)
                    {
                        unhashed[4] = alphabet[m];
                        generatedHash = crypt(unhashed, "50");
                        if (strcmp(generatedHash, givenHash) == 0)
                        {
                            printf("%s\n", unhashed);
                            return (0);
                        }
                    }
                    unhashed[3] = alphabet[l];
                    generatedHash = crypt(unhashed, "50");
                    if (strcmp(generatedHash, givenHash) == 0)
                    {
                        printf("%s\n", unhashed);
                        return (0);
                    }
                }
                unhashed[2] = alphabet[k];
                generatedHash = crypt(unhashed, "50");
                if (strcmp(generatedHash, givenHash) == 0)
                {
                    printf("%s\n", unhashed);
                    return (0);
                }
            }
            unhashed[1] = alphabet[j];
            generatedHash = crypt(unhashed, "50");
            if (strcmp(generatedHash, givenHash) == 0)
            {
                printf("%s\n", unhashed);
                return (0);
            }
        }
        unhashed[0] = alphabet[i];
        generatedHash = crypt(unhashed, "50");
        if (strcmp(generatedHash, givenHash) == 0)
        {
            printf("%s\n", unhashed);
            return (0);
        }

    }
}
