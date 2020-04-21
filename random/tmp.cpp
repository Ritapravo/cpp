#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define int long long int
#define v(x) vector<x>
using namespace std;

signed main(){
	int t;
	cin>>t;
	while(t--){
		string s1,s2;
		cin>>s1>>s2;
		int n = s1.size();
		s1 = s1 + "#";
		s2 = s2 + "#";

		int c = 0,x=-1;
		v(int) A,B;

		int l = 0, k =0;
		for(int i =0; i<=n; i++){
			if(s1[i]!=s2[i]){
				c++;
				l++;
			}
			else{
				if(c!=0){
					if(k>0)
						A.push_back(i-c-x);
					k++;
					x = i;
				}
				c=0;
			}
		}
		
		int ans =l*k;
		int i =0;

		if(k>1)sort(A.begin(), A.end());
		
		while(k>1){
			l += A[i++];
			int tmp = (--k)*l;
			if(tmp<ans)
				ans = tmp;
		}

		cout<<ans<<endl;
		
	}
	return 0;
}




void print(v(int)&arr){
	cout<<"{";
	for(auto i=arr.begin(); i!=arr.end(); i++){
		cout<<*i;
		if(i!=arr.end()-1)
			cout<<",";
	}cout<<"}"<<endl;
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