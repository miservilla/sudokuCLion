/******************************************************************************
 *Michael Servilla
 *
 *This file is to read sudoku input from the standard input stream, echo the
 *input, verify that it is valid, and calculate and print out a solution if it
 *exist or state "no solution" if it does not exist.
 *****************************************************************************/

#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 81
#define WIDTH 9

int inputTest(char puzzArray[]);
void cleanArray(char puzzArray[]);

char puzzArray[MAX_SIZE];
char tmpChar;
int puzzChar;
int charCount;
int errorFlag;
int dupCount;
int i;
int j;
int k;


int main()
{
  while((puzzChar = getchar()) != EOF)
  {
    putchar(puzzChar);
    if (puzzChar == '\n')
    {
      inputTest(puzzArray);
      if (errorFlag == 1 || charCount  != MAX_SIZE)
      {
        printf("Error\n\n");
      }
      else
      {
        printf("\n");
      }
      for (i = 0; i < MAX_SIZE; ++i)
      {
        if (i % WIDTH == 0)
        {
          printf("\n");
        }
        printf(" %c", puzzArray[i]);
      }
      cleanArray(puzzArray);
      printf("\n\n\n");
      errorFlag = 0;
      charCount = -1;
    }
    if (charCount < MAX_SIZE)
    {
      puzzArray[charCount] = (char) puzzChar;
    }
    if (!(isdigit(puzzChar) || puzzChar == '.'))
    {
      errorFlag = 1;
    }
    errorFlag = 0;
    charCount++;
  }
  return 0;
}
int inputTest(char puzzArray[])
{
  for (i = 0; i < 80; i += 9)
  {
    for (j = 0; j < 8; ++j)
    {
      dupCount = 0;
      tmpChar = puzzArray[i + j];
      for (k = j; k < 9; ++k)
      {
        if (tmpChar == '.')
        {
          break;
        }
        if (puzzArray[i + k] == tmpChar )
        {
          dupCount++;
          if (dupCount > 1)
          {
            errorFlag = 1;
            return errorFlag;
          }
        }
      }
    }
  }
  return errorFlag;
}
void cleanArray(char puzzArray[])
{
  for (i = 0; i < MAX_SIZE; ++i)
  {
    puzzArray[i] = ' ';
  }
}