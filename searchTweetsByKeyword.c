#include "headerA3.h"
#include "headerAddA3.h"

// Function 3: Search for the word in the linked list given
int searchTweetsByKeyword(tweet * tweetList)
{
    // Declaring variables
    tweet * tempF3;
    int num;
    int i;
    char keyword[141];
    char word1[141];
    char word2[141];
    char *compare;
    
    // Initializing variable
    tempF3 = tweetList;
    num = 0;
    i = 0;
    
    printf("Enter a keyword to search: ");
    scanf("%s", keyword);

    // Uses a new variable to keep the keyword lowercase
    strcpy(word2, keyword);
    for (i = 0; i < strlen(word2); i++)
    {
        word2[i] = tolower(word2[i]);
    }
    
    printf("\n");

    while (tempF3 != NULL)
    {
        // Uses a new variable to keep the text lowercase
        strcpy(word1, tempF3->text);
        for (i = 0; i < strlen(word1); i++)
        {
            word1[i] = tolower(word1[i]);
        }

        // Sees if the keyword is in the sentence and puts it into "compare", if found, prints out the match
        compare = strstr(word1, word2);

        if (compare)
        {
            printf("\nMatch found for '%s'; %s wrote: %s", keyword, tempF3->user, tempF3->text);
            num = 1;
            
            // Goes to the next node
            tempF3 = tempF3->next;
        }
        else
        {   
            // Goes to the next node
            tempF3 = tempF3->next;
        }
    }

    // returns 0 if there are no matches, returns 1 if there is a match
    return num;
}