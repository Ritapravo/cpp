def bin(arr, k, n):
    lo = 0
    hi = n-1
    while(lo<=hi):
        mid = lo + (hi-lo)//2
        if(arr[mid] == k and (mid==n-1 or arr[mid]<arr[mid+1])):
            return n-(mid + 1)
        elif(k>=arr[mid]):
            lo = mid + 1
        else:
            hi = mid - 1
    return n-lo

def b(arr, k, n):
    lo, hi = 0,n-1
    while(lo<=hi):
        mid = lo + (hi-lo)//2
        if(arr[mid]==k and (mid==0 or arr[mid-1]<arr[mid])):
            return n-mid
        elif(k>arr[mid]):
            lo = mid+1
        else:
            hi = mid-1
    #print(hi)
    return n-lo

arr = [0,1,1,1,3,3]
n = len(arr)
print(b(arr, int(input()), n))