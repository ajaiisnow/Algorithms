#include <iostream>
#include <vector>
using namespace std;

int Partition(int lo, int hi, vector<int>& arr)
{
    int i = lo-1;
    int j = lo;
    int pivot = arr[hi];
    while( j < hi)
    {
        if(arr[j] < pivot)
        {
            swap(arr[++i], arr[j]);
        }
        ++j;
    }
    if(i < hi)
    {
        swap(arr[++i], arr[j]);
    }
    return i;
}

void QSort(int lo, int hi, vector<int>& arr)
{
    if(lo < hi)
    {
        int part = Partition(lo,hi,arr );
        QSort(lo, part-1, arr);
        QSort(part+1, hi, arr);
    }
}

int main( int argc, char** argv)
{
    vector<int> arr {5,4,11,2,1,9,8,7,1};
    QSort(0, arr.size()-1, arr);
    cout << "Sorted array is:"<<endl;
    for(int i : arr)
    {
        cout << i << ", ";
    }
    cout <<endl; 
    return 0;
}
