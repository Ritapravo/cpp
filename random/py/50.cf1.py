



#li = [(2, 0), (0, 2), (2, 2), (0, 0), (-2, 2), (-2, 0), (4,0), (4,2)]
li = [(2, 0), (0, 2), (2, 2), (0, 0), (-2, 2), (-2, 0)]
#li = [(0, 0), (0, 2), (2, 0), (2, 2), (1, 1)]
def solve(li):
    n = len(li)

    di = dict()
    for i in  range(len(li)):
        li[i] = tuple(li[i])
        di[li[i]] = i
    count = 0
    di2 = dict()
    for i in range(n-1):
        for j in range(i+1,n):
            x = li[i]
            y = li[j]
            if (x[0]==y[0] or x[1]==y[1]):
                d = abs(x[0]-y[0]+x[1]-y[1])
                if(x[1]==y[1]):
                    p1 = (x[0],x[1]+d)
                    p2 = (y[0],x[1]+d)
                    p3 = (x[0],x[1]-d)
                    p4 = (y[0],x[1]-d)
                else:
                    p1 = (x[0]+d,x[1])
                    p2 = (x[0]+d,y[1])
                    p3 = (x[0]-d,x[1])
                    p4 = (x[0]-d,y[1])
                if(di.get(p1)!=None and di.get(p2)!=None):
                    x1 = max(di[p1],di[p2])
                    y1 = min(di[p1],di[p2])
                    tmp = [i,j,x1,y1]
                    tmp.sort()
                    tmp = tuple(tmp)
                    if(di2.get(tmp)==None):
                        print(tmp)
                        count += 1
                        print(x,y,p1,p2)
                    di2[tmp] = 0
                if(di.get(p3)==0 and di.get(p4)==0):
                    x1 = max(di[p1],di[p2])
                    y1 = min(di[p1],di[p2])
                    tmp = [i,j,x1,y1]
                    tmp.sort()
                    if(di2.get((x1,y1))==None):
                        print(tmp)
                        count += 1
                        print(x,y,p1,p2)
                    di2[tmp] = 0
    return (count)

print(solve(li))