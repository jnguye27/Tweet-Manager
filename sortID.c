#include "header.h"

// Function 8: Sorts the nodes based on id values
void sortID (tweet ** head)
{
    // Declaring variables
    tweet * tempF8;
    tweet * tempF8Before;
    int tempValue;
    int i;
    char switchOne[51];
    char switchTwo[141];

    // Initializing variables 
    tempF8 = *head;
    tempF8Before = tempF8;
    i = 0;

    // Will read and compare id values within the linked list, loops 10x to make sure
    for (i = 0; i < 10; i++)
    {
        while (tempF8 != NULL)
        {
            tempF8Before = tempF8;

            while (tempF8Before->next != NULL)
            {
                // Goes through each node, if the current node id is > the next node id, switch eachother's node data
                if ((tempF8Before->id) > (tempF8Before->next->id))
                {
                    // Puts the current node's values into temporary variables
                    strcpy(switchOne, tempF8Before->user);
                    strcpy(switchTwo, tempF8Before->text);
                    tempValue = tempF8Before->id;

                    // Puts the next node's data into the current node
                    strcpy(tempF8Before->user, tempF8Before->next->user);
                    strcpy(tempF8Before->text, tempF8Before->next->text);
                    tempF8Before->id = tempF8Before->next->id;

                    // Puts the data in the temporary variables into the next node
                    strcpy(tempF8Before->next->user, switchOne);
                    strcpy(tempF8Before->next->text, switchTwo);
                    tempF8Before->next->id = tempValue;
                }

                // Repeats that process by moving right (left is now sorted) over and over
                tempF8Before = tempF8Before->next;
            }
        
            // Moves to the next node
            tempF8 = tempF8->next;
        }
        tempF8 = *head;
    }

    printf("Tweets have been reorganized.\n");
}
