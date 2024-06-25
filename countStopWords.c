#include "headerA3.h"
#include "headerAddA3.h"

// Function 4: Finds, counts, shows the user how many stopwords there are in each tweet
void countStopWords(tweet * tweetList)
{
    // Declaring variables
    tweet * tempF4;
    char stopWords[25][5] = {"a","an","and","are","as","at","be","by","for","from","has","he","in","is","it","its","of","on","that","the","to","was","were","will","with"};
    char sentence[141];
    char *compare;
    int numStop, numTweets;
    int i, j;

    // Initializing variables
    tempF4 = tweetList;
    numStop = 0;
    numTweets = 0;
    i = 0;
    j = 0;
    
    printf("\n");

    while (tempF4 != NULL)
    {
        // Counts the number of tweets in the linked list
        numTweets = numTweets + 1;

        // Uses a new variable to keep the text lowercase
        strcpy(sentence, tempF4->text);
        for (i = 0; i < strlen(sentence); i++)
        {
            sentence[i] = tolower(sentence[i]);
        }
        
        for (i = 0; i < 25; i++)
        {
            // Sees if the keyword is in the sentence and puts it into "compare", if found, numStop++
            compare = strstr(sentence, stopWords[i]);

            if (compare && i!=0 && i!=1 && i!=2)
            {
                numStop = numStop + 1;
            }

            for (j = 0; j < strlen(sentence); j++)
            {
                if (i == 0)
                {
                    if (sentence[j] == 'a')
                    {
                        if ((sentence[j-1] <= 90 && sentence[j-1] >= 65)||(sentence[j+1] <= 122 && sentence[j+1] >= 97))
                        {
                            numStop = numStop + 0;
                        }
                        else
                        {
                            numStop = numStop + 1;
                        }
                    }
                }
                else if (i == 1)
                {
                    if (sentence[j] == 'a' && sentence[j+1] == 'n')
                    {
                        if ((sentence[j-1] <= 90 && sentence[j-1] >= 65)||(sentence[j+2] <= 122 && sentence[j+2] >= 97))
                        {
                            numStop = numStop + 0;
                        }
                        else
                        {
                            numStop = numStop + 1;
                        }
                    }
                }
                else if (i == 2)
                {
                    if (sentence[j] == 'a' && sentence[j+1] == 'n' && sentence[j+2] == 'd')
                    {
                        if ((sentence[j-1] <= 90 && sentence[j-1] >= 65)||(sentence[j+3] <= 122 && sentence[j+3] >= 97))
                        {
                            numStop = numStop + 0;
                        }
                        else
                        {
                            numStop = numStop + 1;
                        }
                    }
                }
            }

        }

        // Goes to the next node
        tempF4 = tempF4->next;
    }
    
    printf("\nAcross %d tweets, %d stop words were found.\n", numTweets, numStop);
}