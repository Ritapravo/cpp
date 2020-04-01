//mergesort in vector
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define ll long long int
#define v(x) vector<x>
using namespace std;
void print(v(v(int)) &arr);
void print(v(int)&arr);
void merge(v(int) &arr, int l , int m, int r);
void mergesort(v(int) &arr, int l , int r);


int main(){
    cout<<"Back once again"<<endl;
    v(v(int)) arr {{1,3},{6,6},{6,6}};
    
    v(int) ab{10, 9, 0, 0, 1, 6, 9, 4};
    mergesort(ab,0,ab.size()-1);
    print(ab);
    print(arr);
    return 0;
}

void merge(v(int) &arr, int l , int m, int r){
    v(int) x, y;
    for (int i = l;i<=m; i++)
        x.push_back(arr[i]);
    for (int i = m+1 ;i<=r; i++)
        y.push_back(arr[i]);
    int i = 0, j = 0, k= l;
    while(i<m-l+1 && j < r-m){
        if(x[i]<y[j]){
            arr[k]=x[i];
            i++;
            k++;
        }
        else{
            arr[k]=y[j];
            j++;
            k++;
        }
    }
    while(i<m-l+1){
        arr[k]=x[i];
        i++;
        k++;
    }
    while(j<r-m){
        arr[k]=y[j];
        j++;
        k++;
    }
}
void mergesort(v(int) &arr, int l , int r){
    if(l<r){
        int mid = l + (r-l)/2;
        mergesort(arr,l, mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}


void print(v(v(int)) &arr){
    cout<<"{";
    for(auto i = arr.begin(); i!=arr.end(); i++){
        cout<<"{";
        for(auto j =(*i).begin(); j!=(*i).end(); j++){
            cout<<*j;    
            if(j!=(*i).end()-1)
                cout<<",";
        }
        cout<<"}";
        if(i!=arr.end()-1)
                cout<<",";
    }cout<<"}"<<endl;
}
void print(v(int)&arr){
    cout<<"{";
    for(auto i=arr.begin(); i!=arr.end(); i++){
        cout<<*i;
        if(i!=arr.end()-1)
            cout<<",";
    }cout<<"}"<<endl;
}