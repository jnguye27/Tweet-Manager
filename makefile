nguyenJessicaA3: mainA3.o createTweet.o displayTweets.o searchTweetsByKeyword.o countStopWords.o deleteTweet.o saveTweetsToFile.o loadTweetsFromFile.o sortID.o
	gcc -Wall -std=c99 mainA3.o createTweet.o displayTweets.o searchTweetsByKeyword.o countStopWords.o deleteTweet.o saveTweetsToFile.o loadTweetsFromFile.o sortID.o -o nguyenJessicaA3

sortID.o: sortID.c headerA3.h headerAddA3.h
	gcc -Wall -std=c99 -c sortID.c   

loadTweetsFromFile.o: loadTweetsFromFile.c headerA3.h headerAddA3.h
	gcc -Wall -std=c99 -c loadTweetsFromFile.c   

saveTweetsToFile.o: saveTweetsToFile.c headerA3.h headerAddA3.h
	gcc -Wall -std=c99 -c saveTweetsToFile.c   

deleteTweet.o: deleteTweet.c headerA3.h headerAddA3.h
	gcc -Wall -std=c99 -c deleteTweet.c   

countStopWords.o: countStopWords.c headerA3.h headerAddA3.h
	gcc -Wall -std=c99 -c countStopWords.c   

searchTweetsByKeyword.o: searchTweetsByKeyword.c headerA3.h headerAddA3.h
	gcc -Wall -std=c99 -c searchTweetsByKeyword.c   

displayTweets.o: displayTweets.c headerA3.h headerAddA3.h
	gcc -Wall -std=c99 -c displayTweets.c   

createTweet.o: createTweet.c headerA3.h headerAddA3.h
	gcc -Wall -std=c99 -c createTweet.c   

mainA3.o: mainA3.c headerA3.h headerAddA3.h
	gcc -Wall -std=c99 -c mainA3.c 

clean: 
	rm *.o nguyenJessicaA3 mainA3.o createTweet.o displayTweets.o searchTweetsByKeyword.o countStopWords.o deleteTweet.o saveTweetsToFile.o loadTweetsFromFile.o sortID.o