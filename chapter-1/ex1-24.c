// Write a program to check a C program for rudimentary syntax
// 	errors like unbalanced parentheses, brackets and braces.
// Don't forget about quotes, both single and double
// escape sequences, and comments.
// This program is hard if you do it in full generality.

#include <string.h>
#include <stdio.h>
// Good
// 2 + (3 + 8)
// Bad
// 9 + (3
// 2) - 7 + (10 / 5)

// startLoop to get characters
// balanced = 0
// if char == '(' balanced += 1
// if char == ')' balanced -= 1
//   if balanced < 0 stop loop
// endLoop
// if balanced == 0 print: "Balanced expression"
// else print: "Unbalanced expression"