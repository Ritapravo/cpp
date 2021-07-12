from collections import deque as queue

def dfs(graph, u):
    print(u)
    visited[u] = True
    for i in graph[u]:
        if(not visited[i]):
            dfs(graph, i)

def bfs(graph, v):
    visited[v] = True
    arr = queue()
    arr.append(v)
    print(v)
    s,k = 1,1
    while(s):
        u = arr.popleft()
        s -= 1
        k -= 1
        for i in graph[u]:
            if(not visited[i]):
                visited[i] = True
                arr.append(i)
                s += 1
                print(i, end = " ")
        if(k==0):
            k = s
            print("")



graph =  [[],[2],[1,4,5],[6],[2,8],[2,8],[3,8],[8],[4,5,6,7]]
n = len(graph)
visited = [False for i in range(n)]
bfs(graph, 1)