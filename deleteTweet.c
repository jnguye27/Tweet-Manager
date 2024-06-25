#include "headerA3.h"
#include "headerAddA3.h"

// Function 5: Deletes a tweet that the user chooses
void deleteTweet(tweet ** tweetList)
{
    // Declaring variables
    tweet * tempF5;
    tweet * tempF5Before;
    int totalTweets, tweetCounter;
    int input, truth;

    // Initializing variables 
    tempF5 = *tweetList;
    tempF5Before = tempF5;
    totalTweets = 0;
    tweetCounter = 0;
    truth = 0;

    // Counts the number of tweets there are in the linked list
    while (tempF5 != NULL)
    {
        totalTweets = totalTweets + 1;

        // Goes to the next node
        tempF5 = tempF5->next;
    }

    // Puts temp back to the beginning (header)
    tempF5 = *tweetList;
    
    if (totalTweets == 0)
    {
        // If there are no tweets to delete, go back to main
        printf ("There are no tweets to delete.\n");
        return;
    }
    else if (totalTweets == 1)
    {
        // If there is only 1 tweet, delete that one and go back to main
        printf ("The tweet has been deleted.\n");

        // Changes to the next head (should be NULL) and frees the old one
        *tweetList = tempF5->next;
        free(tempF5);

        return;
    }
    else
    {
        // Else, deletes the tweet that the user desires (dummy proofing input aswell)
        printf ("\nCurrently there are %d tweets.\n", totalTweets);
        printf ("\nWhich tweet do you wish to delete - enter a value between 1 and %d: ", totalTweets);
        scanf ("%d", &input);

        while (truth == 0)
        {
            if (input >= 1 && input <= totalTweets)
            {
                truth = 1;
            }
            else
            {
                printf ("\nInvalid input, try again.\n");
                scanf ("%d", &input);
            }
        }
    }

    while (tempF5 != NULL)
    {
        // Counts the tweet # in the linked list
        tweetCounter = tweetCounter + 1;

        // If the tweet # = input # then frees/deletes that node and connect the prev. node to the next node
        if (tweetCounter == input)
        {
            if (input == 1)
            {
                // Changes to the next head and frees the old node
                *tweetList = tempF5->next;
                
                printf ("\nTweet %d deleted. There are now %d tweet(s) left.\n", tempF5->id, totalTweets);
                
                free(tempF5);

                return;
            }
            else
            {
                tempF5Before->next = tempF5->next;

                totalTweets = totalTweets - 1;

                printf ("\nTweet %d deleted. There are now %d tweet(s) left.\n", tempF5->id, totalTweets);

                free(tempF5);

                return;

            }
        }
        else
        {
            // Goes to the next node 
            tempF5Before = tempF5;
            tempF5 = tempF5->next;
        }
    }
}