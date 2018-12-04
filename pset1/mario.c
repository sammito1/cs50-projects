#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user for height
    int h;
    do
    {
        h = get_int("Positive integer less than 23: ");
    }
    while (h < 0 || h > 23);

    // Steps for drawing each row of the pyramid
    // Print out configured rows until i is not < h
    for (int i = 0; i < h; i++)
    {
        // print spaces for left pyramid
        for (int j = 0; j < h - (i + 1); j++)
        {
            printf(" ");
        }

        // print hashes for left pyramid
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        // print gap
        for (int j = 0; j < 2; j++)
        {
            printf(" ");
        }
        // print hashes for right pyramid
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        // print new line
        printf("\n");
    }
}
