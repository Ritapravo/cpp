
def solve(dp, li, n, s):
    if(s==0):
        dp[n][s] = 1
        return 1
    if(n==0):
        dp[n][s] = 0
        return 0
    if(dp[n][s]!=-1):
        return dp[n][s]
    if(li[n-1]>s):
        dp[n][s] = solve(dp, li, n-1, s)
        return dp[n][s]
    else:
        dp[n][s] = solve(dp, li, n, s-li[n-1]) + solve(dp, li, n-1, s)
        return dp[n][s]

def pr(dp, li, n, s, sol, tmp):
    if(s==0):
        sol.append(tmp)
        return 
    if(n<=0):
        return 
    if(li[n-1]>s):
        pr(dp, li, n-1, s, sol, tmp)
    else:
        if(dp[n][s-li[n-1]]>0):
            pr(dp, li, n, s-li[n-1], sol, tmp+[li[n-1]])
        if(n>0 and dp[n-1][s]>0):
            pr(dp, li, n-1, s, sol, tmp)


if __name__=="__main__":
    li = [2,3,5]
    t = 8
    n = len(li)
    dp = [[-1 for j in range(t+1)]for i in range(n+1)]
    ans = solve(dp, li, n, t)
    print(ans)
    sol = []
    tmp =[]
    pr(dp, li, n, t, sol, tmp)
    for i in dp:
        print(i)
    print(sol)


