//Ahnaf Raihan
//program3.cpp

/* program3.cpp contains methods: int max, int lcs, and int main. program3.cpp serves to demonstrate the use of recursive programming in a top-down fashion using memoization in order to solve the LCS problem. */

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

/* int max is utilized by int lcs to find the maximum of two values. It takes in two integers and outputs the larger of the two */

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

/* int lcs is used by int main to recursively find the longest common subsequence between two strings and returns length of the longest common subsequence. It takes in two strings X and Y as well as their respective lengths, m and n. int LCS uses three cases to iteratively find the length of the LCS: The base case, in which m or n are 0, the second case in which the current subproblem has already been calculated, and is simply retrieved from our 2D array, or the third case in which the subproblem has not been calculated, and we calculate it recursively - and then save the result to our 2D array of answers. int lcs assumes that X and Y are < 100 characters, and m and n will be greater than 0. */

int lcs(string X, string Y, int m, int n) {
    int c[m+1][n+1]; // 2D array used to hold calculations for subproblems
    int retVal = 0; // integer to hold return value of LCS length
    for(int i = 0; i <= m; i++) // integer used to iterate through c and set values to -1
        for(int j = 0; j<= n; j++) // integer used to iterate through c and set values to -1
            c[i][j] = -1;
    
    if(m == 0 || n == 0)
        return 0;
    
    if(c[m][n]!= -1)
        return c[m][n];
    
    if(X[m-1] == Y[n-1])
        retVal = 1 + lcs(X,Y,m - 1,n - 1);
    else
        retVal = max(lcs(X,Y,m - 1,n),lcs(X,Y,m,n - 1));
    
    c[m][n] = retVal;
    return retVal;
}

/* int main serves as the driver for program3 and takes in 3 files from the terminal: <filex.txt> <filey.txt> <output3.txt>. It then calculates m and n, the lengths of two input strings X and Y. After this it begins a timer to measure time to run the algorithm. int main runs int LCS and stops the timer after completion. Finally, it outputs length of the found LCS and prints the total time taken by the recursive top-down LCS algorithm to the output file. int main uses argc to hold the number of arguments passed in to program and argv as an array of strings holding each argument. int main assumes to receive 3 file names from the terminal. */

int main(int argc, const char * argv[]) {
    ifstream filex(argv[1]); //input stream to operate on first input file
    string X((istreambuf_iterator<char>(filex)), istreambuf_iterator<char>()); // string containing input from first input file
    ifstream filey(argv[2]); //input stream to operate on second input file
    string Y((istreambuf_iterator<char>(filey)), istreambuf_iterator<char>()); // string containing input from second input file
    ofstream output(argv[3]); //output stream to operate on third input file
    
    int m = X.length()-1; // variable to hold length of string X
    int n = Y.length()-1; // variable to hold length of string Y
    
    clock_t begin = clock(); // variable to hold current system time before execution of lcs
    int length = lcs(X, Y, m, n); // int to hold return value (length of lcs)
    clock_t end = clock(); // variable to hold current system time after execution of lcs
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC * 1000.0; // variable to hold calculated execution time of int lcs method in milliseconds
    
    output << length << endl; // output length of LCS to output file
    output << elapsed_secs << " ms" << endl; // output run time of algorithm to output file
    return 0;
}
