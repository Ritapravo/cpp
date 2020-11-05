#sorting algorithms

def bubblesort(arr):
    n = len(arr)
    for j in range(n):
        swapped = False
        for i in range(n-1-j):
            if(arr[i]>arr[i+1]):
                arr[i], arr[i+1] = arr[i+1], arr[i]
                swapped = True
        if(not swapped):
            break

def insertionsort(arr):
    n = len(arr)
    for i in range(1,n):
        j = i
        tmp = arr[i]
        while(j>0 and arr[j-1]>tmp):
            arr[j] = arr[j-1]
            j -= 1
        arr[j] = tmp

def selectionsort(arr):
    n = len(arr)
    for i in range(n-1):
        minpos = i
        for j in range(i+1,n):
            if(arr[j]<arr[minpos]):
                minpos = j
        arr[i], arr[minpos] = arr[minpos], arr[i]


def merge(arr, l, m, r):
    n1 = m-l+1
    n2 = r-m
    a = arr[l:m+1]
    b = arr[m+1:r+1]
    i,j,k = 0,0,l
    while(i<n1 and j<n2):
        if(a[i]<b[j]):
            arr[k] = a[i]
            i += 1
        else:
            arr[k] = b[j]
            j += 1
        k += 1
    while(i<n1):
        arr[k] = a[i]
        i+=1
        k+=1
    while(j<n2):
        print(k,j,)
        arr[k] = b[j]
        j+=1
        k+=1


def mergesort(arr, l, r):
    if(l<r):
        m = l + (r-l)//2
        mergesort(arr, l, m)
        mergesort(arr, m+1, r)
        merge(arr, l, m, r)



arr = [5,2,9,1,3,6]
mergesort(arr,0,len(arr)-1)
print(arr)


#python "F:\cpp\random\py\24.sorting.py"
    