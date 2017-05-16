			----------------------
   				program2 
			----------------------

program2 utilizes the recursive (without memoization) programming approach to solve the Longest Common Subsequence problem (LCS).

To compile:

1) Move to designated directory holding program2.cpp and associated files.
2) Prompt> make
3) Prompt> ./program2 <filex.txt> <filey.txt> <output2.txt> 

<filex.txt> contains one line with a sequence of characters (without space)
<filey.txt> contains one line with a sequence of characters (without space)
<output2.txt> is your designated text file for program2 output

program2 does not make use of any specific C++ data structures.

The running time of the recursive method is theta(2^n) in its worst case (when there are no common characters between X and Y) due to many subproblems being solved repetitively, making it the slowest of the 3 LCS methods.

program2 contains program2.cpp, used as a driver for the int lcs algorithm.
