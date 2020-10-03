#include <iostream>
#include <vector>
using namespace std;

bool MazeTraversal(vector<vector<char>>&Maze,int s_row, int s_col,int e_row, int e_col)
{}

int main( int argc, char** argv)
{
    vector<vector<char>>Maze
    {
        {-1,0,-1,0,0,0,-1,0},
        {0,0,-1,0,0,-1,0,0},
        {0,-1,-1,0,-1,-1,0,-1},
        {0,-1,-1,0,0-1,0,-1},
        {0,-1,-1,-1,0,-1,0,-1},
        {0,0,-1,-1,0,-1,0, 0},
        {-1,0,0,0,0,0,-1,0},
        {0,0,-1,-1,-1,0,0,0}
    };
    
    int startRow = 8;
    int startCol = 0;
    int endRow = 0;
    int endCol = 8;

    if(MazeTraversal(Maze, startRow,startCol,endRow,endCol))
    {
        cout << "There is a path from the starting to end of the maze" <<endl;
    }
    else
    {
        cout << "There is no path from start to end" << endl;
    }
    return 0;
}