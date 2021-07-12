#level node tree using bfs
#https://www.geeksforgeeks.org/level-node-tree-source-node-using-bfs/
from collections import deque as queue 

def makegraph():
    n = int(input())
    graph = [[] for i in range(n)]
    for i in range(n-1):
        x,y = map(int, input().split())
        graph[x].append(y)
        graph[y].append(x)
    return graph

def bfs(graph, u):
    n = len(graph)
    vis = [False]*n
    vis[u] = True
    levels = []
    q = queue()
    q.append(u)
    k = 1
    q_size = 1
    while(not q_size==0):
        k -= 1
        if(k==0):
            k = q_size
            levels.append(list(q))
        v = q.popleft()
        q_size -= 1      
        for i in graph[v]:
            if not vis[i]:
                vis[i] = True
                q.append(i)
                q_size += 1
    return levels

if __name__ == "__main__":
    #graph = [[1, 2], [0, 3, 4, 5], [0, 6], [1], [1], [1], [2, 7], [6]]
    graph = [[],[2,3],[1,4,5],[1,6,7],[2,8],[2,8],[3,8],[3,8],[4,5,6,7]]
    levels = bfs(graph, 1)
    print(levels)
