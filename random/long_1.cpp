#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
void print(v(v(int)) &arr);
void print(v(int)&arr);


signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i =0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr, arr+n);
        v(int)groups;
        int g = 1;
        for(int i =0; i<n-1; i++){
            if(arr[i+1]-arr[i]<=2)
                g ++;
            else{
                groups.push_back(g);
                g = 1;
            }
        }
        groups.push_back(g);

        int a1 = *min_element(groups.begin(), groups.end());
        int a2 = *max_element(groups.begin(), groups.end());
        
        cout<<a1<<" "<<a2<<endl;
        
    }
    return 0;
}
