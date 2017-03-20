//Ahnaf Raihan
//program1.cpp

/* program1.cpp contains methods: int max, int lcs, and int main. program1.cpp serves to demonstrate the use of bottom-up dynamic programming in order to solve the LCS problem. */

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

/* int lcs is used by int main to iteratively find the longest common subsequence between two strings and print out lenLCS table for input less than size 10. It takes in two strings X and Y as well as their respective lengths, m and n; and an ostream object used to output results to a file. int LCS constructs the lenLCS table one row at a time, from left to right. When it is complete, c[m][n] will contain length of the LCS. If length of X or Y is less than or equal to 10, it proceeds to print out the table lenLCS, and prints a longest common subsequence. To find the LCS, the method traverses the array from c[m][n]. From there if a letter in X and Y in c[a][b] are equal, we add it to the final LCS string. If not, compare values of c[a-1][b] and c[a][b-1] and continue the process with the max of the two until reaching an end of the table. int lcs assumes that X and Y are < 100 characters, m and n will be greater than 0 and output file will be open. */

int lcs (string X, string Y, int m, int n, ostream &output) {
    int c[m+1][n+1]; // 2D array used to replicate lenLCS and order subproblems in order to solve smaller subproblems first
    int a = m; // integer to hold length of X used when traversing array c from bottom-up
    int b = n; // integer to hold length of Y used when traversing array c from bottom-up
    string word = ""; // string used to hold LCS
    for (int i = 0; i <= m; i++) { // int i used as iterator
        for (int j = 0; j <= n; j++) { // int j used as iterator
            if (i == 0 || j == 0) {
                c[i][j] = 0;
                if (m <= 10 && n <= 10)
                    output << c[i][j];
            }
            
            else if (X[i-1] == Y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;   // This code builds the table for lenLCS in the bottom-up fashion
                if (m <= 10 && n <= 10) {
                    output << c[i][j];
                }
            }
            
            else {
                c[i][j] = max(c[i-1][j], c[i][j-1]);
                if (m <= 10 && n <= 10)
                    output << c[i][j];
            }
        }
        
        if (m <= 10 && n <= 10)
            output << endl;
    }

    while (a > 0 && b > 0){  // finds the LCS starting at c[m][n] and puts it into string word
        if (X[a - 1] == Y[b - 1]) {
            word = X[a - 1] + word;
            a--;
            b--;
        }
        else if (c[a - 1][b] < c[a][b - 1]) {
            b--; }
        else {
            a--; }
    }
    if (m <= 10 && n <= 10)
        output << word << endl;
    return c[m][n]; // contains value for length of LCS
}

/* int main serves as the driver for program1 and takes in 3 files from the terminal: <filex.txt> <filey.txt> <output1.txt>. It then calculates m and n, the lengths of two input strings X and Y. After this it begins a timer to measure time to run the algorithm. int main runs int LCS and stops the timer after completion. Finally, if length of X or Y was greater than 10, it outputs length of the found LCS and prints the total time taken for the bottom-up LCS algorithm to the output file. int main uses argc to hold the number of arguments passed in to program and argv as an array of strings holding each argument. int main assumes to receive 3 file names from the terminal. */

int main(int argc, const char * argv[]) {
    ifstream filex(argv[1]); //input stream to operate on first input file
    string X((istreambuf_iterator<char>(filex)), istreambuf_iterator<char>()); // string containing input from first input file
    ifstream filey(argv[2]); //input stream to operate on second input file
    string Y((istreambuf_iterator<char>(filey)), istreambuf_iterator<char>()); // string containing input from second input file
    ofstream output(argv[3]); //output stream to operate on third input file
    
    int m = X.length()-1; // variable to hold length of string X
    int n = Y.length()-1; // variable to hold length of string Y
    
    clock_t begin = clock(); // variable to hold current system time before execution of lcs
    int length = lcs(X, Y, m, n, output); // int to hold return value (length of lcs)
    clock_t end = clock(); // variable to hold current system time after execution of lcs
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC * 1000.0; // variable to hold calculated execution time of int lcs method in milliseconds
    
    if (m > 10 || n > 10)
        output << length << endl; // output length of LCS if m or n are greater than 10
    output << elapsed_secs << " ms" << endl; // output run time of algorithm to output file
    return 0;
}
