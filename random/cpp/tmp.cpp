#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;
void print(v(v(int)) &arr);
void print(v(int)&arr);


signed main(){
	int n,m,r;
	cin>>n>>m>>r;
	int a[n],b[m];
	int s1 = 0,s2 = 0;
	for(int i = 0; i<n; i++){
		cin>>a[i];
		s1 += a[i]-r;
	}
	for(int i = 0; i<m; i++){
		cin>>b[i];
		s2 += b[i]-r;
	}
	int ans = abs(s1-s2);
	ans += r;
	if(s1==s2)
		cout<<"Balanced"<<endl;

	else if(s1>s2)cout<<-1*ans<<endl;
	else
		cout<<ans<<endl;
	return 0;
}


//g++ "tmp.cpp" && a
//g++ "F:\cpp\random\tmp.cpp" && a 