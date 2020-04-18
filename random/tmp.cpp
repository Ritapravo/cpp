#include <iostream>
#include<stdio.h>
#include<vector>
#include<bits/stdc++.h>

using  namespace std;

void abc(int a){
	++a;
	printf("%d",a);
}

signed main(){
	int a=10;
	abc(++a);
	abc(a++);
	printf("%d",a);
}
//g++ "tmp.cpp" && a
//g++ "F:\cpp\random\tmp.cpp" && a 



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