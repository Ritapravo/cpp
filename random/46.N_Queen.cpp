//N-Queen Problem
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int board[20];

void print(int n ){
    cout<<"\n\n"<<" ";
    for(int j = 1; j<=n; j++)
        cout<<" "<<j;
    cout<<endl;
    for (int i = 1; i<=n; i++){
        cout<<i;
        for(int j = 1; j<=n; j++){
            if(board[i]==j)
                cout<<" Q";
            else    
                cout<<" -";
        }
        cout<<endl;
    }
}

bool check(int row, int col){
    for(int i = 1; i<row; i++){
        if(board[i]==col)
            return false;
        else
            if(abs(board[i]-col)==abs(i-row))
                return false;
    }
    return true;
}

void solve(int row,int n, int &count){
    for(int col = 1; col<=n; col++){
        if(check(row, col)){
            board[row] = col;
            if(row==n){
                print(n);
                count ++;
            }
            else
                solve(row+1,n, count);
        }  
    }
}

signed main(){
    int n=4;
    //cin>>n;
    int count = 0;
    solve(1,n, count);
    //cout<<count<<endl;
    return 0;
}

//g++ "46.N_Queen.cpp" && a
//g++ "F:\cpp\random\46.N_Queen.cpp" && a 
