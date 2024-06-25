#include "headerA3.h"
#include "headerAddA3.h"

// Function 6: Saves the linked list to a file
void saveTweetsToFile(tweet * tweetList)
{
    // Declaring variables
    FILE * file;
    tweet * tempF6;
    int truth;
    char fileName[51];

    // Initializing variables
    tempF6 = tweetList;
    truth = 0;

    printf("\nEnter the filename where you would like to store your tweets: ");
    scanf("%s", fileName);

    // Dummy proofing fileName (length of name must be 1 - 51)
    while (truth == 0)
    {
        if ((strlen(fileName) > 0) && (strlen(fileName) <= 51))
        {
            truth = 1;
        }
        else
        {
            printf ("\nInvalid input, try again.\n");
            scanf("%s", fileName);
        }
    }

    // Will open the file to write in "fileName" that the user inputted
    file = fopen(fileName, "w");

    // Checks if the file has opened properly
    if (file == NULL)
    {
        printf ("\nError with creating the file.\n");
        return;
    }
    else
    {
        // Prints the linked list data to "fileName"
        while (tempF6 != NULL)
        {
            fprintf(file, "%d, %s, %s\n", tempF6->id, tempF6->user, tempF6->text);
            tempF6 = tempF6->next;
        }
    }

    // Closes the file
    fclose(file);
    
    printf("\nOutput successful!\n");
}