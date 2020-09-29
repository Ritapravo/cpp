import sys
sys.setrecursionlimit(1000000)

def dfs(graph, v, c, vis):
    vis[v]= True
    for i in graph[v]:
        if not vis[i]:
            dfs(graph, i, c, vis)
        else:
            #if(i!=v):
            c[0]+= 1


def dft(graph,n,m):
    vis = [False for i in range(n+1)]
    c = [0]
    for i in range(1,n+1):
        if not vis[i]:
            dfs(graph, i, c, vis)
    return c[0]


n,m = map(int, input().split())
graph = [[]for i in range(n+1)]
for i in range(m):
    a,b = map(int, input().split())
    graph[a].append(b)
    #graph[b].append(a)
ans = dft(graph,n,m)
print(ans)

#python "F:\cpp\random\py\PROBLEM1_PYTHON_RITAPRAVO_SARKER.py"