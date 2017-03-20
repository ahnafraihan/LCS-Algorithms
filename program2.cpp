//Ahnaf Raihan
//CS375 - program2

/* program2.cpp contains methods: int max, int lcs, and int main. program2.cpp serves to demonstrate the use of recursive programming in order to solve the LCS problem. */

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

/* int lcs is used by int main to recursively find the longest common subsequence between two strings and return length of the longest common subsequence. It takes in two strings X and Y as well as their respective lengths, m and n. int LCS uses three cases to recursively find the length of the LCS: The base case, in which m or n are 0, the second case in which the previous value in X and Y are both equal and we recursively call lcs again, or the third case in which the previous values in X and Y are not equal and we recursively call lcs on the larger of the two. int lcs assumes that X and Y are < 100 characters, and m and n will be greater than 0. */
int lcs(string X, string Y, int m, int n) {
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return lcs(X, Y, m - 1, n - 1) + 1;
    else
        return max(lcs(X, Y, m - 1, n), lcs(X, Y, m, n - 1));
}

/* int main serves as the driver for program2 and takes in 3 files from the terminal: <filex.txt> <filey.txt> <output2.txt>. It then calculates m and n, the lengths of two input strings X and Y. After this it begins a timer to measure time to run the algorithm. int main runs int LCS and stops the timer after completion. Finally, it outputs length of the found LCS and prints the total time taken by the recursive LCS algorithm to the output file. int main uses argc to hold the number of arguments passed in to program and argv as an array of strings holding each argument. int main assumes to receive 3 file names from the terminal. */
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
    output << elapsed_secs << " ms" << endl; // outputs run time of algorithm to output file
    
    return 0;
}
