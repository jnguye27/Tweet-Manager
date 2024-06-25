tweetManager: main.o createTweet.o displayTweets.o searchTweetsByKeyword.o countStopWords.o deleteTweet.o saveTweetsToFile.o loadTweetsFromFile.o sortID.o
	gcc -Wall -std=c99 main.o createTweet.o displayTweets.o searchTweetsByKeyword.o countStopWords.o deleteTweet.o saveTweetsToFile.o loadTweetsFromFile.o sortID.o -o tweetManager

sortID.o: sortID.c header.h
	gcc -Wall -std=c99 -c sortID.c   

loadTweetsFromFile.o: loadTweetsFromFile.c header.h
	gcc -Wall -std=c99 -c loadTweetsFromFile.c   

saveTweetsToFile.o: saveTweetsToFile.c header.h
	gcc -Wall -std=c99 -c saveTweetsToFile.c   

deleteTweet.o: deleteTweet.c header.h
	gcc -Wall -std=c99 -c deleteTweet.c   

countStopWords.o: countStopWords.c header.h
	gcc -Wall -std=c99 -c countStopWords.c   

searchTweetsByKeyword.o: searchTweetsByKeyword.c header.h
	gcc -Wall -std=c99 -c searchTweetsByKeyword.c   

displayTweets.o: displayTweets.c header.h
	gcc -Wall -std=c99 -c displayTweets.c   

createTweet.o: createTweet.c header.h
	gcc -Wall -std=c99 -c createTweet.c   

main.o: main.c header.h
	gcc -Wall -std=c99 -c main.c 

clean: 
	rm *.o tweetManager
