#https://www.spoj.com/problems/LCA/

from math import ceil, log
import sys
from sys import stdin, stdout
sys.setrecursionlimit(1500)

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



for _ in range(int(stdin.readline())):
    N = int(stdin.readline())
    graph = []
    for i in range(N):
        graph.append([int(x)-1 for x in stdin.readline().split()][1:])
    #---------------------#
    LN = ceil(log(N))
    dp = [[None for j in range(LN+1)]for i in range(N)]
    lvl = [-1 for i in range(N)]
    dfs(0,0)
    #---------------------#
    ans = []
    ans.append("Case "+str(_+1)+":"+"\n")
    q = int(stdin.readline())
    for i in range(q):
        a,b = map(int, stdin.readline().split())
        ans.append(str(lca(a-1,b-1)+1) +"\n")
    for i in ans:
        stdout.write(i)