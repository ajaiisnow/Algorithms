#include <iostream>
#include <vector>
#include <limits>

using namespace std;
const int NEG_INFINITY = numeric_limits<int>::min();
const int POS_INFINITY = numeric_limits<int>::max();
float median_of_sorted_arrays( vector<int>& arr1, vector<int>& arr2)
{
    float average = 0;
    if(arr1.size() > arr2.size())
    {
        return median_of_sorted_arrays(arr2,arr1);
    }
    int arr1_len = arr1.size();
    int arr2_len = arr2.size();

    int start = 0;
    int end = arr1.size();
    while(start <= end)
    {
        
        int pos_arr1 = (start + end)/2;
        int pos_arr2 = (arr1_len+ arr2_len + 1)/2 - pos_arr1;

        int max_left_arr1 = (pos_arr1 == 0 )? NEG_INFINITY : arr1[pos_arr1-1];
        int min_right_arr1= (pos_arr1 == arr1_len)? POS_INFINITY : arr1[pos_arr1];

        int max_left_arr2 = (pos_arr2 == 0)? NEG_INFINITY : arr2[pos_arr2-1];
        int min_right_arr2 = (pos_arr2 == arr2_len)?POS_INFINITY:arr2[pos_arr2];

        if(max_left_arr1 <= min_right_arr2 && max_left_arr2 <= min_right_arr1)
        {
            if((arr1_len+arr2_len)%2==0)
            {
                average = (max(max_left_arr1, max_left_arr2)+min(min_right_arr1,min_right_arr2))/2;
            }
            else
            {
                average = max(max_left_arr1,max_left_arr2);
            }
            
            break;
        }
        else if(max_left_arr1 > min_right_arr2)
        {
            /* 
                move left as the maximum of arr1 is greater than min of arr2
                end position is updated with psoition_arr1 -1
            */
            end = pos_arr1-1;
        }
        else
        {
            /* Move right as the maximum is arr2 is greater than minimum of arr1 */
            start = pos_arr1+1;
        }   
    }
    return average;
}

int main(int argc, char**argv)
{
    int n = 5;
    string s = "abcdrfg";
    vector<vector<int>>dp(n,vector<int>(s.length()));

    vector<int> arr1{1,3,5,6,8};
    vector<int> arr2{2,4,7,9};
    double average = median_of_sorted_arrays(arr1, arr2);
    cout << "Median of arrays are: " << average <<endl;
    return 0;
}