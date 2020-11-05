def dfs(grid,i,j,m,n):
    if(i<0 or j<0 or i>=m or j>=n or grid[i][j]=='0'):
        return 0
    grid[i][j] = '0'
    a = dfs(grid, i, j-1, m, n)
    b = dfs(grid, i, j+1, m, n)
    c = dfs(grid, i-1, j, m, n)
    d = dfs(grid, i+1, j, m, n)
    return 1+a+b+c+d

m, n = map(int, input().split())
if(n==0):
    print(0)
    exit()
grid = []
for i in range(m):
    a = [i for i in input().split()]
    grid.append(a)
ans = 0
for i in range(m):
    for j in range(n):
        if(grid[i][j]=='1'):
            tmp = dfs(grid,i,j, m, n)
            if(tmp>ans):
                ans = tmp
print(ans)
    



#python "F:\cpp\random\py\PROBLEM2_PYTHON_RITAPRAVO_SARKER.py"