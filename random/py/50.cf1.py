def solve(s,x,n):
    arr = [0 for i in range(n)]
    ind = True
    t = 0
    for i in range(n):
        if(ind):
            if(s[i]!=x):
                t += 1
        else:
            if(s[i]==x):
                t += 1
        ind = not ind
        arr[i] = t
    return arr 

def solve2(s,arr,x):
    n = len(arr)
    if(n<3):
        return arr[-1]
    c = arr[-1]
    if(n&1):
        if(s[-1]==s[0] and arr[-1]!=arr[]):
            c -=1
    else:
        if()

for _ in range(int(input())):
    s = input()
    n = len(s)
    arr1 = solve(s,'w', n)
    arr2 = solve(s,'b', n)
    print(arr1)
    print(arr2)
    


#python "F:\cpp\random\py\50.cf1.py"