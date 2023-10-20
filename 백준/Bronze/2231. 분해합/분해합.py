"""
Digit Generator
================

- Given an integer number, 
- you have to find the smallest integer number 
- such that the product of its digits is equal to the given number. 
- If no such number exists, print 0.
"""

input_number = int(input())
status = 0
for i in range(1, input_number): # 1 <= i < input_number
    test_number = i # Declare test_number to check 
    for j in str(i): # Trouver by digit
        test_number += int(j) # Convert to int for computing
    if test_number == input_number: # if i is the smallest generator number
        print(i)
        status = 1
        break # It starts from 1, and the first one is the smallest one.

if status == 0:
    print(0)
