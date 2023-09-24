#include <libpynq.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

#define LENGTH 30

void readLine(char str[], int length)
{
  char ch;
  int j = 0, i = 0;
  for (i = strlen(str); i < length; i++)
  {
    str[i] = '\0';
  }
  while (((ch = getchar()) != '\n') && j < length - 1)
  {
    str[j] = ch;
    j++;
  }
  while ((ch != '\n') && j >= length - 1)
  {
    ch = getchar();
  }
  str[j] = '\0';
}

void printArray(char a[], int length)
{
  int i;
  printf("[");
  for (i = 0; i < length; i++)
  {
    if (a[i] == '\0')
    {
      printf("\\0");
    }
    else if (a[i] == '\n')
    {
      printf("\\n");
    }
    else
    {
      printf("%c", a[i]);
    }
    if (i < length - 1)
    {
      printf(",");
    }
  }
  printf("]\n");
}

int isconsonant(char c)
{
  c = toupper(c);
  return (int)(c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U');
}

int isvowel(char c)
{
  c = toupper(c);
  return (int)(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int is0to9(char c)
{
  return (int)isdigit(c);
}

void printChar(char c)
{
  putchar(c);
  int r = 0, g = 0, b = 0;
  fflush(NULL);
  sleep_msec(200);
  if (isconsonant(c) == 1)
  {
    r = 255;
    g = 0;
    b = 0;
  }
  else if (isvowel(c) == 1)
  {
    r = 0;
    g = 0;
    b = 255;
  }
  else if (is0to9(c) == 1)
  {
    r = 0;
    g = 255;
    b = 0;
  }
  else if (c == '\0')
  {
    r = 255;
    g = 255;
    b = 255;
  }
  color_led_onoff(r, g, b);
  sleep_msec(500);
  color_led_onoff(0, 0, 0);
}

void printString(char s[])
{

  printf("The current string is: ");
  int x = 0;
  while (1)
  {
    if (x == 0)
    {
      printf("\"");
    }
    if (s[x] == '\0')
    {
      printf("\"");
      break;
    }
    else if (s[x] == '\n')
    {
      printf("\n");
    }
    else
    {
      printChar(s[x]);
    }
    x++;
  }
  printf("\n");
}

int findFirstOccurrence(char str[], char aChar)
{
  int i;
  int index = -1;
  for (i = 0; i < strlen(str); i++)
  {
    if (str[i] == aChar)
    {
      index = i;
      break;
    }
  }
  return index;
}

int readInt(char str[], int length)
{
  int i;
  int result = 0;
  if (length == 0 || !isdigit(str[0]))
  {
    return -1;
  }

  for (i = 0; i < length && isdigit(str[i]); i++)
  {
    result = result * 10 + (str[i] - '0');
  }

  return result;
}

void insertChar(char str[], char aChar, int index)
{
  int len = strlen(str), i;

  if (index > len || len >= LENGTH - 1)
  {
    return;
  }

  for (i = len; i >= index; i--)
  {
    str[i + 1] = str[i];
  }
  str[index] = aChar;
}

void replaceChars(char str[], char fromString[], char toChar)
{
  int i, j;

  for (i = 0; str[i] != '\0'; i++)
  {
    for (j = 0; fromString[j] != '\0'; j++)
    {
      if (str[i] == fromString[j])
      {
        str[i] = toChar;
        break;
      }
    }
  }
}

int main(void)
{
  pynq_init();
  color_leds_init_pwm();

  char string0[] = "Oooooh, 0a0a0a0a0a, --x--x--x--, what is happening now?\n";
  printString(&string0[0]);

  char inputString[LENGTH];
  char currString[LENGTH] = {'\0'};
  char fromString[LENGTH] = {'\0'};
  char aChar[LENGTH] = {'\0'};
  char toChar[LENGTH] = {'\0'};
  char charToInsert;
  int indexToInsert;
  int firstOccurence;

  do
  {
    printf("Command? ");
    readLine(inputString, LENGTH);
    switch (inputString[0])
    {
    case 'p':
      printString(currString);
      break;
    case 'a':
      printArray(currString, LENGTH);
      break;
    case 's':
      printf("Please enter a string? ");
      scanf("%[^\n]", &currString); //gets(currString);
      printString(currString);
      break;
    case 'o': // task 10
      printf("Find first occurrence of which character? ");
      readLine(aChar, LENGTH);
      firstOccurence = findFirstOccurrence(currString, aChar[0]);
      printf("The first occurrence of '%c' is at index %d\n",
             aChar[0], firstOccurence);
      break;

    case 'i': // task 12

      printf("Insert which character? ");
      readLine(inputString, LENGTH);
      charToInsert = inputString[0];

      printf("At what index? ");
      readLine(inputString, LENGTH);
      indexToInsert = readInt(inputString, LENGTH);

      insertChar(currString, charToInsert, indexToInsert);

      break;

    case 'r': // task 13
      printf("Replace which characters? ");
      readLine(fromString, LENGTH);

      printf("with which character? ");
      readLine(toChar, LENGTH);

      replaceChars(currString, fromString, toChar[0]);
      break;

    case 'q':
      printf("Bye!\n");
      break;
    default:
      printf("Unknown command '%c'\n", inputString[0]);
      break;
    }

  } while (inputString[0] != 'q');

  // do {
  // printf("String? ");
  // readLine(inputString, LENGTH);
  // printArray(inputString, LENGTH);
  // printString(inputString);
  // } while(1);

  leds_destroy();
  pynq_destroy();
}
