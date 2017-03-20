			----------------------
   				program1 
			----------------------

program1 utilizes the bottom-up dynamic programming approach to solve the Longest Common Subsequence problem (LCS).

To compile:

1) Move to designated directory holding program1.cpp and associated files.
2) Prompt> make
3) Prompt> ./program1 <filex.txt> <filey.txt> <output1.txt> 

<filex.txt> contains one line with a sequence of characters (without space)
<filey.txt> contains one line with a sequence of characters (without space)
<output1.txt> is your designated text file for program1 output

program1 makes use of a 2D array to replicate lenLCS in order to find the longest common subsequence in a bottom-up fashion. With an array, we can complete the table, then traverse the array backwards iteratively to find the LCS.

The running time of the bottom-up method is theta(mn), because each table entry takes theta(1) time to compute. The bottom-up method runs similarly to top-down, but has an advantage with smaller inputs.

program1 contains program1.cpp, used as a driver for the int lcs algorithm.
