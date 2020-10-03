#include <iostream>
#include <vector>
using namespace std;

int left( int index)
{
    return ((2*index)+1);
}

int right( int index)
{
    return ((2*index)+2);
}

void MaxHeap( int lo, int hi, int index, vector<int>& arr)
{
    int large = index;
    int left_index = left(index);
    int right_index = right(index); 
    if(arr[large] < arr[left_index] && left_index < hi)
    {
        large = left_index;
    }
    if(arr[large] < arr[right_index] && right_index < hi)
    {
        large = right_index;
    }
    if( large != index)
    {
        swap(arr[index], arr[large]);
        MaxHeap( 0, hi, large, arr);
    }
}

void HeapSort( int lo, int hi, vector<int>& arr)
{
    for( int i = hi/2; i >= 0; i--)
    {
        MaxHeap( lo, hi, i, arr);
    }
 
    for( int i = hi; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        MaxHeap( 0, i, 0,arr);
    }

    cout << "Sorted array is :" <<endl;
    for( int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main( int argc, char** argv)
{
    vector<int> arr {5,4,11,2,1,9,8,7,1};
    HeapSort( 0, arr.size()-1, arr);
    return 0;
}