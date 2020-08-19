#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	char prev = 'x';
	int ind = 0;
	int a_count = 0, b_count =0;
	for( char c:s){
		if(c=='A')a_count++;
		if(c=='B')b_count++;
	}
	for(int i = 0; i<n; i++){
		if(s[i]=='-')
			continue;
		else if(s[i]=='A'){
			if(prev=='A')
				a_count += i-ind-1;
			else if(prev=='B'){
				a_count += (i-ind-1)/2;
				b_count += (i-ind-1)/2;
			}
			else
				a_count += i;
			prev = 'A';
			ind = i;
		}
		else{
			if(prev=='B')
				b_count += i-ind-1;
			prev = 'B';
			ind = i;
		}
	}
	if(prev=='B')
		b_count += n-ind-1;
	if(a_count>b_count)
		cout<<'A'<<endl;
	else if (b_count>a_count)
		cout<<'B'<<endl;
	else	
		cout<<"Coalition government"<<endl;
	return 0;
}

//g++ "tmp5.cpp" && a
//g++ "F:\cpp\random\tmp5.cpp" && a 