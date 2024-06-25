#include "headerA3.h"
#include "headerAddA3.h"

// Function 1: Creates a tweet
tweet * createTweet(tweet * tweetList)
{
    // Declaring variables
    struct microtweet * node; 
    tweet * tempF1;
    int i; 
    int truth;

    // Initializing variables & Allocating space
    node = malloc(sizeof(struct microtweet));
    tempF1 = tweetList;
    i = 0;
    truth = 0;
    node->id = 0;
    node->next = NULL;

    // Obtains the username and stores it into the new node -> user + dummy proofing
    printf ("\nEnter a username: ");
    scanf(" %[^\n]s", node->user);
    while (truth == 0)
    {
        if ((strlen(node->user) > 0) && (strlen(node->user) <= 51))
        {
            truth = 1;
        }
        else
        {
            printf ("\nInvalid input, try again.\n");
            scanf(" %[^\n]s", node->user);
        }
    }

    // Resets truth value
    truth = 0;

    // Obtains the user's text (until it hits a \n) and stores it into the new node -> text + dummy proofing
    printf ("\nEnter the user's tweet: ");
    scanf(" %[^\n]s", node->text);
    while (truth == 0)
    {
        if ((strlen(node->text) > 0) && (strlen(node->text) <= 141))
        {
            truth = 1;
        }
        else
        {
            printf ("\nInvalid input, try again.\n");
            scanf(" %[^\n]s", node->text);
        }
    }

    // Obtains the user's id and stores it into the new node -> id
    for (i = 0; i < strlen(node->user); i++)
    {
        node->id = node->id + node->user[i];
    }
    node->id = node->id + strlen(node->text);
    
    // If the userid already exists, add random numbers (1-999) to generate a unique id
    while (tempF1 != NULL)
    {
        if (tempF1->id == node->id)
        {
            // srand creates a random seed that allows for a random number every time
            srand(time(0));
            node->id = node->id + rand()%999+1;

            // resets the linked list reading
            tempF1 = tweetList;
        }
        else
        {
            tempF1 = tempF1->next;
        }
    }

    printf ("\n\nYour computer-generated userid is: %d.\n", node->id);

    // Links the header and nodes together, puts the new nodes at the end
    if (tweetList == NULL)
    {
        // if head is NULL, the list is empty
        tweetList = node;
    }
    else
    {
        // Temp points to header
        tempF1 = tweetList;

        // Makes tempF1 go to the end of the linked list
        while (tempF1->next != NULL)
        {
            tempF1 = tempF1->next;
        }

        // Connects the node to the end of the linked list
        tempF1->next = node;
    }

    /* 
    This adds nodes to the beginning of the linked list:
    node->next = tweetList;
    tweetList = node;
    */

    return (tweetList);
}