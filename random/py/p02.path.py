
def fpath(graph, s, d, path = []):
    path.append(s)
    if(s==d):
        return path
    else:
        for i in graph[s]:
            if(i not in path):
                newpath =  fpath(graph, i, d, path[:])
                if(newpath):
                    return newpath
        return None

def fpath2(graph, start, end, path=[]):
        path = path + [start]
        if start == end:
            return path
        for node in graph[start]:
            if node not in path:
                newpath = fpath2(graph, node, end, path)
                if newpath: return newpath
        return None

graph = [[1,2,3],[3],[0,1],[]]
s,d = 2,3
ans = fpath2(graph, s, d)
ans2 = fpath(graph,s,d)
print(ans)
print(ans2)





def findutil(graph, s, d, vis, pathlist, curr=[]):
    vis[s] = True
    curr.append(s)
    if(s==d):
        pathlist.append(curr)
    else:
        for i in graph[s]:
            if(not vis[i]):
                findutil(graph, i, d, vis, pathlist, curr[:])
    vis[s] = False

def findpath(graph, s, d):
    n = len(graph)
    vis = [False for i in range(n)]
    pathlist = []
    findutil(graph, s, d, vis, pathlist)
    return pathlist

#python "F:\cpp\random\tmp.py"