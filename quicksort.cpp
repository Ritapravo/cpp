#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int array[] , int start, int end){
    int pivot = array[end];
    int i = start-1;
    int temp;
    for(int j = start ;j<=end-1; j++){
        if(array[j]<=pivot){
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        
    }
    temp = array[i+1];
        array[i+1] = array[end];
        array[end] = temp;
    return i+1 ;
}
void quicksort(int array[], int start, int end){
    if (start<end){
        int part = partition(array,start,end);
        quicksort(array,start,part-1);
        quicksort(array,part+1,end);
    }
}


int main()
{   int p=10;
    int sizes[p] = {10000,20000,30000,40000,50000,60000,70000,80000,90000,100000};
    int times[10];
    for (int k = 0; k < p; k++)
    {
        int n = sizes[k];

        int array[n];
        for(int i = 0; i<n; i++) 
            array[i] = rand();
        
        clock_t t;
        t = clock();

        quicksort(array,0,n-1);

        t = clock() - t; 
        double time_taken = ((double)t)/CLOCKS_PER_SEC;

        double d = (time_taken*1000000);//converting to microseconds
        
        times[k]= (int)d;
    }
    printf("\n");
    for (int k = 0; k < p; k++){
        sizes[k]=sizes[k]/1000;
        printf("%d ",sizes[k]);
    }
    printf("\n\n");
    for (int k = 0; k < p; k++){
        times[k]=times[k]/1000;
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