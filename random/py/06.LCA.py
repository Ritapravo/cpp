#finding LCA
#graph = [[1,2],[0,3,4],[0,7],[1,5],[1,6],[3],[4,8],[2],[6,9],[8]]

from math import ceil, log


def dfs(u, p):
    lvl[u] = lvl[p] + 1
    dp[u][0] = p
    for i in range(1,LN+1):
        dp[u][i] = dp[dp[u][i-1]][i-1]
    for v in graph[u]:
        if(v==p):
            continue
        dfs(v,u)

def lca(u, v):
    if(lvl[u] < lvl[v]):
        u,v = v,u
    diff = lvl[u] - lvl[v]
    for i in range(LN+1):
        if((1<<i) & diff):
            u = dp[u][i]

    if(u == v):
        return u

    for i in range(LN, -1, -1):
        if(dp[u][i] != dp[v][i]):
            u = dp[u][i]
            v = dp[v][i]
    return dp[u][0]


graph = [[1,2],[0,3,4],[0,7],[1,5],[1,6],[3],[4,8],[2],[6,9],[8]]
N = 10
LN = ceil(log(N))
dp = [[None for j in range(LN+1)]for i in range(N)]
lvl = [-1 for i in range(N)]
dfs(0,0)
for i in dp:
    print(i)
print(lvl)
print(lca(6,6))