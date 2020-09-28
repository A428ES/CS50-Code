#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

float calculateReadingLevel(int stringData[]);

int main(void)
{
    // Prompt user for string that will be evaluated
    string toRead = get_string("What am I reading: ");

    // This array will hold on to the three essential components that will be used in the formula
    int returnData[3] = {0, 0, 0};

    // this will run through the length of the string
    for (int i = 0, n = strlen(toRead); i < n; i++)
    {
        // Depending on ASCII correlation, increment the associated element in returnData array
        if (toRead[i] >= 65 && toRead[i] <= 122)
        {
            returnData[0]++;
        }
        else if (toRead[i] == 46 || toRead[i] == 33 || toRead[i] == 63)
        {
            returnData[1]++;
        }
        else if (toRead[i] == 32)
        {
            if (returnData[2] == 0)
            {
                returnData[2]++;
            }

            returnData[2]++;
        }
    }


    // send information to function that produces average and returns rounded grade level
    float finalResult = calculateReadingLevel(returnData);
    string messageToPrint;

    // filter which message to display to user depending on grade
    if (finalResult >= 16.0)
    {
        messageToPrint = "Grade 16+\n";
    }
    else if (finalResult < 1)
    {
        messageToPrint = "Before Grade 1\n";
    }
    else
    {
        messageToPrint = "Grade %.0f\n";
    }

    printf(messageToPrint, finalResult);
}


float calculateReadingLevel(int stringData[])
{
    double calcArray[2];

    // calculate averages per 100 words
    calcArray[0] = ((double)stringData[0] / (double)stringData[2]) * 100;
    calcArray[1] = ((double)stringData[1] / (double)stringData[2]) * 100;

    // return grade level using specified formula
    return round((0.0588 * calcArray[0]) - (0.296 * calcArray[1]) - 15.8);
}
