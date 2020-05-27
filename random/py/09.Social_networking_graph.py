#https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/social-networking-graph/


from collections import deque as queue

def solve(graph, s, d):
    n = len(graph)
    vis = [False for i in range(n)]
    vis[s] = True
    q = queue()
    q.append(s)
    q_size = 1
    k = 1
    l = 0
    while(not q_size==0):
        if(k==0):
            k = q_size
            l += 1
        if(l==d):
            return q_size
        k -= 1
        u = q.popleft()
        q_size -= 1
        for i in graph[u]:
            if(not vis[i]):
                vis[i] = True
                q.append(i)
                q_size += 1
    return 0  

if __name__=="__main__":
    n,e = map(int, input().split())
    graph = [[]for i in range(n+1)]
    for i in range(e):
        a,b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    for _ in range(int(input())):
        s,d =  map(int, input().split())
        print(solve(graph, s, d))
        