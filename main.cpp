//A program that counts the # of words and letters in an input string.
#include <iostream>
#include <cstring>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;

void input(char s[], int size);
//Reads a line of input from the keyboard.

int wordCount(char s[]);
//Returns the # of words in C-string s.

void countLetter(char s[], char letters[], int occurences[], int& numberUsed);
//Precondition: C-string s non-empty. Array letters and occurences are 
//empty.
//Postcondition: letters array has been filled with all the letters in 
//C-string s. occurences array has been filled with all numbers 
//corresponding to the number of occurences for each letter in array 
//letters.

void mergeSort(char letters[], int occurences[], int startPos, int endPos);
//Precondition: letters array is non-empty.
//Postcondition: Sorts the contents of letters in alphabetical order.

void output(int wordCount, char letters[], int occurences[], int numberUsed);
//Prints out the number of words and occurences of letters in the input
//string.

const int MAX = 65;

int main()
{
    //Define a c-string of length 64.
    char s[MAX];

    //Reads a line of text into c-string s.
    input(s, MAX);

    //Counts the number of words in c-string s.
    int count = wordCount(s);

    int occurences[MAX];
    char letters[MAX];
    int numberUsed = 0;

    //Counts the number of letters in c-string s.
    countLetter(s, letters, occurences, numberUsed);

    //Sorts array letters in ascending order.
    mergeSort(letters, occurences, 0, numberUsed - 1);

    //Prints out the number of words and the number of the number of occurences
    //of each letter in c-string s.
    output(count, letters, occurences, numberUsed);

    return 0;
}

void input(char s[], int size)
{
    cout<<"Enter sentence: ";
    cin.getline(s, size);
    cout<<endl;
}

int wordCount(char s[])
{
    int count = 0;
    char copy[65];
    strcpy(copy, s);
    char *word = strtok(copy, " .,");

    while(word != NULL)
    {
        count += 1;
        word = strtok(NULL, " .,");
    }

    return count;
}

void countLetter(char s[], char letters[], int occurences[], int& numberUsed)
{
    int index = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isalpha(s[i]))
        {
            letters[index] = tolower(s[i]);
            occurences[index] = 1;
            numberUsed += 1;
            for (int j = strlen(s) - 1; j > i; j--)
            {
                if (tolower(s[i]) == tolower(s[j]))
                {
                    occurences[index] += 1;
                    for (int k = j; k <= strlen(s); k++)
                        s[k] = s[k + 1];
                }
            }
            index++;
        }
    }
}

void mergeSort(char letters[], int occurences[], int startPos, int endPos)
{
    if ((endPos - startPos) <= 1)
        return;

    mergeSort(letters, occurences, startPos, (startPos + endPos)/2);
    mergeSort(letters, occurences, ((startPos + endPos)/2) + 1, endPos);
    for (int i = 1; i <= endPos; i++)
    {
        for (int j = i; j > 0 && letters[j] < letters[j - 1]; j--)
        {
            int temp = letters[j - 1], temp2 = occurences[j - 1];
            letters[j - 1] = letters[j];
            occurences[j - 1] = occurences[j];
            letters[j] = temp;
            occurences[j] = temp2;
        }
    }
}
void output(int wordCount, char letters[], int occurences[], int numberUsed)
{
    cout<<wordCount<<" words\n";
    for (int i = 0; i < numberUsed; i++)
        cout<<occurences[i]<<" "<<letters[i]<<endl;
    cout<<endl;
}
