//factorial in a better method

#include<iostream>
#include<vector>
using namespace std;

int main(){
    while(true){
        vector<int> arr(10000,0);
        int n ;
        cin>>n;
        if(n==-1)
            break;
        int k = 0;
        arr[0] = 1;
        int c = 0;
        for(int i = 2; i<=n; i++){
            for(int j=0; j<=k; j++){
                arr[j] = arr[j]*i + c;
                c = arr[j]/10;
                arr[j] = arr[j]%10;
            }
            while(c){
                arr[++k] = c%10;
                c = c/10;
            }
        }
        for (int i = k ; i>=0 ; i--)
            cout<<arr[i];
        cout<<endl;
    }
    return 0;
}