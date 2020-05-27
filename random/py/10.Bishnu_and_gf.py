#https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/

def dfs(u, p):
    level[u] = level[p] + 1
    for i in graph[u]:
        if(i!=p):
            dfs(i,u)



if __name__=="__main__":
    n = int(input())
    graph = [[]for i in range(n+1)]
    level = [-1 for i in range(n+1)]
    for i in range(n-1):
        a,b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    dfs(1,1)
    ans = n+1
    ind = n+1
    for _ in range(int(input())):
        a = int(input())
        if(level[a]<ans):
            ans = level[a]
            ind = a
        if(ans==level[a] and a<ind):
                ind = a
    print(ind)
