import sys
sys.stdin=open('input.txt','r')
sys.stdout=open('output.txt','w')

for _ in range(int(input())):
    n = int(input())
    s = input()
    
    a = 0
    b = 0
    for i in s:
        if(i=='A'):
            a += 1
        else:
            b += 1
    res = ""
    if(max(a,b)-min(a,b)==1):
        res += "Y"
    else:
        res += "N"    
    print("Case #{}: {}".format(_+1, res))
