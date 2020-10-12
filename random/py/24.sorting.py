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


arr = [5,2,9,1,3,6]
selectionsort(arr)
print(arr)


#python "F:\cpp\random\py\24.sorting.py"
    