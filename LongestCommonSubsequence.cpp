#include <iostream>
#include <limits.h>
#include <string>
#include <cstring>
#include <memory>
using namespace std;

int main( int argc, char**argv)
{
    string str1("asdbfvadsfbcd");
    string str2("abbcdnkhgy");
 
    const int ROWS = str1.length()+1;
    const int COLS = str2.length()+1;

    int dptab[ROWS][COLS] = {0};
    for( int i = 1; i < ROWS; i++)
    {
        for( int j = 1; j < COLS; j++)
        {
            if(str1[i] == str2[j])
            {
                dptab[i][j] = dptab[i-1][j-1]+1;
            }
            else
            {
                dptab[i][j] = max(dptab[i-1][j], dptab[i][j-1]);
            }            
        }
    }
    cout << "Longest Common Subsequence length is " << dptab[ROWS-1][COLS-1] <<endl;    
    return 0;
}