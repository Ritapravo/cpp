#include <bits/stdc++.h>
using namespace std;

bool prime[10000]; 


void f(){
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=10000; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=10000; i += p) 
                prime[i] = false; 
        } 
    } 
}

int main(){
  f();
   int n1, n2;
   cin>>n1>>n2;
   vector<int> vec;
   for(int i=n1;i<=n2;i++){
      int flag=0;
       for(int j=2;j<=sqrt(i);j++){
           if(i%j==0) {
               flag=1;
               break;
           }
       }
         if(flag==0) vec.push_back(i);
   }
   set<int> sp;
   vector<int> vec1;
   int lvec = vec.size();
   for(int i=0;i<lvec;i++){
         for(int j=0;j<lvec;j++){
          if(i!=j){
              string s1 = to_string(vec[i]); 
              string s2 = to_string(vec[j]); 
  
              string s = s1 + s2; 
   
              int c = stoi(s); 
              if(prime[c]&&sp.find(c)==sp.end())
                 {sp.insert(c);vec1.push_back(c);}
          }
       }
   }
   int max=INT_MIN;
   int min = INT_MAX;
   int lvec1=vec1.size();
   for(int i=0;i<lvec1;i++){
     if(max<vec1[i]) max=vec1[i];
     if(min>vec1[i]) min=vec1[i];
   }
    long long int a=min; long long int b=max; long long int c; 
    cout<<lvec1<<" "<<a<<" "<<b<<endl;
     for(int i=0;i<lvec1-2;i++){
       c=a+b;
       a=b; b=c;
  }
   cout<<c<<'\n';
   long long int x = 9223372036854775807;
   //x += 1;
   cout<<x<<endl;
}