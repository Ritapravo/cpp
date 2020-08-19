#bfs for graph
from queue import Queue 

def bfs(graph, v ,visited):
    n = len(graph)
    q = Queue()
    #visited = [False for i in range(n)]
    visited[v-1] = True
    u = v
    traversal = []
    while(True):
        #print(u)
        traversal.append(u)
        for j in graph[u-1]:
            if(not visited[j-1]):
                q.put(j)
                visited[j-1] = True
        if q.empty():
            return traversal
        u = q.get()
def bft(graph,v):
    visited = [False for i in range(len(graph))]
    groups = 0 
    components = []
    for i in range(1,len(graph)+1):
        if(not visited[i-1]):
            components.append(bfs(graph,i,visited))
            groups += 1
    return components

def makegraph():
    #n->number of nodes
    #e->number of edges
    n,e = map(int, input().split())
    graph = [[] for i in range(n)]
    for i in range(e):
        x,y = map(int,input().split())
        graph[x-1].append(y)
        graph[y-1].append(x)
    return graph

if __name__== "__main__":
    #graph = [[2,3],[1,4,5],[1,6,7],[2,8],[2,8],[3,8],[3,8],[4,5,6,7]]
    graph = [[],[4,5],[6,7],[2],[2],[3],[3],[]]
    #graph = makegraph()
    #print(graph)
    li = bft(graph,1)
    print(li)

""" 
8 10 #number of nodes and edges
1 2
1 3
2 4
2 5
3 6
3 7
4 8
5 8
6 8
7 8
<----graph---->
           1
         /   \
        2     3
       / \   / \
      4   5 6   7
       \ /   \ /
         \   /
           8
"""

#python "F:\cpp\random\py\01.bfs.py"