import sys
sys.stdin=open('input.txt','r')
sys.stdout=open('output.txt','w')


def isfilled(soduku, rc):
    for rc[0] in range(7):
        for rc[1] in range(7):
            if(soduku[rc[0]][rc[1]]==0):
                return False
    #rc[0]+=1
    #rc[1]+=1
    return True
def possibilities(soduku, row, col, region):
    arr = [0 for i in range(8)]
    for j in range(7):
        if soduku[row][j]!=0:
            arr[soduku[row][j]] = 1
    for i in range(7):
        if(soduku[i][col]!=0):
           arr[soduku[i][col]]  = 1
    code = region[row][col]

    for i in range(7):
        for j in range(7):
            if(region[i][j]==code and soduku[i][j]!=0):
                arr[ soduku[i][j]] = 1
    poss = []
    for i in range(1,8):
        if(arr[i]==0):
            poss.append(i)
    return poss 

def solve(soduku, region):
    rc = [None,None]
    if(isfilled(soduku, rc)):
        return True
    poss = possibilities(soduku,rc[0],rc[1],region)
    t = len(poss)
    for k in range(t):
        soduku[rc[0]][rc[1]] = poss[k]
        if(solve(soduku,region)):
            return True
        soduku[rc[0]][rc[1]] = 0
    return False


soduku, region = [], []
for i in range(7):
    tmp = [int(x) for x in input().split()]
    soduku.append(tmp)
for i in range(7):
    tmp = [x for x in input().split()]
    region.append(tmp)
ans = solve(soduku, region)
if(not ans):
    print("Sudoku can't be solved", end = "")
else:
    for i in range(7):
        for j in range(7):
            print(soduku[i][j], end = " ")
        print()
    



#python "F:\cpp\random\py\51cf2.py"