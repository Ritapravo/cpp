#https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/words-and-trees-f9ef202c/

def dfs1(u, p):
    for i in graph[u]:
        if(i!=p):
            dp[u] +=  dfs1(i,u)
    dp[u] += letters[u]
    return dp[u]


def dfs2(u, p):
    for i in graph[u]:
        if(i!=p):
            tmp =  dfs2(i,u)
            dp2[u] = [dp2[u][x] + tmp[x] for x in range(26)]
    dp2[u][ord(letters[u])-97] += 1
    return dp2[u]


if __name__=="__main__":
    n,q = map(int , input().split())
    letters = ["#"] + [x for x in input().split()]
    graph = [[] for i in range(n+1)]
    for i in range(n-1):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    dp = ["" for i in range(n+1)]
    dp2 = [[0 for j in range(26)]for i in range(n+1)]
    dfs1(1,1)
    dfs2(1,1)
    for _ in range(q):
        a,b = map(str,input().split())
        a = int(a)
        tmp = dp2[a][:]
        ans = 0
        for c in b:
            if(tmp[ord(c)-97]>0):
                tmp[ord(c)-97]-=1
            else:
                ans += 1
        print(ans)