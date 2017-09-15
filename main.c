/******************************************************************************
 *Michael Servilla
 *
 *This file is to read sudoku input from the standard input stream, echo the
 *input, verify that it is valid, and calculate and print out a solution if it
 *exist or state "no solution" if it does not exist.
 *****************************************/

#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 81
#define WIDTH 9

char puzzArray[MAX_SIZE];
int character;
int charCount;
int errorFlag;

int main()
{
  while((character = getchar()) != EOF)
  {
    putchar(character);
    if (character == '\n')
    {
      printf("The charCount is %d\n", charCount);
      if (errorFlag == 1 || charCount  != MAX_SIZE)
      {
        printf("Error\n\n");
      }
      else
      {
        printf("\n");
      }
      errorFlag = 0;
      charCount = -1;
    }
    if (charCount < MAX_SIZE)
    {
      puzzArray[charCount] = (char) character;
    }
    if (!(isdigit(character) || character == '.'))
    {
      errorFlag = 1;
    }
    errorFlag = 0;
    charCount++;
  }
  return 0;
}