/*
Program: Tweet Manager
Creator: Jessica Nguyen
Due Date: 2022-03-31 
*/

#include "header.h"

int main (int argc, char * argv[]) 
{
    // Declaring all variables, (tweetList = header)
    int choice, num;
    tweet * tweetList = NULL;
    tweet * tempMain; // for freeing

    // The choice inputted = function # activated
    do {
        printf ("\n-- Here is the menu --\n\n");
        printf ("1. Create a new tweet\n");
        printf ("2. Display tweets\n");
        printf ("3. Search a tweet (by keyword)\n");
        printf ("4. Find how many words are 'stop words'\n");
        printf ("5. Delete the nth tweet\n");
        printf ("6. Save tweets to a file\n");
        printf ("7. Load tweets from a file\n");
        printf ("8. Sort the given linked list on userid\n");
        printf ("9. Exit\n");
        
        printf ("\nChoose a menu option: ");
        scanf ("%d", &choice);
        printf ("\n");
        
        switch (choice) {
            case 1:
                tweetList = createTweet(tweetList);
                break;

            case 2:     
                displayTweets(tweetList);
                break;

            case 3:
                num = searchTweetsByKeyword(tweetList);
                if (num == 0)
                {
                    printf("\nNo matches found.\n");
                }
                else
                {
                    printf("\nAll matches found.\n");
                }
                break;

            case 4:
                countStopWords(tweetList);
                break;

            case 5:
                deleteTweet(&tweetList);
                break;

            case 6:
                saveTweetsToFile(tweetList);
                break;

            case 7:
                loadTweetsFromFile(&tweetList);
                break;

            case 8:
                sortID (&tweetList);
                break;

            case 9:
                printf ("Menu Exited.\n");

                // Frees the linked list before exiting the program
                while (tweetList != NULL)
                {
                    tempMain = tweetList;
                    tweetList = tweetList->next;
                    free (tempMain);
                }

                return 0;
            
            default: printf ("That is an invalid choice\n");
        }
    } while (choice != 9);
   return 0;
}
