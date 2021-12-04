#include "day3.h"
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define EXAMPLE

#ifdef EXAMPLE
#define DAY3_INPUT_FILENAME "./src/day3/example_input.txt"
#define BIT_LENGTH 5
#else
#define BIT_LENGTH 12
#define DAY3_INPUT_FILENAME "./src/day3/input.txt"
#endif

void day3_part1_results(FILE *);
void day3_part2_results(FILE *, int);

int fileLineCount(FILE *);

void day3_get_results(void)
{

    FILE *fp = fopen(DAY3_INPUT_FILENAME, "r");
    if (!fp)
    {
        fprintf(stderr, "Error[%d] opening file '%s'\n error: %s\n", errno, DAY3_INPUT_FILENAME, strerror(errno));
        return;
    }

    day3_part1_results(fp);
    // day3_part2_results(fp);
    fclose(fp);
}

void day3_part1_results(FILE *fp)
{

    int counts[BIT_LENGTH] = {0};
    int countsIndex = BIT_LENGTH - 1;
    char currentChar;

    int lineCount = 0;

    while ((currentChar = fgetc(fp)) != EOF)
    {
        if (isspace(currentChar))
        {
            lineCount++;
            continue;
        }

        counts[countsIndex] += atoi(&currentChar);
        countsIndex--;
        if (countsIndex < 0)
        {
            countsIndex = BIT_LENGTH - 1;
        }
    };
    unsigned int gamma = 0;
    unsigned int epsilon = 0;

    for (size_t i = 0; i < BIT_LENGTH; i++)
    {
        if (counts[i] > (lineCount / 2))
        {
            gamma |= (1 << i);
            epsilon &= ~(1 << i);
        }
        else
        {
            gamma &= ~(1 << i);
            epsilon |= (1 << i);
        }
    }

    // for (int i = sizeof(gamma); 0 <= i; i--)
    // {
    //     printf("%c", (gamma & (1 << i)) ? '1' : '0');
    // }
    // printf("\n");
    // for (int i = sizeof(epsilon); 0 <= i; i--)
    // {
    //     printf("%c", (epsilon & (1 << i)) ? '1' : '0');
    // }
    // printf("\n");

    printf("Day 3 Part 1: %d\n", gamma * epsilon);
}

// void day3_part2_results(FILE *fp, int entries)
// {
//     int storage[entries][BIT_LENGTH];
//     memset(storage, 0, sizeof(storage));
//     int halfEntries = entries / 2;

//     int countsIndex = BIT_LENGTH - 1;
//     char currentChar;
//     int charIndex = 0;

//     int lineCount = 0;

//     while ((currentChar = fgetc(fp)) != EOF)
//     {

//         if (isspace(currentChar))
//         {
//             lineCount++;
//             continue;
//         }
//         storage[lineCount][charIndex] = currentChar;
//         charIndex++;
//     };
//     for (size_t i = 0; i < BIT_LENGTH; i++)
//     {
//         int oneCounts = 0;
//         for (size_t e = 0; e < entries; e++)
//         {
//             if (storage[e][i] == '1')
//             {
//                 oneCounts++;
//             }
//         }

//         for (size_t e = 0; e < entries; e++)
//         {
//             if (oneCounts > halfEntries)
//             {
//                 storage[e][i] == '1';
//             }
//         }
//     }

//     unsigned int gamma = 0;
//     unsigned int epsilon = 0;

//     for (size_t i = 0; i < BIT_LENGTH; i++)
//     {
//         if (counts[i] > (lineCount / 2))
//         {
//             gamma |= (1 << i);
//             epsilon &= ~(1 << i);
//         }
//         else
//         {
//             gamma &= ~(1 << i);
//             epsilon |= (1 << i);
//         }
//     }

//     // for (int i = sizeof(gamma); 0 <= i; i--)
//     // {
//     //     printf("%c", (gamma & (1 << i)) ? '1' : '0');
//     // }
//     // printf("\n");
//     // for (int i = sizeof(epsilon); 0 <= i; i--)
//     // {
//     //     printf("%c", (epsilon & (1 << i)) ? '1' : '0');
//     // }
//     // printf("\n");

//     printf("Day 3 Part 1: %d\n", gamma * epsilon);
// }

int fileLineCount(FILE *fp)
{
    int lineCount = 0;
    char currentChar;

    while ((currentChar = fgetc(fp)) != EOF)
    {
        if (isspace(currentChar))
        {
            lineCount++;
            continue;
        }
    }
    rewind(fp);
    return lineCount;
}
