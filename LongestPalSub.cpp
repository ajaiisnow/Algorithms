#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

string GetModifiedString(const string& str_in)
{
    string str;
    int i = 0;
    int j = 0;
    int new_length = (2 * str_in.length()) + 1;
    str.reserve(new_length); 
    const char SPECIAL_CHAR = '#';
    while( i < new_length)
    {
        if(i % 2 == 0)
        {
            str.insert(i,1,SPECIAL_CHAR);
        }
        else
        {
            str.insert(i, 1, str_in[j]);
            ++j;
        }
        ++i;
    }
    return str;
}
string ReplaceChar(string& pal_string, char rem_char)
{
    string res_string;
    size_t j = 0;
    for(size_t i = 0; i <  pal_string.length(); i++)
    {
        if(pal_string[i]!= rem_char)
        {
            res_string.insert(j++,1,pal_string[i]);
        }
    }
    return res_string;
}

//  tuple<int,int,int> LongestPalindromeSubString( const string& str_in)
//  {
//     int idx = 0;
//     int mirror_idx = 0;
//     int left = 0;
//     int right = 0;
//     int best_length = 0;
//     const int LEN = str_in.length(); 
//     //int pal[LEN] = {0};
//     for( int center = 0; center < LEN; center++)
//     {
//         idx = center+1;
//         mirror_idx = (2*center)-idx;

//         while(  idx < LEN && mirror_idx >= 0)
//         {
//             if(str_in[idx] != str_in[mirror_idx])
//             {
//                 break;
//             }
//             int length = (idx - mirror_idx)+1;
//             if( length > best_length)
//             {
//                 best_length = length;
//                 left = mirror_idx;
//                 right = idx;
//             }
//             ++idx;
//             mirror_idx = (2*center)-idx;
//         }
//     }
//     return make_tuple(left,right,best_length);

//  }


string LongestPalindromeSubString(string& str_in)
{
    const int LEN = str_in.length();
    int dptab[LEN][LEN] = {0};
    int start_idx = 0;
    string pal_string;
    int length = 1;
    int i = 0; int j = 0;


    for( int i = 0; i < LEN; i++)
    {
        dptab[i][i] = 1;
    }

    while( i < LEN-1)
    {
        j = i+1;
        if( str_in[i] == str_in[j])
        {
            dptab[i][j] = 1;
            if( (j-i)+1 > length)
			{
				length = (j-i)+1;
				start_idx = i;
			}
        }
        i++;
    }

    // for length >= 3
    i = 0;
    int len = 2;
    while(len < LEN)
    {
    	j = i+len;
    	while(i < LEN && j < LEN)
    	{
			if(str_in[i] == str_in[j] && dptab[i+1][j-1] == 1)
			{
				dptab[i][j] = 1;
				if( (j-i)+1 > length)
				{
					length = (j-i)+1;
					start_idx = i;
				}
			}
			++i;
			j = i + len;
    	}
    	i = 0;
		++len;
    }
    pal_string = str_in.substr(start_idx, length);
    return pal_string;
}


int main( int argc, char** argv)
{
	if(argc > 1)
	{
		string str_in(argv[1]);
		string lpal = LongestPalindromeSubString(str_in);
		cout << "Longest Palindrome substring is: " << lpal <<endl;
	}
	else
		cout << "Not Enough parmeters " <<endl;
    return 0;
}
