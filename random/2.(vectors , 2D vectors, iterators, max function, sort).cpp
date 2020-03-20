//vectors , 2D vectors, iterators, max function, sort 
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#define maxv(a) *max_element(a.begin(), a.end())
#define maxa(a) *max_element(a, a+(sizeof(a) / sizeof(a[0])))
#define ll long long int
#define len(a) sizeof(a)/sizeof(a[0])
#define f(i,a,b) for(ll i=a; i<=b; i++)
#define g(i,a,b) for(ll i=a; i>=b; i--)
#define append push_back

using namespace std;
ll pow(ll n, ll k, ll p);
ll max3(ll a, ll b, ll c);
ll min3(ll a, ll b, ll c);
bool comp(ll a, ll b);

int main(){
    cout<<"Ritoman's C++ code."<<endl;

    vector<ll> arr5 {1,5,6,2};
    for (ll it :arr5)
        cout<<it<<" ";

    ll arr[] = {1,5,3,2,3,3,4,4};
    //ll n = (sizeof(arr)/sizeof(arr[0]));
    ll n = len(arr);
    cout<<n<<endl;

    vector<ll> vect(arr, arr+n);
    sort(vect.begin(),vect.end());
    vector<ll> :: iterator lower,upper,ptr;
    for(ptr = vect.begin(); ptr<vect.end();ptr++){
        cout<<*ptr<<" ";
    }
    cout<<endl;
    
    lower = lower_bound(vect.begin(),vect.end(),3);
    upper = upper_bound(vect.begin(),vect.end(),3);
    ll l = lower - vect.begin();
    ll u = upper - vect.begin();
    cout<<l<<" "<<u<<endl;

    //2D vectors
    ll row = 3;
    ll col = 5;
    vector<vector<ll>> arr2(row, vector<ll>(col,0));
    vector<vector<ll>>:: iterator i ;
    vector<ll>::iterator j ; 
    for(i=arr2.begin(); i<arr2.end(); i++){
        for (j = i->begin() ; j< i->end() ; j++)
            cout<<*j<<" ";
        cout<<endl;
    }
    cout<<max3(5,2,3)<<endl;
    cout<<min3(5,2,3)<<endl;

    cout<<max({5,2,9,7,6,1,7},comp)<<endl;
    //cout<<comp(5,3)<<endl;

    return 0;
}

ll max3(ll a, ll b, ll c){
    ll m = max(a,b);
    m = max(m,c);
    return m;
}
ll min3(ll a, ll b, ll c){
    ll m = min(a,b);
    m = min(m,c);
    return m;
}

ll pow(ll n, ll k, ll p=1000000007){
    ll res = 1;
    n = n%p;
    while(n>0){
        if(k%2==1){
            k--;
            res = (res*n)%p;
        }
        else{
            k = k/2;
            n = (n*n)%p;
        }
    }
    return res;
}

bool comp(ll a, ll b){
    return a<b;
}

