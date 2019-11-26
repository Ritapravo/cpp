#include<stdio.h>
#include<stdlib.h>
#include <chrono> 
#include <iostream> 
using namespace std; 
using namespace std::chrono;

//using namespace std;

void insertionsort(int array[], int n){
    for (int j = 1; j < n; j++)
    {
        int key = array[j];
        int i=j-1;
        while(i>=0 && array[i]>key){
            array[i+1]=array[i];
            i-=1;
        }
        array[i+1]=key;
    }
}

int main()
{   int p=10;
    int sizes[p] = {1000,2000,3000,4000,5000,6000,7000,8000,9000,10000};
    int times[10];
    for (int k = 0; k < p; k++)
    {
        int n = sizes[k];


        auto start = high_resolution_clock::now(); 
        int array[n];
        for(int i = 0; i<n; i++) 
            array[i] = rand();

        insertionsort(array,n);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start); 

        int d = duration.count();
        /* cout << "\nTime taken by function: "
            << duration.count() << " microseconds "<<n << endl;   */      
        times[k]= d;
    }
    printf("\n");
    for (int k = 0; k < p; k++){
        sizes[k]=sizes[k]/100;
        printf("%d ",sizes[k]);
    }
    printf("\n\n");
    for (int k = 0; k < p; k++){
        times[k]=times[k]/2000;
        printf("%d ",times[k]);
    }
    printf("\n\n");
    
    int graph[51][101]={0};
    for (int k = 0; k < p; k++){
        graph[times[k]][sizes[k]] = 1;
    }
    for(int i=50;i>=0;i--){
        for(int j =0;j<101;j++){
            if (graph[i][j]==1)
                printf("*");
            else
            {
                printf(" ");
            }
            
        }
        printf("\n");
    }    
    return 0;
}




/* auto start = high_resolution_clock::now(); 
    int a[500000];
    for(int i = 0; i<500000; i++) 
        a[i] = rand(); 
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "\nTime taken by function: "
         << duration.count() << " microseconds" << endl; */