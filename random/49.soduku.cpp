#include <bits/stdc++.h>
using namespace std;

bool isFilled(vector<vector<int>> &sudoku, int &row, int &col)
{
    for(row = 0; row < 7; row++)
    {
        for(col = 0; col < 7; col++)
        {
            if(sudoku[row][col] == 0)
                return false;
        }
    }
    return true;
}

vector<int> Possibilities(vector<vector<int>> sudoku, int row, int col, vector<vector<char>> &region)
{
    vector<int> arr(8, 0);
    
    for(int j = 0; j < 7; j++)
    {
        if(sudoku[row][j] != 0)
            arr[sudoku[row][j]] = 1;
    }

    for(int i = 0; i < 7; i++)
    {
        if(sudoku[i][col] != 0)
            arr[sudoku[i][col]] = 1;
    }

    char code = region[row][col];

    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(region[i][j] == code && sudoku[i][j] != 0)
            {
                arr[sudoku[i][j]] = 1;
            }
        }
    }
    

    vector<int> poss;
    for(int i = 1; i <= 7; i++)
    {
        if(arr[i] == 0)
            poss.push_back(i);
    }

    return poss;
}

bool Solve(vector<vector<int>> &sudoku, vector<vector<char>> &region)
{
    int row, col;

    if(isFilled(sudoku, row, col))
    {
        return true;
    }
    //cout<<row<<" "<<col<<endl;
    vector<int> poss = Possibilities(sudoku, row, col, region);
    int t = poss.size();
    for(int k = 0; k < t; k++)
    {
        sudoku[row][col] = poss[k];
        if(Solve(sudoku, region))
            return true;
        sudoku[row][col] = 0;
    }
    return false;
}

int main()
{
    vector<vector<int>> sudoku(7, vector<int> (7));
    vector<vector<char>> region(7, vector<char> (7));
    
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            cin>>sudoku[i][j];
        }
    }

    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            cin>>region[i][j];
        }
    }
    
    bool ans = Solve(sudoku, region);
    if(ans == false)
    {
        cout<<"Sudoku can't be solved";
    }
    else
    {
        for(int i = 0; i < 7; i++)
        {
            for(int j = 0; j < 7; j++)
            {
                cout<<sudoku[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}

//g++ "tmp.cpp" && a
//g++ "F:\cpp\random\tmp.cpp" && a 


/* 
7 1 3 4 5 2 6 
1 6 5 2 4 3 7
3 5 2 6 1 7 4
4 2 7 3 6 5 1
5 7 4 1 2 6 3
6 3 1 5 7 4 2
2 4 6 7 3 1 5

 */

/* 
0 0 0 0 0 0 0

0 0 0 0 4 0 0

3 0 0 6 0 0 0

0 0 0 0 6 0 1

5 0 0 0 0 0 3

0 0 1 0 0 0 2

2 0 0 0 0 0 5

r r r b b b b

g r r r r b o

g g g g b b o

p p g o o o o

p p g d o l l

p p p d l l l

d d d d d l l */

/* 
0 0 0 0 0 6 0

0 0 0 0 0 0 0

2 6 5 1 7 4 3

0 0 0 3 0 0 0

0 0 0 0 0 0 0

0 0 0 0 0 0 0

0 0 0 0 0 0 0

a a a b b b b

a a a a b b c

d d d e e b c

d d d d e e c

f f f h e e c

f f h h e c c

f f h h h h c */