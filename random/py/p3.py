
def fn(n):
    octalNum = [0] * 100
    i = 0
    while (n != 0):
        octalNum[i] = n % 8
        n = int(n / 8)
        i += 1
    for j in range(i - 1, -1, -1):
        if(octalNum[j]==1):
            return 0 
    return 1

n = int(input())
a = []
for i in range(n):
    t = [int(i) for i in input().split()]
    a.append(t)

b = []
for j in range(n):
    s = 0
    for i in range(n):
        s += a[i][j]
    if(fn(s)):
        b.append(s)
b.sort()
for i in b:
    print(i)
    
    
#python "F:\cpp\random\py\p3.py"  
    
    
    