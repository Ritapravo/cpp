//finding product of very large numbers in an efficient way
#include<iostream>
#include<vector>
using namespace std;

string product(string s1, string s2);

int main(){
    int t;
    cin>>t;
    while(t--){
        string s1/* ="5" */, s2/* ="12" */;
        cin>>s1>>s2;
        string prod = product(s1,s2);
        cout<<prod<<endl;
        exp = exp.substr(1,exp.length()-1);
    }
}
string product(string s1, string s2){
    bool c1 = false, c2 = false;
    if(s1[0]=='-'){
        s1 = s1.substr(1,s1.length()-1);
        c1 = true;
    }
    if(s2[0]=='-'){
        s2 = s2.substr(1,s2.length()-1);
        c2 = true;
    }
    int n1 = s1.length();
    int n2 = s2.length();
    vector<int> res(n1+n2,0);
    int p1 = 0, p2 = 0 ;
    for(int i = n1-1; i>=0; i--){
        int c = 0;
        int x = s1[i]-'0';
        p2 = 0;
        for(int j = n2-1; j>=0; j--){
            int y = s2[j]-'0';
            int sum = x*y+c+res[p1+p2];
            c = sum/10;
            res[p1+p2] = sum%10;
            p2++;
        }
        if(c>0)
            res[p1+p2] += c;
        p1++;
    }
    int p3 = n1+n2-1;
    while(p3>=0 and res[p3]==0)
        p3--;
    string prod = "";
    if (p3==-1)
        prod = prod + '0';
    else{
        if(c1^c2)
            prod = prod + '-';
        while (p3 >= 0) 
            prod += to_string(res[p3--]); 
    }
    return prod;
}