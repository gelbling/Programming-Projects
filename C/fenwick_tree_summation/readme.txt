PROGRAM DESCRIPTION:
A Fenwick tree (also known as a binary indexed tree) is a data structure that can efficiently perform range calculations, such as computing the sum across a range of numbers without having to examine every single number in the range.

Motivating Example: Suppose we have an array with N elements, and we want to find the sum from indices i to j. The simplest approach would be to iterate through the elements from i to j, and then sum them. For the worst case scenario, this would take N operations.



RUN EXAMPLE:

exe/./PC03 1 2 3 4 5 6 7 8 9 10
------------------------------
1: Print array and fenwick tree 
2: Calculate range sum 
3: Update array and Fenwick Tree
ENTER YOUR SELECTION: 1
Array  : 0 1 2 3 4 5 6 7 8 9 10 
Fenwick: 0 1 3 3 10 5 11 7 36 9 19 

Do you wish to continue? (y/n): y
------------------------------
1: Print array and fenwick tree 
2: Calculate range sum 
3: Update array and Fenwick Tree
ENTER YOUR SELECTION: 2

Enter the range to calculate, between 1 and 11: 3 9

The sum from 3 to 9: 42

Do you wish to continue? (y/n): y
------------------------------
1: Print array and fenwick tree 
2: Calculate range sum 
3: Update array and Fenwick Tree
ENTER YOUR SELECTION: 3

Enter the location and value to update the initial array: 3 50

Do you wish to continue? (y/n): y
------------------------------
1: Print array and fenwick tree 
2: Calculate range sum 
3: Update array and Fenwick Tree
ENTER YOUR SELECTION: 1
Array  : 0 1 2 50 4 5 6 7 8 9 10 
Fenwick: 0 1 3 50 57 5 11 7 83 9 19 

Do you wish to continue? (y/n): n