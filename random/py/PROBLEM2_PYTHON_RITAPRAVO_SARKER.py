from math import ceil
for _ in range(int(input())):
    n,k = map(int, input().split())
    x = n*n - k
    arr = [[1 for i in range(n)]for j in range(n)]
    if(x<2*(n-1)):
        for i in range(ceil(x/2)):
            arr[0][i] = 0
        for i in range(1, x-ceil(x/2)+1):
            arr[i][0] = 0
    elif(x<=(n-1)*(n-1)):
        for i in range(n-1):
            arr[0][i] = 0
        for i in range(1, n-1):
            arr[i][0] = 0
        x = x-2*(n-1)+1
        for i in range(1,n-1):
            for j in range(1,n-1):
                if(x>0):
                    arr[i][j] = 0
                    x -= 1
    else:
        arr = [[0 for i in range(n)]for j in range(n)]
        for i in range(ceil(k/2)):
            arr[0][i] = 1
        for i in range(1, k-ceil(k/2)+1):
            arr[i][0] = 1

    for i in range(n):
        for j in range(n):
            print(arr[i][j], end = "")
        print()