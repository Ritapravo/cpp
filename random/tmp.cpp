#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<stdio.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
void print(v(v(int)) &arr);
void print(v(int)&arr);


signed main(){
	int t;
	cin>>t;
	while(t--){
		v(int)arr;
		int x;
		while(true){
			cin >>x;
			if(x == -1)
				break;
			else
				arr.push_back(x);
		}
		int n  = arr.size(), cnt = 0, tot = 0, pos = 0 ;
		for(int i = 0; i<n; i++){
			if(arr[i]>30)
				cnt += 1;
			if(arr[i]%2==0){
				pos += i+1;
				tot += arr[i]*(i+1);
			}
		}
		float ans = (float)tot/pos;
		printf("%lld %0.2f\n",cnt, ans );
	}
	return 0;
}


//g++ "tmp.cpp" && a
//g++ "F:\cpp\random\tmp.cpp" && a 