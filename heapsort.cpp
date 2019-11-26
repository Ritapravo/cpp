#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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
    int times[10];
    for (int k = 0; k < p; k++)
    {
        int n = sizes[k];

        int array[n];
        for(int i = 0; i<n; i++) 
            array[i] = rand();
        
        clock_t t;
        t = clock();

        heapSort(array,n);

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