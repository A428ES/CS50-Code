#include <stdio.h>
#include <cs50.h>

void drawSpace(int spaces);
void drawBlock(int blocks);

int main(void)
{
    // variable for pyramid height dimension
    int pyramidHeight;

    // prompt user for height specifics
    do
    {
        pyramidHeight = get_int("How tall should Pyramid be?: ");
    }
    while (pyramidHeight <= 0 || pyramidHeight > 8); // continue prompting as long as user input is invalid


    // for loop for drawing pyramid height
    for (int i = 0; i < pyramidHeight; i++)
    {
        drawSpace(pyramidHeight - i); // indent for symmetry
        drawBlock(i + 1); // draw hashtags for side a

        printf("  "); // seperate sides

        drawBlock(i + 1); // draw hastags for side b

        printf("\n"); // new line
    }
}

void drawSpace(int spaces)
{
    // function for printing spaces involving symmetrical appearence
    spaces--;
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
}

void drawBlock(int blocks)
{
    // function for drawing hashtag blocks

    for (int i = 0; i < blocks; i++)
    {
        printf("#");
    }
}
