#https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/minimize-the-magic-05a3986c

def dfs(u, p):
    lvl[u] = lvl[p]+1
    for v in graph[u]:
        if(v!=p):
            dfs(v,u)


if __name__=="__main__":
    n,x = map(int, input().split())
    val = [0] + [int(x) for x in input().split()]
    graph = [[]for x in range(n+1)]
    for i in range(n-1):
        a,b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    lvl = [0 for i in range(n+1)]
    dfs(1,1)
    p = max(lvl)
    cnt = [0 for i in range(p+2)]
    for i in lvl:
        cnt[i] += 1
    ind = 0
    for i in range(1,p+2):
        if(cnt[i]<pow(2,i-1)):
            ind = i
            break
    ans = 0
    for i in range(1,n+1):
        ans += lvl[i]*val[i]
    ans += ind*x
    print(ans)

