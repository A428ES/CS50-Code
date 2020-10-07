#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // check that a file name was provided.
    if (argc != 2)
    {
        printf("You did not specify a file to open!\n");

        return 1;
    }

    // open the specified file in read mode
    FILE *theImg = fopen(argv[1], "r");
    FILE *writeImg;

    // check to see if file was opened successfully/exists
    if (theImg == NULL)
    {
        printf("There was an error opening the file!\n");

        return 1;
    }

    // open raw file and find size of file.
    fseek(theImg, 0, SEEK_END);
    int fileSize = ftell(theImg);
    fseek(theImg, 0, SEEK_SET);
    char fileName[7];

    int BytesRead = 0;
    int doneReading = 0;
    int fileCount = 0;
    int inRead = 0;

    // buffer for reading data
    unsigned char readBuff[512];

    while (doneReading != 1)
    {
        fread(readBuff, 512, 1, theImg);

        if (readBuff[0] == 0xff && readBuff[1] == 0xd8 && readBuff[2] == 0xff)
        {
            if (readBuff[3] >= 224 && readBuff[3] <= 229)
            {
                if (inRead == 1)
                {
                    fclose(writeImg);
                }
                sprintf(fileName, "%03i.jpg", fileCount); // create unique file name
                writeImg = fopen(fileName, "wb"); // open file for writing
                fileCount++;
                inRead = 1;
            }
        }

        if (inRead == 1)
        {
            fwrite(readBuff, 512, 1, writeImg);
        }

        BytesRead += 512;

        if (fileSize == BytesRead)
        {
            doneReading = 1;
        }
    }

    fclose(theImg);
}
