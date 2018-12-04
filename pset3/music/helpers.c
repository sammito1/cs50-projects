// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "helpers.h"

#define BASEFREQUENCY 440.00
// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    float numerator = (fraction[0] - '0'); // subtract char '0' in order to convert from ASCII to related int value!
    float denominator = (fraction[2] - '0');
    float numEighthNotes = (numerator / denominator) * 8;
    return numEighthNotes;
}

// Calculates frequency (in Hz) of a note
// Note can be received in the format A4, A#4, etc...
// Parse the string into a NOTE and an OCTAVE
// A4 == 440 Hz
// For every semitone UP, multiply by pow(2, 1/12)
// For every semitone DOWN, divide by pow(2, 1/12)
int frequency(string note)
{
    // parsing string "note" into a note and an octave
    char parsedNote[3];
    int parsedOctave;

    for (int i = 0; i < strlen(note); i++)
    {
        if (isalpha(note[i]))
        {
            parsedNote[i] = note[i];
        }
        else if (note[i] == '#' || note[i] == 'b')
        {
            parsedNote[i] = note[i];
            parsedNote[i + 1] = '\0';
        }
        else if (isdigit(note[i]))
        {
            parsedOctave = note[i] - '0'; // subtracting char '0' to convert char note[i] from ASCII to related int value
        }
    }

    // converting to parsed note + octave into a frequency
    // var frequency is = 440 hz, which is the frequency of A4
    float frequency = BASEFREQUENCY;
    // comparing parsed note an entire octave of notes (not including sharps, flats)
    if (parsedNote[0] == 'A')
    {
        // adjusts base frequency to match frequency of note at octave 4
        frequency = BASEFREQUENCY * 1;

        // adjusts frequency up or down one semitone based on if it includes a sharp or flat
        if (parsedNote[1] == '#')
        {
            frequency *= pow(2.00, 1.00 / 12.00);
        }
        else if (parsedNote[1] == 'b')
        {
            frequency /= pow(2.00, 1.00 / 12.00);
        }
    }
    else if (parsedNote[0] == 'B')
    {
        // adjusts base frequency to match frequency of note at octave 4
        frequency = BASEFREQUENCY * pow(2.00, 2.00 / 12.00);

        // adjusts frequency up or down one semitone based on if it includes a sharp or flat
        if (parsedNote[1] == '#')
        {
            frequency *= pow(2.00, 1.00 / 12.00);
        }
        else if (parsedNote[1] == 'b')
        {
            frequency /= pow(2.00, 1.00 / 12.00);
        }
    }
    else if (parsedNote[0] == 'C')
    {
        // adjusts base frequency to match frequency of note at octave 4
        frequency = BASEFREQUENCY / pow(2.00, 9.00 / 12.00);
        // adjusts frequency up or down one semitone based on if it includes a sharp or flat
        if (parsedNote[1] == '#')
        {
            frequency *= pow(2.00, 1.00 / 12.00);
        }
        else if (parsedNote[1] == 'b')
        {
            frequency /= pow(2.00, 1.00 / 12.00);
        }
    }
    else if (parsedNote[0] == 'D')
    {
        // adjusts base frequency to match frequency of note at octave 4
        frequency = BASEFREQUENCY / pow(2.00, 7.00 / 12.00);

        // adjusts frequency up or down one semitone based on if it includes a sharp or flat
        if (parsedNote[1] == '#')
        {
            frequency *= pow(2.00, 1.00 / 12.00);
        }
        else if (parsedNote[1] == 'b')
        {
            frequency /= pow(2.00, 1.00 / 12.00);
        }
    }
    else if (parsedNote[0] == 'E')
    {
        // adjusts base frequency to match frequency of note at octave 4
        frequency = BASEFREQUENCY / pow(2.00, 5.00 / 12.00);

        // adjusts frequency up or down one semitone based on if it includes a sharp or flat
        if (parsedNote[1] == '#')
        {
            frequency *= pow(2.00, 1.00 / 12.00);
        }
        else if (parsedNote[1] == 'b')
        {
            frequency /= pow(2.00, 1.00 / 12.00);
        }
    }
    else if (parsedNote[0] == 'F')
    {
        // adjusts base frequency to match frequency of note at octave 4
        frequency = BASEFREQUENCY / pow(2.00, 4.00 / 12.00);

        // adjusts frequency up or down one semitone based on if it includes a sharp or flat
        if (parsedNote[1] == '#')
        {
            frequency *= pow(2.00, 1.00 / 12.00);
        }
        else if (parsedNote[1] == 'b')
        {
            frequency /= pow(2.00, 1.00 / 12.00);
        }
    }
    else if (parsedNote[0] == 'G')
    {
        // adjusts base frequency to match frequency of note at octave 4
        frequency = BASEFREQUENCY / pow(2.00, 2.00 / 12.00);

        // adjusts frequency up or down one semitone based on if it includes a sharp or flat
        if (parsedNote[1] == '#')
        {
            frequency *= pow(2.00, 1.00 / 12.00);
        }
        else if (parsedNote[1] == 'b')
        {
            frequency /= pow(2.00, 1.00 / 12.00);
        }
    }
    else
    {
        return 1;
    }

    // now that var "frequency" is set to the appropriate note (sharp flat, or neither)...
    // it is adjusted to the appropriate octave based on var "parsedOctave"
    if (parsedOctave == 4)
    {
        return round(frequency);
    }
    else if (parsedOctave > 4)
    {
        return round(frequency * pow(2, parsedOctave - 4));
    }
    else if (parsedOctave < 4)
    {
        return round(frequency / pow(2, 4 - parsedOctave));
    }
    else
    {
        return 1;
    }
}
// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s, "\n") == 0 || strcmp(s, "") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
