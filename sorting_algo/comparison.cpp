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
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        //swap(arr[i], arr[largest]); 
        int temp = arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        //swap(arr[0], arr[i]);
        int temp = arr[i];
        arr[i]=arr[0];
        arr[0]=temp; 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 

int main()
{   int p=10;
    int sizes[p] = {10000,20000,30000,40000,50000,60000,70000,80000,90000,100000};
    int timesq[10];
    int timesh[10];
    //printf("QUICKSORT(*) V/S HEAPSORT(+)\n");
    for (int k = 0; k < p; k++)
    {
        int n = sizes[k];

        int array[n];
        for(int i = 0; i<n; i++) 
            array[i] = rand();
        
        clock_t t1;
        t1 = clock();

        quicksort(array,0,n-1);

        t1 = clock() - t1; 
        double time_taken1 = ((double)t1)/CLOCKS_PER_SEC;

        double d1 = (time_taken1*1000000);//converting to microseconds
        
        timesq[k]= (int)d1;

        /* =============================================== */

        clock_t t;
        t = clock();

        heapSort(array,n);

        t = clock() - t; 
        double time_taken = ((double)t)/CLOCKS_PER_SEC;

        double d = (time_taken*1000000);//converting to microseconds
        
        timesh[k]= (int)d;

    }
    printf("\ninput size of a random array : ");
    for (int k = 0; k < p; k++){
        sizes[k]=sizes[k]/1000;
        printf("%d ",sizes[k]*1000);
    }
    printf("\n\nQuick Sort time(in micro sec): ");
    for (int k = 0; k < p; k++){
        timesq[k]=timesq[k]/1000;
        printf("%d ",timesq[k]*1000);
    }
    printf("\n\nHeap Sort time(in microsec): ");

    for (int k = 0; k < p; k++){
        timesh[k]=timesh[k]/1000;
        printf("%d ",timesh[k]*1000);
    }
    printf("\n\n");
    
    int graph[51][101]={0};
    graph[0][0]=1;
    for (int k = 0; k < p; k++){
        graph[timesq[k]][sizes[k]] = 1;
    }
    for (int k = 0; k < p; k++){
        graph[timesh[k]][sizes[k]] = 2;
    }
    printf("QUICKSORT(*) V/S HEAPSORT(+)\n");
    for(int i=50;i>=0;i--){
        for(int j =0;j<101;j++){
            if (graph[i][j]==1)
                printf("*");
            else if(graph[i][j]==2)
                printf("+");
            else
            {
                printf(" ");
            }
            
        }
        printf("\n");
    }    
    return 0;
}