#https://www.geeksforgeeks.org/minimum-initial-vertices-traverse-whole-matrix-given-conditions/

def dfs(graph, i, j, vis, n, m):
    vis[i][j] = True
    if(i>0 and graph[i-1][j]<=graph[i][j] and not vis[i-1][j]):
        dfs(graph, i-1, j, vis, n, m)
    if(i<n-1 and graph[i+1][j]<=graph[i][j] and not vis[i+1][j]):
        dfs(graph, i+1, j, vis, n, m)
    if(j>0 and graph[i][j-1]<=graph[i][j] and not vis[i][j-1]):
        dfs(graph, i, j-1, vis, n, m)
    if(j<m-1 and graph[i][j+1]<=graph[i][j] and not vis[i][j+1]):
        dfs(graph, i, j+1, vis, n, m)


if __name__ == "__main__":
    graph =[[1,2,3],
            [2,3,1],
            [1,1,1]]
    graph1 =[[3,4],
            [5,1]]
    n = len(graph)
    m = len(graph[0])
    srl = [(graph[i][j],i,j)for i in range(n) for j in range(m)]
    
    srl.sort(key = lambda x:x[0], reverse = True)
    vis = [[False for i in range(m)] for i in range(n)]
    for i in range(m*n):
        if not vis[srl[i][1]][srl[i][2]]:
            print(srl[i][1], srl[i][2])
            dfs(graph, srl[i][1], srl[i][2], vis, n, m)
    