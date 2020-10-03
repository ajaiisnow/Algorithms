#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool check_if_repeated( const vector<int>& char_map, const string& str, int left, int right)
{
    if(char_map[str[right]] != 0)
    {
        return false;
    }
    return true;
}

void remove_from_char_map( vector<int>&char_map,const string &str, int left)
{
    char_map[str[left]] = 0;
}

 int longest_non_rep_substring( const string& str)
 {
     if( str.length())
     {
         int len = str.length();
         int left = 0; int right = 0;
         int max_len = 0;
         vector<int> char_map(256);
         while( left < len && right < len)
         {
             if(check_if_repeated(char_map, str, left, right))
             {
                 ++char_map[str[right]];
                 ++right;
                 max_len = max(max_len, (right-left));
             }
             else
             {
                 remove_from_char_map(char_map, str, left);
                 ++left;
             }
         }
         return max_len;
     }
     else
     {
        return 0;
     }
 }
     
 int main( int argc, char** argv)
 {
     //string str("abcbcab");
     //string str("aaaaabcd");
     string str("pwwkew");
    int len = longest_non_rep_substring(str);
    cout << "Length of the longest substring is " << len <<endl; 
 }