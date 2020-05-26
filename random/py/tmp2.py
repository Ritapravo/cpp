

for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    b = [int(i) for i in input().split()]
    c = 0 
    ind = True
    for i in range(n):
        b[i] += c
        c = a[i]-b[i]
        if(c<0):
            ind = False
            break
    if(not ind):
        print("NO")
    else:
        if(c==0):
            print("YES")
        else:
            print("NO")
""" 

1
7
5 2 3 1 4 6 3
3 0 2 0 4 5 2
0
2
0
1
0
0
1 """