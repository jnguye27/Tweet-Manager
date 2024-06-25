#include "header.h"
#include "headerAddOn.h"

// Function 2: Displays all the tweets in the linked list given
void displayTweets(tweet * tweetList)
{
    // Declaring a temp variable, Needed to traverse through the link list multiple times
    tweet * tempF2;

    // Initializing variable
    tempF2 = tweetList;

    // Displays the tweets within tweetList
    while (tempF2 != NULL)
    {
        printf("%d: Created by %s: %s\n", tempF2->id, tempF2->user, tempF2->text);
        tempF2 = tempF2->next;
    }
}
