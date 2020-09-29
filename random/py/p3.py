
def f(li,n,m):
    s = 0
    for i in range(m):
        s += (li[i] + (i+1)*m)
    mi = s
    j = 0
    for i in range(m,n):
        s += (li[i] + (i+1)*m)
        s -= (li[j] + (j+1)*m)
        mi = min(mi,s)
        j += 1
    return mi

def solve(li, n, s):
    lo = 0
    hi = n
    while(lo<=hi):
        mid = lo + (hi-lo)//2
        x = f(li,n,mid)
        if(x==s):
            return mid 
        elif(x<s):
            lo = mid + 1
        else:
            hi = mid-1
    return hi

n,s = map(int, input().split())
li = [int(i) for i in input().split()]
ans = solve(li, n, s)
print(ans)

#python "F:\cpp\random\py\p3.py"