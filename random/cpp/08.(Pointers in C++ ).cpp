//Pointers in C++ 
#include<iostream>
#include<vector>
#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    cout<<"<--Pointer concepts by RitoMan-->"<<endl<<endl;

    //playing with pointers in an array
    cout<<"Using pointer to iterate through arrays"<<endl;
    int arr[] = {1,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *p = &arr[0];
    cout<<*(p+2)<<endl;//output = arr[2] = 4
    int q = *(arr+1);
    cout<<q<<endl;//output = arr[1] = 3
    while(n--)
        cout<<*(arr+n)<<" ";//5 4 3 1 ->reverse order
    cout<<endl<<endl;

    //playing with pointers in vectors
    cout<<"Using pointer to iterate through vectors"<<endl;
    vector<int> arr2{9,6,15,2};
    int *p2 = &arr2[0];
    cout<<*(p2+2)<<endl;//arr2[2] = 15
    vector<int> *q2 = &arr2; 
    cout<<q2->at(3)<<endl;//arr2[3] = 2
    cout<<&q2<<endl;//address of the pointer q2-> 0x62fe6c
    cout<<&arr2<<endl;//start address of arr2-> 0x62fe70
    cout<<q2<<endl;//q2 stores start address of arr2-> 0x62fe70

    cout<<endl;

    //playing with advanced concepts of pointer of a pointer of type vector<int>
    cout<<"Using pointer to access the contents another pointer"<<endl;
    vector<int> **r2 = &q2; //r2 stores the pointer to the pointer q2 -> 0x62fe6c
    cout<<r2<<endl; // r2 prints the address of the pointer q2 -> 0x62fe6c
    cout<<&r2<<endl; // &r2 is the address of the pointer r2 -> 0x62fe68
    cout<<*r2<<endl; // *r2 gives the value of q2, which is the starting address of arr2 ->0x62fe70
    //cout<<*r2->at(1)<<endl; //throws error
    vector<int> *t = *r2;
    cout<<t->at(1)<<endl;//prints arr2[1] = 6
}