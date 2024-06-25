# Tweet-Manager
Description:  
Can create, delete, display, sort, search, save, and load tweets from a file.  
  
To compile:  
make  
  
To run:  
./nguyenJessicaA3  
  
Known limitations:  
1) Although I've added a while loop to try and fix inputs that are longer than text[141], displaying it causes it to crash my program.  
2) Cannot properly make the stopWord function, for example, text[141] = "and" = 3 because the program reads it as "and", "an", and "a". I've tried adding if statements and ' ', '-', '\0', and '\n' at the beginning and at the end of the stopword but it would make my program unreasonably long for 25 stop words.  
  
Improvements:  
1) For my first limitation, perhaps I can allocate memory instead of having it statically given and try to reallocate it (if it was an option).  
2) Search for more ways to dummy-proof it and improve my code by making it have fewer lines and be more efficient.  
