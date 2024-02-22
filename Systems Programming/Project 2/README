Nihar Biradar nb769
Tyler Uhl tbu3

We use arraylists for both the structures that hold all of the words and the words itself.
Each struct, called WordCount, contains a char* word that stores the word an int that stores the occurences of that word.
We run a for loop to iterate through each argument passed to the program.
If the argument is a file, we scan it and move on to the next argument.
If the argument is a directory, we scan it like it is an argument, if it is a file we scan it, if it is a directory we recursively call the function itself.
We used perror() to print if an argument is not a readable file or directory or if a path was given that doesn't exist.
Our file scanning process used a triple pointer. These three pointers iterate through the file and check for valid characters and ' and -.
Becuase our structures are arraylists, if they reach a maximum size, they are realloced with a size that increases by the initial value.
We use global vars to keep track of the structure maximum size.
We use qsort to sort the data and print everything out using write.
Then we create a buffer that adds the : x for the number of occurences of the word. We print using write().