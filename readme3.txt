			----------------------
   				program3 
			----------------------

program3 utilizes the top-down recursive (with memoization) dynamic programming approach to solve the Longest Common Subsequence problem (LCS).

To compile:

1) Move to designated directory holding program3.cpp and associated files.
2) Prompt> make
3) Prompt> ./program3 <filex.txt> <filey.txt> <output3.txt> 

<filex.txt> contains one line with a sequence of characters (without space)
<filey.txt> contains one line with a sequence of characters (without space)
<output3.txt> is your designated text file for program3 output

program3 uses a 2D array that serves to hold the calculations of a subproblem to be potentially retrieved if the subproblem arises again.

The running time of the recursive method is O(mn), similar to the bottom-up approach. The top-down approach pays in recursion overhead, but can be faster than the bottom-up method in cases where certain subproblems are never analyzed.

program3 contains program3.cpp, used as a driver for the int lcs algorithm.