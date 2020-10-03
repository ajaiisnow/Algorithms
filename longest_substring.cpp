#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int search_longest_seq(const string& str1, const string& str2, string& longest_string)
{
    int longest_seq_len = 0;
    const int row = str1.length()+1;
    const int col = str2.length()+1;
    int dp_table[row][col];
    memset(dp_table, 0, sizeof(dp_table));
    int i = 1;
    int j = 1;
    int longest_seq_row = 0;
    int longest_seq_col = 0;
    while( i < row )
    {
        while( j < col)
        {
            if(str1[i-1] == str2[j-1])
            {
                dp_table[i][j] = dp_table[i-1][j-1] +1;
                if(longest_seq_len < dp_table[i][j])
                {
                    longest_seq_len = dp_table[i][j];
                    longest_seq_row = i;
                    longest_seq_col = j;
                }
            } 
            ++j;     
        }
        j = 0;
        ++i;
    }

    int row_idx = longest_seq_row;
    int col_idx = longest_seq_col;
    vector<char> longest_seq_string;
    while( row_idx > 0 && col_idx > 0 && dp_table[row_idx][col_idx] != 0)
    {
        longest_seq_string.push_back(str1[row_idx-1]);
        --row_idx;
        --col_idx;
    }
    longest_string.assign( longest_seq_string.rbegin(),longest_seq_string.rend());
    return longest_seq_len;
}

int main( int argc, char **argv)
{
    string str1("ABCDFOLA");
    string str2("ANBCDFOLK");
    string longest_seq;
    int leng = search_longest_seq(str1,str2,longest_seq);
    cout << "length of longest sequence is: " << leng << endl;
    cout << "Longest sub sequence is: " << longest_seq <<endl; 
    return 0;
}