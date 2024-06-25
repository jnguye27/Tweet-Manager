#include "headerA3.h"
#include "headerAddA3.h"

// Function 7: Loads the file linked list to a program
void loadTweetsFromFile(tweet ** tweetList)
{
    // Declaring variables
    FILE * file = NULL;
    tweet * tempF7;
    int truth;
    int i;
    char fileName[51];
    char fileString[200];
    char * split;

    // Initializing variables & Allocating space
    tempF7 = *tweetList;
    truth = 0;
    i = 0;

    printf("\nEnter a filename to load from: ");
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
    file = fopen(fileName, "r");

    // Checks if the file has opened properly / if the fileName I'm searching for exists
    if (file == NULL)
    {
        printf ("\nError with creating the file.\n");
        return;
    }
    else
    {
        while(fgets(fileString, 200, file))
        {
            // I have to declare the node in here to create multiple nodes & allocate memory for each
            struct microtweet * node = malloc(sizeof(struct microtweet));

            // Removes the newline at the end of each fgets input
            if (fileString[strlen(fileString)-1] == '\n')
            {
                fileString[strlen(fileString)-1] = '\0';
            }

            // Using strtok to split the string up and putting them in their correct data variables: id, user, text
            split = strtok(fileString, ",");

            // atoi() will convert the string of digits into integer digits
            node->id = atoi(split);

            split = strtok(NULL, ",");
            strcpy(node->user, split);
            if (node->user[0] == ' ')
            {
                // Gets rid of any spaces that were accidentally added at the front
                for (i = 0; i < strlen(node->user); i++)
                {
                    if (i == (strlen(node->user)-1))
                    {
                        node->user[i] = '\0';

                    }
                    else
                    {
                        node->user[i] = node->user[i+1];
                    }
                }
            }

            split = strtok(NULL, ",");
            strcpy(node->text, split);
            if (node->text[0] == ' ')
            {
                // Gets rid of any spaces that were accidentally added at the front
                for (i = 0; i < strlen(node->text); i++)
                {
                    if (i == (strlen(node->text)-1))
                    {
                        node->text[i] = '\0';

                    }
                    else
                    {
                        node->text[i] = node->text[i+1];
                    }
                }
            }

            // Since the added node is at the end, we must make next = NULL
            node->next = NULL;

            // Links the header and nodes together, puts the new nodes at the end
            if (*tweetList == NULL)
            {
                // if head is NULL, the list is empty and the header now points to the new node
                *tweetList = node;
            }
            else
            {
                // Reuses temp as the temp header
                tempF7 = *tweetList;

                // Makes tempF7 go to the end of the linked list
                while (tempF7->next != NULL)
                {
                    tempF7 = tempF7->next;
                }

                // Connects the node to the end of the linked list
                tempF7->next = node;
                tempF7 = tempF7->next;
            }
        }
    }

    // Closes the file
    fclose(file);
    
    printf("\nTweets imported!\n");
}