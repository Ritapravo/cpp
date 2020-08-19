# finding all prime factors of a number

from math import sqrt, gcd as hcf

a, b = map(int, input().split())
c = hcf(a,b)
cnt = 0
while(a>c):
    x = 1
    for i in range(2,int(sqrt(a))+1):
        if(a%i==0):
            x = i
            break
    if(x==1):
        a = 1
    else:
        a = a//x
    cnt += 1
    #print(a,0)
while(b>c):
    x = 1
    for i in range(2,int(sqrt(b))+1):
        if(b%i==0):
            x = i
            break
    if(x==1):
        b = 1
    else:
        b = b//x
    cnt += 1
    #print(b,1)
print(cnt, end = "")
    


#python "F:\cpp\random\py\31.codevita2.py"
""" 
d = dict()
n = 15689
while(n%2==0):
    if(2 in d):
        d[2]+=1
    else:
        d[2] =1
    n = n//2
for i in range(3, int(sqrt(n))+1, 2):
    while (n%i==0):
        if(i in d):
            d[i]+=1
        else:
            d[i] =1
        n = n//i
if(n>2):
    if(n in d):
        d[n]+=1
    else:
        d[n] =1
print(d) """