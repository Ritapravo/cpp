#include <iostream>
using namespace std;
int main(void)
{
     int arr[10];
     int d;
     arr[0] = 0;
     arr[9] = 0;
     int nw[10];
     nw[0] = 0; nw[9] = 0;

     for(int i = 1; i<= 8;i++){
         cin>>arr[i];
         nw[i] = arr[i];
     }

     cin>>d;


     for(int i = 0; i< d;i++)
     {

         for(int j = 1;j<= 8;j++)
         {
             if(arr[j-1] == arr[j+1])
                 nw[j] = 0;
             else
                 nw[j] = 1;
         }

         for(int j = 1;j<=8;j++)
             arr[j] = nw[j];
     }

     for(int i = 1;i <=8;i++)
         cout<<nw[i]<<" ";
}

//g++ "xyz.cpp" && a
//g++ "F:\cpp\random\xyz.cpp" && a 