#https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/
from collections import deque as queue

def level(graph, start, end):
    n= len(graph)
    vis = [False for i in range(n)]
    vis[start] = True
    q = queue()
    q.append(start)
    q_size = 1
    k = 1
    ans  = 0
    while(not q_size==0):
        if(k==0):
            k = q_size
            ans += 1
        k -= 1
        u = q.popleft()
        #print(u)
        q_size -= 1
        if(u==end):
            return ans
        for i in graph[u]:
            if(not vis[i]):
                vis[i] = True
                q.append(i)
                q_size += 1

for _ in range(int(input())):
    n, m  = map(int, input().split())
    graph = [[]for i in range(n+1)]
    for i in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    print(level(graph, 1, n))
