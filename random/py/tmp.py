#Finding all paths between two nodes in a graph


def findpath(graph, s, d, vis, count, paths, tmp =[]):
    vis[s] = True
    #tmp.append(s)
    if (s==d):
        count[0]+=1
        paths.append(tmp+[d])
    else:
        for x in graph[s]:
            if(not vis[x]):
                findpath(graph, x, d, vis, count, paths, tmp+[s])
    vis[s] = False

def path(graph, s, d):
    n = len(graph)
    vis = [False]*n
    count = [0]
    paths = []
    findpath(graph, s, d, vis, count,paths)
    return paths

if __name__ =="__main__":
    graph = [[1,2,3],[3],[0,1],[]]
    ans  = path(graph, 2,3)
    print(ans)

#git add . && git commit -m "py" && git push origin master