# CS50
Projects and problems solved during CS50 Harvard courses.

## Lecture 1 - C

### Practice Problems

#### Half file
- Supposing the user is going to a restaurant with another person, this program aims to calculate how much each one should pay, including bill, tax, and tip values.

#### Prime file
- This project aims to show the user (based on a chosen range) what Prime numbers exist.

### Lab 1

#### Population file
- This project was a lab activity whose goal was to preview how long it would take (in years) for a llama population chosen by the user to achieve the final population, also chosen by the user. We assumed that 1/3 of llamas of the start population are born annually, and 1/4 die.
- The project scope was divided into four parts:
  * Asking the user for a start population;
  * Asking the user for a final population;
  * Calculating the number of years required;
  * Printing the result on the screen;

### Problem set 1

#### Mario file
- Inspired by Mario games, this challenge's goal was to ask the user for an integer number that would result in a pyramid's height. 
- The project scope was divided into three parts:
  * Creating a formula to calculate the pyramid's height;
  * Creating a formula to calculate the number of spaces " " before each line;
  * Creating a formula to calculate the number of hashes on each line.
 
 #### Cash file
- This project aims to show how many coins are owed in change. 
- There are four coin types: quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢). 
- This algorithm receives a value greater than one and stores it. Then, it must calculate how many coins are necessary to cover the change owed. For instance:
  * If the input is 0, the output must be 0;
  * If the input is 4, the output must be 4 (i.e., four pennies);
  * If the input is 24, the output must be 6 (i.e., two dimes and four pennies).

## Lecture 2 - Arrays

### Practice Problems

#### Hours file
- This project aims to calculate, according to the user preferences (sum or average), how much time was spent over the weeks during the CS50 course.

#### No-vowels file
- This project aims to change every vowel - except 'u' - to numbers in a string, which is an array of characters.

#### Password file
- This project aims to evaluate if a password chosen by the user is valid or not valid and prints the result on the screen.
- A valid password must have:
  * At least one number;
  * At least one lowercase letter;
  * At least one uppercase letter;
  * At least one symbol.

### Lab 2

#### Scrabble file
 - This project is a game in which two players must choose a word. Each character in these words has several points according to how difficult it is to find it in a word (i.e., the 'a' value's is 1, and the 'z' value's is 10). 
- In the end, it's printed on the screen which player is the winner (or if they have a tie) according to the sum of the points of each symbol.
- Rules:
  * The letters 'A' and 'a' have the same number of points;
  * Non-alphabetical characters count as 0 points.

### Problem set 2

#### Readability file
- This project aims to create an algorithm that calculates a text grade reading level and prints the result on the screen.
- This way, it gets a string from the user, and uses the formula index = 0.0588 * L - 0.296 * S - 15.8, where:
  * L is the average number of letters per 100 words in the text, and
  * S is the average number of sentences per 100 words in the text.

- There are three possible results:
  * Before Grade 1;
  * Grade X (where x is a number between 2 and 15);
  * Grade 16+.
 
#### Bulbs file
- This project aims to get a message from the user, like "Hi!". After, it transforms each character used into an integer and converts the decimal number into binary.
- Then, the result is printed on the screen in bulbs emoji format. The number 1 is represented as an on light bulb, and the number 0 as an off one.
  * Each character must be represented in a different line.
 
## Lecture 3 - Algorithms

### Practice Problems

#### Atoi file
 - This project aims to create an algorithm that converts strings into an integer using a recursive function.

#### Temps file
- This project aims to create an algorithm that sorts an array of cities' temperatures in descending order.
- The final result is printed out on the screen.

#### Max file
- This program asks the user for the number of integers he wants to compare and which they are. Then, it prints on the screen the biggest one.

#### Snackbar file
- At this project, a menu of snacks is printed on the screen. Then, the user is asked to choose some foods or drinks, like Fries or soda. In the end, the foods chosen's costs are summed and printed on the screen as the final cost.
  * For this purpose, it used a linear search algorithm.
  * Items that are not on the menu can't be summed.

### Problem set 3

#### Plurality file
- This program aims to calculate the winner of a plurality election, in which voters can choose only one candidate.
- For starting the program, it is necessary to use candidates' names as argument values. Then, the user must define the number of voters. Each voter chooses one candidate.
- Finally, the winner's (or winners', if it is tied) name is printed on the screen.

#### Runoff file
- This program aims to calculate the winner of a runoff election, in which voters can choose candidates in their preference order.
- For starting the program, it is necessary to use candidates' names as argument values. Then, the user must define the number of voters. Each voter puts each candidate in a rank of preference.
- The program reads each vote and organizes the results in a matrix of integer values (preferences[i][j], in which i is the voter index, and j is the candidate index).
- A candidate receives a vote when he is the voter's first option. If the candidate has already been eliminated, the voter's second option is chosen instead, and so on.
- The candidate with the lower number of votes is eliminated in every loop.
- The program ends when there is a winner or when it is tied, and the result is printed on the user's screen.

## Lecture 4 - Memory

### Practice Problems

#### License and License_matrix files

- It's a simple program for practice using functions malloc and free from C. It reads eight sequences of seven characters from a .txt file and prints it on the screen.
  * license.c file does it using malloc;
  * license_matrix.c file does it using a matrix.
