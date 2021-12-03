#include "day1.h"
#include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// #ifndef MAX_BUF
// #define MAX_BUF 200
// #endif

void day1_part1_results(void)
{
    // char path[MAX_BUF];
    // char inputFilePath[MAX_BUF];

    // getcwd(path, MAX_BUF);
    // printf("Current working directory: %s\n", path);
    // sprintf(inputFilePath, "%s/src/day1/input.txt", path);
    // printf("inputFilePath: %s\n", inputFilePath);

    // FILE *fptr;
    // fptr = fopen("/Users/michael/workspace/advent-of-code-2021/src/day1/input.txt", "r");
    // int c;
    // while (1)
    // {
    //     c = fgetc(fptr);
    //     if (feof(fptr))
    //     {
    //         break;
    //     }
    //     printf("%c\n", c);
    // }
    // fclose(fptr);
    int increasedDepthCount = 0;
    for (int i = 0; i < DEPTH_SIZE; i++)
    {
        if (i != 0 && depths[i] > depths[i - 1])
        {
            increasedDepthCount++;
        }
    }
    printf("Day 1 Part 1: %d\n", increasedDepthCount);
}

void day1_part2_results(void)
{
    int increasedDepthCount = 0;
    int slidingWindow1Sum = 0;
    int slidingWindow2Sum = 0;

    for (int i = 0; i < DEPTH_SIZE; i++)
    {
        if (i + 3 > DEPTH_SIZE)
        {
            continue;
        }

        slidingWindow2Sum = depths[i] + depths[i + 1] + depths[i + 2];

        if (i != 0 && slidingWindow2Sum > slidingWindow1Sum)
        {
            increasedDepthCount++;
        }
        slidingWindow1Sum = slidingWindow2Sum;
    }
    printf("Day 1 Part 2: %d\n", increasedDepthCount);
}