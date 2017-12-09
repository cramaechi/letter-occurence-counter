# Letter Occurence Counter
A program that reads in a line of text and outputs the number of words in the line and the number
of occurrences of each letter.

### Synopsis
This is a program that will read in a line of text and output the number of words in the line
and the number of occurences of each letter. A word is defined to be any string of letters
that is delimited at each end by either whitespace, a period, a comma, or the beginning or
end of the line. The input can only consist letters, whitespace, commas, and periods.

Uppercase and lowercase version of a letter are counted as the same letter.

The letters will be printed in alphabetical order.

## Setup
1. Download and install [Git](https://git-scm.com/downloads), if you don't already have it.

2. Open terminal and run the git clone command:

   ```
   $ git clone https://github.com/cramaechi/letter-occurence-counter.git
   ```
    or [download as ZIP](https://github.com/cramaechi/letter-occurence-counter/archive/master.zip).

3. Go to the project folder:

   ```
   $ cd letter-occurence-counter
   ```

4. Compile:

   ```
   $ make
   ```
   
## Usage
Run:

```
$ ./counter
```

Sample Output:
```
Enter sentence: Hello, my name is Chibuikem Amaechi.                                                                  
                                                                                                                      
6 words                                                                                                               
3 a                                                                                                                   
1 b                                                                                                                   
2 c                                                                                                                   
4 e                                                                                                                   
3 h                                                                                                                   
4 i                                                                                                                   
1 k                                                                                                                   
2 l                                                                                                                   
4 m                                                                                                                   
1 n                                                                                                                   
1 o                                                                                                                   
1 s                                                                                                                   
1 u                                                                                                                   
1 y 
```
