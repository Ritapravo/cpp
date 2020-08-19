#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//#define N 20
#define f(i,x) for(long long int i = 0 ; i<x; i++)
#define g(i,a,b) for(long long int i = a ; i<b; i++)
string ctb( long long int ); 
string compute(vector<pair< long long int, long long int>>&v);


int main(){
    long long int n ;
    cin>>n;
    long long int li[n];
    f(i,n){
        cin>>li[i];
    }

    vector<string> li2;//for storing binary values
    f(i,n){
        li2.push_back(ctb(li[i]));
    }
/* 
    for(string i: li2)
        cout<<i<<" ";
    cout<<endl;
     */
    vector<pair< long long int,  long long int>> pro(n);
    long long int em = li[0];
    f(i,n)if(li[i]>em)em = li[i];

    long long int maxlen = ctb(em).size();

    
    f(i,n){
        string s = li2[i];
        long long int ns = s.size();
        long long int count = 0;
        f(j,ns)
            if(s[j]=='1')
                count++;
        pro[i].first = count;
        pro[i].second = maxlen - count;
    }
/* 
    for(auto i:pro)
        cout<<i.first<<" "<<i.second<<endl;
 */

    string res="", ans = compute(pro);
    
     long long int m = ans.size();
    //cout<<ans<<" "<<m<<" "<<maxlen<< endl;
    if(maxlen>=m){
        for(long long int i = 0; i<maxlen-m; i++){res += "0";}
        //f(i,m)res = res + ans[i];
    }
    
    cout<<res+ans<<endl;
}

string compute(vector<pair< long long int, long long int>>&v){
     long long int res = 0;
     long long int n = v.size();
    f(i,1<<n){
         long long int a = 0;
         long long int b = 0;
        f(j,n){
            if((i>>j)&1){
                a += v[j].first;
                b += v[j].second;
            }
        }
        if(a==b && a!=0 && b!=0)
            res++;
    }
    return ctb(res);
}




string ctb( long long int n) 
{ 
     long long int res[10000], count = 0;   
    while (n > 0) { 
        res[count] = n % 2; 
        n = n / 2; 
        count += 1; 
    } 
    string str="";
    for (long long int j = count - 1; j >= 0; j--) 
        str += to_string(res[j]);
    return str;
} 



//g++ "tmp4.cpp" && a
//g++ "F:\cpp\random\tmp4.cpp" && a 