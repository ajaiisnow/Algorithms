#include <iostream>
#include <vector>

using namespace std;

void FindAllPermutations( vector<int>& in_arr, 
                          int stIdx, int len,
                          vector<vector<int>>&res_array)
{
    if( stIdx == len)
    {
        res_array.push_back(in_arr);
        return;
    }
    for( int i = stIdx; i < len; i++)
    {
        swap(in_arr[i],in_arr[stIdx]);
        FindAllPermutations( in_arr, stIdx+1, len, res_array);
        swap(in_arr[i], in_arr[stIdx]);
    }
}



int main()
{
    vector<int> arr{1,2,3};
    vector<vector<int>> resultant_arry;
    FindAllPermutations(arr,0, arr.size(), resultant_arry);

    cout << "There are "<< resultant_arry.size() <<" Permutations"<<endl;
    for( auto a : resultant_arry)
    {
        cout << "[ " ;
        for(auto in_a : a)
        {
            cout << in_a << " ";
        }
        cout << "]" <<endl;
    }
}