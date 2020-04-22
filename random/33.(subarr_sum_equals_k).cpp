//find the number of subarrays having sum == k
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
int subarraySum(vector<int>& nums, int k);


signed main(){
    cout<<"Hello Ritoman"<<endl;
    v(int)nums{-1,-1,1,-1,1};
    int k = 0;
    cout<<subarraySum(nums, k)<<endl;
    return 0;
}


int subarraySum(vector<int>& nums, int k) {
    int n = nums.size(), c = 0, s = 0;
    unordered_map<int, int> d{{0,1}};
    
    for(int i=0; i<n; i++){
        s = s + nums[i];
        if (d.find(s-k) != d.end()){
            c += d[s-k];
        }
        if(d.find(s)==d.end())
            d[s] = 1;
        else
            d[s] += 1;
    }
    return c;
}