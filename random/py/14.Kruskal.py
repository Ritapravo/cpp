#minimum spanning tree --> Kruskal's algo


def edge_inp():
    e = int(input())
    edges =[]
    for i in range(e):
        a,b,w = map(int, input().split())
        edges.append((w,a,b))
    return edges


def root(x):
    while(id[x]!=x):
        id[x] = id[id[x]]
        x = id[x]
    return x

def union(x,y):
    p = root(x)
    q = root(y)
    id[p] = id[q]

def kruskal(edges):
    min_cost = 0
    for i in range(e):
        x = edges[i][1]
        y = edges[i][2]
        if(root(x)!=root(y)):
            sp_tree.append(edges[i])
            min_cost += edges[i][0]
            union(x,y)
    return min_cost

if __name__=="__main__":
    n = 5
    e = 6
    edges = [(2,1,2),(1,3,1),(4,3,4),(3,2,4),(6,4,5),(5,2,5)]
    edges.sort()
    sp_tree = []
    id = [i for i in range(n+1)]
    min_cost = kruskal(edges)
    print(min_cost)
    print(sp_tree)
    