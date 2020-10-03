#include <iostream>
#include <cstring>
#include <memory>
#include <stdio.h>
using namespace std;

void Assign( int LEN, int* Arr[])
{
    for( int i = 0; i < LEN; i++)
    {
        for( int j = 0; j < LEN; j++)
        {
            Arr[i][j]  = ((i*LEN)+j);
        }
        cout << endl;
    }
}


void print( int LEN, int* Arr[])
{
    for( int i = 0; i < LEN; i++)
    {
        for( int j = 0; j < LEN; j++)
        {
            cout << Arr[i][j] << "   ";
        }
        cout << endl;
    }
}


int main()
{
    int** arr = new int*[5];
    for( int i = 0; i < 5; i++)
    {
        arr[i] = new int[5];
    }
    
    Assign(5, arr);

    print( 5, arr);

    for(  int i = 0; i < 5; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}