# Kaprekar's Routine (C++)

A console program that applies Kaprekar's routine to a 4-digit number and shows every step until it reaches 6174. Built with a teammate (Ricardo Villarreal) for my Algorithm Analysis and Design course at Universidad de Monterrey (UDEM).

## How the routine works

1. Sort the digits in descending order to get the largest number.
2. Sort them in ascending order to get the smallest number.
3. Subtract the two (keeping leading zeros so the result always has 4 digits).
4. Repeat with the result until you reach 6174.

Any 4-digit number that does not have all digits equal reaches 6174 in at most 7 steps.

## What the program does

- Asks for a 4-digit number and **validates the input**: exactly 4 characters, digits only, and not 4 repeated digits (those lead to 0000).
- Prints each subtraction and the number of steps needed.
- Checks every number from 0000 to 9999 (except repeated-digit ones) and reports the maximum number of steps, which is 7.

## Example

```
Input your 4 digit number: 3524

Substraction number 1: 5432-2345
New value: 3087

Substraction number 2: 8730-0378
New value: 8352

Substraction number 3: 8532-2358
New value: 6174

Substractions needed to go from 3524 to 6174: 3 out of 7 possibles.

Max iterations for numbers between 0000 to 9999: 7
```

## How to run

```
g++ -std=c++17 kaprekar.cpp -o kaprekar
./kaprekar
```

## Implementation notes

- `sortMax` and `sortMin` convert the string to digits, sort them with `std::sort` and rebuild the integer.
- Every function is documented with its input, output and pre-conditions, and the file ends with the time and space complexity analysis (O(1), since inputs are limited to 4 digits).
- Input validation uses an `unordered_set` of allowed characters.

## Authors

Samuel Holguín and Ricardo Villarreal.
