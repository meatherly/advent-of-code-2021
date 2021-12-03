#include "day2.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int depthsTest[10] = {
//     199, 200, 208, 210, 200, 207, 240, 269, 260, 263,
// };

#define DAY2_INPUT_FILENAME "./src/day2/input.txt"

void day2_part1_results(void)
{

    /* Open the file for reading */
    char *line_buf = NULL;
    size_t line_buf_size = 0;

    FILE *fp = fopen(DAY2_INPUT_FILENAME, "r");
    if (!fp)
    {
        fprintf(stderr, "Error[%d] opening file '%s'\n error: %s\n", errno, DAY2_INPUT_FILENAME, strerror(errno));
        return;
    }

    int horizontalPosition = 0;
    int depthPosition = 0;

    while (getline(&line_buf, &line_buf_size, fp) > 0)
    {
        int amount;
        // int scannedAmount = sscanf(line_buf, "forward %d", &amount);
        // printf("Contents: %s", line_buf);
        // printf("Amount: %d\n", amount, scannedAmount);
        if (sscanf(line_buf, "forward %d\n", &amount) > 0)
        {
            horizontalPosition += amount;
        }
        if (sscanf(line_buf, "down %d\n", &amount) > 0)
        {
            depthPosition += amount;
        }
        if (sscanf(line_buf, "up %d\n", &amount) > 0)
        {
            depthPosition -= amount;
        }
    }

    fclose(fp);

    // printf("Horizontal: %d\n", horizontalPosition);
    // printf("Depth: %d\n", depthPosition);

    printf("Day 2 Part 1: %d\n", horizontalPosition * depthPosition);
}

void day2_part2_results(void)
{
    /* Open the file for reading */
    char *line_buf = NULL;
    size_t line_buf_size = 0;

    FILE *fp = fopen(DAY2_INPUT_FILENAME, "r");
    if (!fp)
    {
        fprintf(stderr, "Error[%d] opening file '%s'\n error: %s\n", errno, DAY2_INPUT_FILENAME, strerror(errno));
        return;
    }

    int horizontalPosition = 0;
    int depthPosition = 0;
    int aim = 0;

    while (getline(&line_buf, &line_buf_size, fp) > 0)
    {
        int amount;
        // int scannedAmount = sscanf(line_buf, "forward %d", &amount);
        // printf("Contents: %s", line_buf);
        // printf("Amount: %d\n", amount, scannedAmount);
        if (sscanf(line_buf, "forward %d\n", &amount) > 0)
        {
            horizontalPosition += amount;
            depthPosition += aim * amount;
        }
        if (sscanf(line_buf, "down %d\n", &amount) > 0)
        {
            aim += amount;
        }
        if (sscanf(line_buf, "up %d\n", &amount) > 0)
        {
            aim -= amount;
        }
    }

    fclose(fp);

    // printf("Horizontal: %d\n", horizontalPosition);
    // printf("Depth: %d\n", depthPosition);
    printf("Day 2 Part 2: %d\n", horizontalPosition * depthPosition);
}