#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

void subsets( vector<int>& arr, vector<vector<int>>&subset_array)
{
    int len = arr.size();
    for( int64_t i = 0; i < pow(2,len); i++ )
    {
        int mask = 1;
        vector<int> temp;
        for( int j = 0; j < len; j++ )
        {
            if( i & (mask << j ))
            {
                temp.push_back(arr[j]);
            }
        }
        subset_array.push_back(temp);
    }
}


int main()
{
    vector<int> arr{1,2,3,4,5};
    vector<int> subarry;
    vector<vector<int>> sub_arr;
    subsets(arr,sub_arr );
    cout << "Sub arrays of Array: "<< sub_arr.size() <<endl;
    for( auto a : sub_arr)
    {
        cout << "[ ";
        for( auto in_arr : a)
        {
            cout << in_arr << " ";
        }
        cout << " ]" <<endl;
    }
    return 0;
}