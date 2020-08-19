//Longest Distance First Page Replacement Algorithm implementation

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
#define N 100
using namespace std;


int maxm(int[], int );//maxm function finds the max element in an array
int distinct(int[], int, int, int *, int[]);
//returns the number of distinct pages
int func(int[], int[], int, int, int, unordered_map<int, int>&);
//returns the position of the frame where new page will be inserted in case of page fault

signed main(){
    //cout<<"Hello Ritoman"<<endl;
    cout<<"This is LDF page replacement algorithm"<<endl;
    int frames, n, pages[N], c5, dist[N];
    cout<<"Enter the number of frames: "; cin>>frames;
    cout<<"Enter the number of inputs: "; cin>>n;
    cout<<"Enter the reference pages serially"<<endl;
    for(int i=0 ; i<n ; i++) cin>>pages[i];


    int d = distinct(pages, n, frames, &c5, dist);

    sort(dist, dist+d);
    //for(int i =0; i<d; i++)cout<<dist[i]<<" ";
    cout<<endl;
    unordered_map<int, int> map;
    for(int i = 0; i<d; i++)
        map[dist[i]] = i;

    int faults = 1;
    int matrix[frames+1][n];
    memset(matrix,-1,sizeof(matrix));
    matrix[0][0] = pages[0];
    matrix[frames][0] = -3;
    unordered_set<int> s{pages[0]};
    
    int si = 0;
    for(int j = 1; j<n; j++){
        int temp[frames];
        int x = pages[j];

        for(int i= 0; i<frames; i++)
            matrix[i][j] = matrix[i][j-1];

        if(s.find(x)==s.end()){
            if(j<=c5){
                si ++;
                matrix[si][j] = x;
                s.insert(x);   
            }
            else{
                for(int i= 0; i<frames; i++)
                    temp[i] = matrix[i][j-1] ;
                int pos = func(temp, dist, x, d, n, map);
                matrix[pos][j] = x;
                s.insert(x);
                s.erase(temp[pos]);
            }
            faults ++;
            matrix[frames][j] = -3;
        }
        else
            matrix[frames][j] = -2;
    }
    //
    for(int i = 0 ; i < frames+1 ; i++){
        for (int j = 0 ; j < n ; j++){
            if (matrix[i][j] == -1)
                cout<<"  ";
            else if (matrix[i][j] == -2)
                cout<<"H ";
            else if (matrix[i][j] == -3)
                cout<<"M ";
            else
                cout<<matrix[i][j]<<" "; 
        }
        cout<<"\n";
    }
    cout<<"Page faults: "<<faults<<endl;
    return 0;
}



int func(int temp[], int dist[], int x, int d, int n, unordered_map<int, int>&map){
    int xp = map[x];
    int a[n], b[n];
    for(int i = 0 ; i<n; i++){
        int p = map[temp[i]];
        a[i] = (d+p-xp)%d;
        b[i] = (d+xp-p)%d;
    }
    int m = -1, pos=-1;
    for(int i = 0 ; i<n ; i++){
        int mp = min(a[i],b[i]);
        //cout<<mp<<" "<<m<<" "<<pos<<endl;
        if(mp>=m){
            if(mp==m){
                if(b[i]<b[pos])
                    pos = i;
            }
            else
                pos = i;
            m = mp;
        }
    }
    return pos;
}

int distinct(int array[], int n, int n5, int *c5, int dist[]){
    unordered_set<int> s;
    bool ind = true;
    int res = 0;
    for(int i =0; i<n; i++){
        if (s.find(array[i]) == s.end()) { 
            s.insert(array[i]); 
            dist[res] = array[i];
            res++;
        } 
        if(ind && res==n5){
            *c5 = i;
            ind = false;
        }
    }
    return res;
}

int maxm(int array[], int n){
    int m = array[0];
    for(int i = 1 ; i<n ; i++){
        if (array[i]>m){
            m = array[i];
        }
    }
    return m;
}


//0 2 1 3 5 4 6 3 7 4 7 3 3 5 5 3 1 1 1 7 1 3 4 1

/* 
1. input/output
This is LDF page replacement algorithm
Enter the number of frames: 3
Enter the number of inputs: 12
Enter the reference pages serially
0 1 2 3 0 1 4 0 1 2 3 4

0 0 0 0 0 0 0 0 0 2 2 2
  1 1 3 3 1 1 1 1 1 3 3
    2 2 2 2 4 4 4 4 4 4
M M M M H M M H H M M H
Page faults: 8

2. input/output
This is LDF page replacement algorithm
Enter the number of frames: 4
Enter the number of inputs: 24
Enter the reference pages serially
0 2 1 3 5 4 6 3 7 4 7 3 3 5 5 3 1 1 1 7 1 3 4 1    

0 0 0 0 0 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4
  2 2 2 2 2 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6
    1 1 5 5 5 5 5 5 5 5 5 5 5 5 1 1 1 1 1 1 1 1
      3 3 3 3 3 7 7 7 3 3 3 3 3 3 3 3 7 7 3 3 3
M M M M M M M H M H H M H H H H M H H M H M H H
Page faults: 12

*/