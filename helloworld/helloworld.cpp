#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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

        int array[n];
        for(int i = 0; i<n; i++) 
            array[i] = rand();
        
        clock_t t;
        t = clock();

        insertionsort(array,n);

        t = clock() - t; 
        double time_taken = ((double)t)/CLOCKS_PER_SEC;

        int d = (int)(time_taken*1000000);//converting to microseconds
           
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
