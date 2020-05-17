#longest common substring
def lcs(n,m,count) :        
    if (n== 0 or m == 0) :
        dp[n][m] = 0
        return count  
    if dp[n][m]!=-1:
        return max(count, dp[n][m])   
    if (s[n- 1] == t[m - 1]) : 
        count = lcs(n- 1, m - 1, count + 1)
        dp[n][m] = 1 + dp[n-1][m-1]  
    else:
        dp[n][m] = 0
        count = max(lcs(n,m - 1, 0), lcs(n- 1, m, 0))
    return max(dp[n][m],count)
      
s="aaabb"
t="bbaa"
n=len(s)
m=len(t)
dp=[[-1 for i in range(m+1)] for i in range(n+1)]
count = lcs(n,m,0)
for i in dp:
    print(i)
print(count)

#python "F:\cpp\random\p03.L_C_Substrinng.py"