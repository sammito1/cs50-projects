#define _XOPEN_SOURCE

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define ALPHALENGTH 52

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("usage: ./crack hash");
        return (1);
    }

    string givenHash = argv[1];

    char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\0";
    char unhashed[6];
    string generatedHash;
    unhashed[1] =  '\0';

    // single digit alphas
    for (int i = 0; i < ALPHALENGTH; i++)
    {
        unhashed[0] = alphabet[i];
        printf("%s\n", unhashed);
        generatedHash = crypt(unhashed, "50");
        if (strcmp(generatedHash, givenHash) == 0)
        {
            printf("%s\n", unhashed);
            return (1);
        }
    }

    // resetting all data in array to default ('a' in each spot)
    unhashed[0] = alphabet[0];
    unhashed[1] = alphabet[0];
    unhashed[2] = '\0';

    // double digit alpha combinations
    for (int i = 0; i < ALPHALENGTH; i++)
    {
        for (int j = 0; j < ALPHALENGTH; j++)
        {
            unhashed[1] = alphabet[j];
            printf("%s\n", unhashed);
            generatedHash = crypt(unhashed, "50");
            if (strcmp(generatedHash, givenHash) == 0)
            {
                printf("%s\n", unhashed);
                return (1);
            }
        }
        unhashed[0] = alphabet[i];
        printf("%s\n", unhashed);
        generatedHash = crypt(unhashed, "50");
        if (strcmp(generatedHash, givenHash) == 0)
        {
            printf("%s\n", unhashed);
            return (1);
        }
    }

    // resetting all data in array to default ('a' in each spot)
    unhashed[0] = alphabet[0];
    unhashed[1] = alphabet[0];
    unhashed[2] = alphabet[0];
    unhashed[3] = '\0';

    // triple digit alpha combinations
    for (int i = 0; i < ALPHALENGTH; i++)
    {
        for (int j = 0; j < ALPHALENGTH; j++)
        {
            for (int k = 0; k < ALPHALENGTH; k++)
            {
                unhashed[2] = alphabet[k];
                printf("%s\n", unhashed);
                generatedHash = crypt(unhashed, "50");
                if (strcmp(generatedHash, givenHash) == 0)
                {
                    printf("%s\n", unhashed);
                    return (1);
                }
            }
            unhashed[1] = alphabet[j];
            printf("%s\n", unhashed);
            generatedHash = crypt(unhashed, "50");
            if (strcmp(generatedHash, givenHash) == 0)
            {
                printf("%s\n", unhashed);
                return (1);
            }
        }
        unhashed[0] = alphabet[i];
        printf("%s\n", unhashed);
        generatedHash = crypt(unhashed, "50");
        if (strcmp(generatedHash, givenHash) == 0)
        {
            printf("%s\n", unhashed);
            return (1);
        }
    }

    // resetting all data in array to default ('a' in each spot)
    unhashed[0] = alphabet[0];
    unhashed[1] = alphabet[0];
    unhashed[2] = alphabet[0];
    unhashed[3] = alphabet[0];
    unhashed[4] = '\0';

    // four digit alpha combinations
    for (int i = 0; i < ALPHALENGTH; i++)
    {
        for (int j = 0; j < ALPHALENGTH; j++)
        {
            for (int k = 0; k < ALPHALENGTH; k++)
            {
                for (int l = 0; l < ALPHALENGTH; l++)
                {
                    unhashed[3] = alphabet[l];
                    printf("%s\n", unhashed);
                    generatedHash = crypt(unhashed, "50");
                    if (strcmp(generatedHash, givenHash) == 0)
                    {
                        printf("%s\n", unhashed);
                        return (1);
                    }
                }
                unhashed[2] = alphabet[k];
                printf("%s\n", unhashed);
                generatedHash = crypt(unhashed, "50");
                if (strcmp(generatedHash, givenHash) == 0)
                {
                    printf("%s\n", unhashed);
                    return (1);
                }
            }
            unhashed[1] = alphabet[j];
            printf("%s\n", unhashed);
            generatedHash = crypt(unhashed, "50");
            if (strcmp(generatedHash, givenHash) == 0)
            {
                printf("%s\n", unhashed);
                return (1);
            }
        }
        unhashed[0] = alphabet[i];
        printf("%s\n", unhashed);
        generatedHash = crypt(unhashed, "50");
        if (strcmp(generatedHash, givenHash) == 0)
        {
            printf("%s\n", unhashed);
            return (1);
        }
    }

    // resetting all data in array to default ('a' in each spot)
    unhashed[0] = alphabet[0];
    unhashed[1] = alphabet[0];
    unhashed[2] = alphabet[0];
    unhashed[3] = alphabet[0];
    unhashed[4] = alphabet[0];
    unhashed[5] = '\0';

    // five digit alpha combinations
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
                        printf("%s\n", unhashed);
                        generatedHash = crypt(unhashed, "50");
                        if (strcmp(generatedHash, givenHash) == 0)
                        {
                            printf("%s\n", unhashed);
                            return (1);
                        }
                    }
                    unhashed[3] = alphabet[l];
                    printf("%s\n", unhashed);
                    generatedHash = crypt(unhashed, "50");
                    if (strcmp(generatedHash, givenHash) == 0)
                    {
                        printf("%s\n", unhashed);
                        return (1);
                    }
                }
                unhashed[2] = alphabet[k];
                printf("%s\n", unhashed);
                generatedHash = crypt(unhashed, "50");
                if (strcmp(generatedHash, givenHash) == 0)
                {
                    printf("%s\n", unhashed);
                    return (1);
                }
            }
            unhashed[1] = alphabet[j];
            printf("%s\n", unhashed);
            generatedHash = crypt(unhashed, "50");
            if (strcmp(generatedHash, givenHash) == 0)
            {
                printf("%s\n", unhashed);
                return (1);
            }
        }
        unhashed[0] = alphabet[i];
        printf("%s\n", unhashed);
        generatedHash = crypt(unhashed, "50");
        if (strcmp(generatedHash, givenHash) == 0)
        {
            printf("%s\n", unhashed);
            return (1);
        }

    }
}
