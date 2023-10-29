#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libpynq.h>

#define MAXWORDS 12
#define MAXLEN 20

#define DISPLAY_WIDTH 240
#define DISPLAY_HEIGHT 240

 
extern void predefined_printWordList(char *wordList[MAXWORDS]);
extern void predefined_insertWord(char *wordList[MAXWORDS], char *word);
extern void predefined_shareWord(char *wordList[MAXWORDS], char *word);
extern void predefined_deleteWord(char *wordList[MAXWORDS], char *word);
extern void predefined_displayWordList(display_t *display, char *wordList[MAXWORDS]);

void printWordList(char *wordList[MAXWORDS]);
void insertWord(char *wordList[MAXWORDS], char *word);
void swapWords(char *wordList[MAXWORDS], char *word1, char *word2);
void findWord(char **wordList, char *word, int *index);
void longestWord(char *wordList[MAXWORDS], char **word);
void changeVowels(char *wordList[MAXWORDS]);
void appendWords(char *wordList[MAXWORDS], char *word1, char *word2);
void freeWordList(char *wordList[MAXWORDS]);
void shareWord(char *wordList[], char *word);
void deleteWord(char *wordList[MAXWORDS], char *word);

int main()
{
    // pynq_init();
    // color_leds_init_pwm();
    // display_t display;
    // display_init(&display);
    // displayFillScreen(&display, RGB_BLACK);

    char cmd;
    char *wordList[MAXWORDS] = {NULL};
    int foundIndex;
    char word[MAXLEN + 1];
    char word1[50];
    char word2[50];
    char *longest = NULL;

    do
    {
        printf("Command? ");
        scanf(" %c", &cmd);
        switch (cmd)
        {
        case 'q': // quit program
            printf("Bye!\n");
            freeWordList(wordList);
            break;
        case 'p': // print word list
            printWordList(wordList);
            break;
        case 'i': // insert word
            printf("Word? ");
            scanf("%s", word);
            insertWord(wordList, word);
            break;
        case 'f': // find word
            printf("Word? ");
            scanf("%s", word);
            findWord(wordList, word, &foundIndex);
            printf("The index is %d\n", foundIndex);
            break;
        case 'w': // swap words
            printf("Words? ");
            scanf("%s %s", word1, word2);
            swapWords(wordList, word1, word2);
            break;
        case 'l': // longest word
            longestWord(wordList, &longest);
            if (longest == NULL)
            {
                printf("No words\n");
            }
            else
            {
                printf("The longest word is %s\n", longest);
            }
            break;
        case 'v': // change vowels
            changeVowels(wordList);
            break;
        case 'a': // append words
            printf("Words? ");
            scanf("%s %s", word1, word2);
            appendWords(wordList, word1, word2);
            break;
        case 's': // insert a word in the list, sharing the space
            printf("Word? ");
            scanf("%s", word);
            shareWord(wordList, word);
            break;
        case 'd': // delete a word from the list
            printf("Word? ");
            scanf("%s", word);
            deleteWord(wordList, word);
            break;
        case 'D': // display the list
            break;

        default:
            printf("Unknown command '%c'\n", cmd);
            break;
        }
    } while (cmd != 'q');

    // pynq_destroy();
    return 0;
}

void printWordList(char *wordList[MAXWORDS])
{
    int i, j, k, l;

    for (i = 0; i < MAXWORDS && wordList[i] != NULL;)
    {
        printf("\"%s\" is referenced from entries", wordList[i]);
        printf(" %d", i);

        // Count references and print them
        int refCount = 1; // Starts with 1 for itself
        for (j = i + 1; j < MAXWORDS && wordList[j] != NULL && wordList[j] == wordList[i]; j++)
        {
            printf(" %d", j);
            refCount++;
        }
        printf("\n");

        // If a word is referenced multiple times, print it as many times as the ref count
        for (k = 1; k < refCount; k++)
        {
            printf("\"%s\" is referenced from entries", wordList[i]);
            for (l = i; l < i + refCount; l++)
            {
                printf(" %d", l);
            }
            printf("\n");
        }

        i += refCount; // Move to the next distinct word
    }
}

void insertWord(char *wordList[MAXWORDS], char *word) {
    // Check if the list is full
    int lastSlot = -1, i;
    for ( i = 0; i < MAXWORDS; i++) {
        if (wordList[i] == NULL) {
            lastSlot = i;
            break;
        }
    }

    if (lastSlot == -1) {
        printf("List is full\n");
        return;
    }

    // Allocate space for the new word
    char *newWord = malloc(strlen(word) + 1);
    if (!newWord) {
        printf("Memory allocation error\n");
        return;
    }
    strcpy(newWord, word);

    // Find the position to insert the word in the sorted list
    int pos = 0;
    for ( i = 0; i < lastSlot; i++) {
        if (strcmp(wordList[i], newWord) > 0) {
            pos = i;
            break;
        }
        pos = i + 1;
    }

    // Shift other words down to make space
    for ( i = lastSlot; i > pos; i--) {
        wordList[i] = wordList[i - 1];
    }

    // Insert the new word
    wordList[pos] = newWord;
}

void findWord(char **wordList, char *word, int *index)
{
    int i;

    *index = -1; // initially we assume the word is not in the list

    // for (i = MAXWORDS - 1; i >= 0; i--)
    for (i = 0; i <= MAXWORDS - 1; i++)
    {
        if (wordList[i] != NULL && strcmp(wordList[i], word) == 0)
        {
            *index = i;
            break;
        }
    }
}

void swapWords(char *wordList[MAXWORDS], char *word1, char *word2)
{
    int index1 = -1, index2 = -1, i;

    // Find the indices of the two words in the list
    for (i = 0; i < MAXWORDS && wordList[i] != NULL; i++)
    {
        if (strcmp(wordList[i], word1) == 0)
        {
            index1 = i;
        }
        if (strcmp(wordList[i], word2) == 0)
        {
            index2 = i;
        }
    }

    // If both words are found, swap them
    if (index1 != -1 && index2 != -1)
    {
        char *temp = wordList[index1];
        wordList[index1] = wordList[index2];
        wordList[index2] = temp;
    }
    else
    {
        printf("Word(s) not in list\n");
    }
}

void longestWord(char *wordList[MAXWORDS], char **word)
{
    int i;
    int maxLength = 0;
    *word = NULL; // Set the word to NULL initially

    for (i = 0; i < MAXWORDS; i++)
    {
        if (wordList[i] != NULL)
        {
            int currentLength = strlen(wordList[i]);
            // If the current word has a length greater than the maxLength
            // or if the current word has the same length but is at a higher index,
            // then update *word and maxLength
            if (currentLength > maxLength || (currentLength == maxLength && *word != NULL))
            {
                *word = wordList[i];
                maxLength = currentLength;
            }
        }
    }
}

void changeVowels(char *wordList[MAXWORDS])
{
    int i, j;
    for (i = 0; i < MAXWORDS && wordList[i] != NULL; i++)
    {
        for (j = 0; wordList[i][j] != '\0'; j++)
        {
            switch (wordList[i][j])
            {
            case 'a':
                wordList[i][j] = 'e';
                break;
            case 'e':
                wordList[i][j] = 'a';
                break;
            case 'o':
                wordList[i][j] = 'u';
                break;
            case 'u':
                wordList[i][j] = 'o';
                break;
            }
        }
    }
}

void appendWords(char *wordList[MAXWORDS], char *word1, char *word2)
{
    int index1, index2, i, lw1, lw2;

    findWord(wordList, word1, &index1);
    findWord(wordList, word2, &index2);

    if (index1 == -1 || index2 == -1)
    {
        printf("Word(s) not in list\n");
        return;
    }

    lw1 = strlen(word1); // length of word1
    lw2 = strlen(word2); // length of word2

    char *concatenation = (char *)malloc(lw1 + lw2 + 2); //+2 for '+' and '\0' chars.

    for (i = 0; i < lw1; i++)
    {
        concatenation[i] = word1[i];
    }

    concatenation[lw1] = '+';

    for (i = 0; i < lw2; i++)
    {
        concatenation[lw1 + i + 1] = word2[i];
    }

    concatenation[lw1 + lw2 + 1] = '\0';

    free(wordList[index1]);
    for (i = index1; i < MAXWORDS - 1; i++)
    {
        wordList[i] = wordList[i + 1];
        if (wordList[i] == NULL)
        {
            break;
        }
    }

    findWord(wordList, word2, &index2); //get the new index after shift
    free(wordList[index2]); //empty wordlist's index2 indice.
    for (i = index2; i < MAXWORDS - 1; i++) 
    {
        wordList[i] = wordList[i + 1];
        if (wordList[i] == NULL)
        {
            break;
        }
    }

    free(wordList[MAXWORDS - 1]);

    insertWord(wordList, concatenation);

    free(concatenation);
}

void freeWordList(char *wordList[MAXWORDS])
{
    int i;
    for (i = 0; i < MAXWORDS; i++)
    {
        if (wordList[i] != NULL)
        {
            free(wordList[i]);
        }
    }
}

void shareWord(char *wordList[MAXWORDS], char *word)
{
    int index, i;
    index = -1;
    findWord(wordList, word, &index);

    if (index == -1)
    {
        // Word is not in the list, insert normally
        insertWord(wordList, word);
    }
    else
    {

        if (wordList[MAXWORDS - 1] != NULL)
        {
            return;
        }

        // Word is already in the list
        // Shift all elements from 'index' one position to the up
        for (i = MAXWORDS - 2; i >= index; i--)
        {
            wordList[i + 1] = wordList[i];
        }
        // Point the new entry to the same memory location as the first occurrence of the word
        wordList[index] = wordList[index + 1];
    }
}

void deleteWord(char *wordList[MAXWORDS], char *word)
{
    int index = -1;
    int isShared = 0; // pretend that the word is not shared
    int i;
    // Find the last occurrence of the word in the list
    findWord(wordList, word, &index);
    if (index == -1)
    {
        printf("Word not found\n");
        return;
    }

    // If the word is not shared, free its memory

    for (i = 0; i < index; i++)
    {
        if (wordList[i] && strcmp(wordList[i], word) == 0)
        {
            isShared = 1;
            break;
        }
    }

    if (isShared == 0)
    {
        free(wordList[index]);
    }

    // Shift remaining words to the left
    for (i = index; i < MAXWORDS - 1; i++)
    {
        wordList[i] = wordList[i + 1];
    }
    wordList[MAXWORDS - 1] = NULL; // Reset last word to NULL
}
