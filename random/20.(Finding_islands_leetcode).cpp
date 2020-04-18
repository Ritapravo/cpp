//Finding islands 
//link- https://leetcode.com/problems/number-of-islands/

//g++ "F:\cpp\random\20.(Finding_islands_leetcode).cpp" && a 
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;

void bfs(v(v(char))&grid, int i,int j,int m,int n);
void dfs(v(v(char))&grid, int i,int j,int m,int n);



signed main(){
    cout<<"Hello Ritoman"<<endl;
    v(v(char))grid {{'1','1','0','0','0'},
                    {'1','1','0','0','0'},
                    {'0','0','1','0','0'},
                    {'0','0','0','1','1'}};
                    
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(grid[i][j]=='1'){
                dfs(grid,i,j, m, n);
                count ++;
            }
        }
    }
    cout<<count<<endl;
}

void bfs(v(v(char))&grid, int i,int j,int m,int n){
    queue<pair<int, int>> q;
    q.push({i,j});
    grid[i][j] = '0';
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        //cout<<x<<" "<<y<<endl;
        if(y>0 && grid[x][y-1]=='1'){
            q.push({x,y-1});
            grid[x][y-1] = '0';
        }
        if(y<n-1 && grid[x][y+1]=='1'){
            q.push({x,y+1});
            grid[x][y+1] = '0';
        }
        if(x>0 && grid[x-1][y]=='1'){
            q.push({x-1,y});
            grid[x-1][y] = '0';
        }
        if(x<m-1 && grid[x+1][y]=='1'){
            q.push({x+1,y});
            grid[x+1][y] = '0';
        }
        
    }
}

void dfs(v(v(char))&grid, int i,int j,int m,int n){
    if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0') return;
    grid[i][j] = '0';
    dfs(grid, i, j-1, m, n);
    dfs(grid, i, j+1, m, n);
    dfs(grid, i-1, j, m, n);
    dfs(grid, i+1, j, m, n);
}