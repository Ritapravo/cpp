#include<iostream>
using namespace std;

bool strcmp(string s1, string s2){
    int n1 = s1.size(), n2 = s2.size();
    if(n1!=n2)return false;
    for(int i = 0; i<n1; i++)
        if(s1[i]!=s2[i])return false;
    return true;
}
string strcpy(string s1){
    string s2 = "";
    int i = 0;
    while(s1[i]!='\0')s2 += s1[i++];
    return s2;
}

int main(){
    string s1 = "alpha";
    string s2 = "alpha";
    string s3 = strcpy(s2);
    cout<<s3<<endl;
}



//g++ "tmp5.cpp" && a
//g++ "F:\cpp\random\tmp5.cpp" && a 