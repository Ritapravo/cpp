MAX = 100000000


def solve(i):
    if(i>=n):
        if(i==n and s[i-1]=="*"):
            return MAX
        return 0
    if(s[i-1]=="*"):
        return MAX
    
    else:
        if(jump[i]!=0):   
            return(1+min(solve(i+1),solve(i+2),solve(i+p[i])))
        else:
            return(1+min(solve(i+1),solve(i+2))) 
    


def sieve(n):
    primes = [1 for i in range(n+1)]
    primes[0],primes[1] = 0, 0
    i = 2
    while(i*i<=n):
        p = i*i 
        if (primes[p]):
            while(p<=n):
                primes[p] = 0
                p = p+i
        i += 1
    for i in range(1,n+1):
        primes[i] += primes[i-1]
    return primes

for _ in range(int(input())):
    r1,r2 = map(int, input().split())
    n = int(input())
    p = sieve(n)
    jump = [0 for i in range(n+1)]
    for i in range(1,n+1):
        if(p[i]*r2>=i*r1):
            jump[i] = p[i]
    s = input()
    #print(jump)
    dp = [MAX for i in range(n+1)]
    if(s[n-1]=="*"):
        dp[n] = MAX
    def f(x):
        if(x>=n):
            return MAX
        else:
            if(s[x-1]=="*"):
                return MAX
            else:
                return dp[x]
    #print(jump[1:])
    for i in range(n-1, 0, -1):
        if(s[i]=="*"):
            dp[i] = MAX
            continue
        x,y,z = MAX, MAX, MAX
        if(i+1<=n):
            x = dp[i+1]+1
        if(i+2<=n):
            y = dp[i+2]+1
        if(i+jump[i]<=n and jump[i]!=0):
            z = dp[i+jump[i]]+1
        dp[i] = min(x,y,z)
    #print(jump)
    #print(dp)
    if(dp[1]>=MAX or s[n-1]=="*"):
        print("No way!")
    else:
        print(dp[1])
