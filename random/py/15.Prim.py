# Prims algorithm
import heapq as heap

def take_inp():
    n,e = map(int, input().split())
    graph = [[]for i in range(n+1)]
    for i in range(e):
        a, b, w = map(int, input().split())
        graph[a].append((w,b))
        graph[b].append((w,a))

def prim(x):
    hp = []
    min_cost = 0
    heap.heappush(hp,(0,x))
    while(hp!=[]):
        p = heap.heappop(hp)
        x = p[1]
        if(marked[x] == True):
            continue
        min_cost += p[0]
        marked[x] = True
        for g in graph[x]:
            y = g[1]
            if(marked[y] == False):
                heap.heappush(hp,g)
    return min_cost


if __name__=="__main__":
    n,e = 5,6
    graph = [[], [(2,2),(1,3)], [(2,1),(3,4),(5,5)], [(1,1),(4,4)], [(3,2),(4,3),(6,5)], [(5,2),(6,4)]]
    marked = [False for i in range(n+1)]
    min_cost = prim(1)
    print(min_cost)