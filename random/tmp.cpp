#include<stdio.h>
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
//#define int long long int
#define v(x) vector<x>
using namespace std;
void print(v(v(int)) &arr);
void print(v(int)&arr);


int main(){
	cout<<"Hello Ritoman"<<endl;
	
	int a= 5, b=6, c=8, d =9,  max;
	max = a>b?a:b>c?b:c>d?c:d;
	cout<<max<<endl;
	int k = -1, i;
	for(i = 0 ; i<5; i++){
		switch(i+k){
			case 1:
			case 2:
				printf("%d ", i+k);
			case 3:
				printf("%d ", i+k);
			default:
				printf("%d ", i+k);
		}
	}
	return 0;
}
