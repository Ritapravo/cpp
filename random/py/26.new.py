
def bfs(graph, a, b, n):
    vis = [False for i in range(n+1)]
    vis[a] = True
    arr = [] 
    arr.append(a)
    c = 1
    while(arr!=[] and b!=0):
        u = arr.pop(0)
        c -= 1 
        for i in graph[u]:
            if(not vis[i]):
                vis[i] = True
                arr.append(i)
        if(c==0):
            c = len(arr)
            b -= 1  
    return c

# Write your code here
n,e = map(int, input().split())
graph = [[]for i in range(n+1)]
for i in range(e):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
m = int(input())
for i in range(m):
    a,b = map(int, input().split())
    ans = bfs(graph, a, b, n)
    print(ans)