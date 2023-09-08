#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * this file contains functions that checks if a given input is valid 
 * valid double, int, char, etc. 
*/


/**
 * checks that the given input is valid by checking if only the appropriate number of arguments
 * were entered and character wasn't just a space
 * @param numArgsRead: the number of arguments read
 * @param numArgsNeed: the number of arguments needed
 * @return the boolean value if the format is valid or not
*/
bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
  bool formatIsGood = numArgsRead == numArgsNeed;
  char character;
  do{
    scanf("%c", &character); //45  bob  \n
		if(!isspace(character)){ //found a non whitespace character on the way to the end of the line
			formatIsGood = false;
		}
	}while(character != '\n'); //read characters until the end of the line
  return formatIsGood;
}


/**
 * checks if a given input is a valid character 
 * @param prompt: to be repeatedly asked
 * @return the valid the character
*/
char getValidChar(const char* prompt){
  char letter;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do{
    printf("%s", prompt);
    numArgsRead = scanf(" %c", &letter); // waffles 45\n
  }while(!isValidFormat(numArgsRead, numArgsNeeded));

  return letter;
}

/**
 * gets a valid in in the range of l and c
 * @param l the upperbound
 * @param c the lowerbound
 * @return the valid int
*/
int getValidInt(int l, int c){
  int num;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do{
    printf("Enter a column between %d and %d to play in: ", l, c);
    numArgsRead = scanf(" %d", &num); // waffles 45\n
  }while(!isValidFormat(numArgsRead, numArgsNeeded));

  return num;
}

/**
 * gets a valid double and keeps asking prompt if valid double isn't entered
 * @param prompt: the prompt to keep asking the user until they enter a valid double
 * @return the valid double
*/
double getValidDouble(const char* prompt){
  double num;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do{
    //printf("%s", prompt);
    numArgsRead = scanf(" %lf", &num); //waffles\n
  }while(!isValidFormat(numArgsRead, numArgsNeeded));

  return num;
}


/**
 * checks if a value is inbetween a given range
 * @param val: the value
 * @param lowerBound: the lowerbound of the range
 * @param upperBound: the upperBound of the range
 * @return the the boolean value of if the value is within the range
*/
bool inbetween(int val, int lowerBound, int upperBound){
    bool result = val >= lowerBound && val <= upperBound;
    //printf("isinbetwee: %d/n", result);
  return result;
}

/**
 * gets a valid integer in the given range
 * @param lowerBound: the lowerbound of the range
 * @param upperBound: the upperbound of the range
 * @return the valid integer
*/
int getValidIntInRange(int lowerBound, int upperBound){
  int num;
  do{
    //printf("Enter a column between %d and %d to play in: ", lowerBound, upperBound);
    num = getValidInt(lowerBound, upperBound);
    //printf("%d\n", num);
  }while(!(inbetween(num, lowerBound, upperBound)));

  return num;
}



/**
 * get a valid double that is atleast equal to or greater than the minimal value 
 * @param prompt: the prompt to keep asking 
 * @return the valid the double
*/
double getDoubleAtLeast(double min_val, const char* prompt){
  double num;
  do{
    num = getValidDouble(prompt);
  }while(!(num >= min_val));

  return num;
}