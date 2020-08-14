import sys
sys.stdin=open('input.txt','r')
sys.stdout=open('output.txt','w')


for _ in range(int(input())):
    n = int(input())
    inc = input()
    out = input()
    print("Case #{}:".format(_+1))
    for i in range(n):
        s = ""
        r = ""
        tmp = True
        for j in range(i+1, n):
            if(tmp):
                if(inc[j]=="Y" and out[j-1]=="Y"):
                    r += "Y"
                else:
                    r += "N"
                    tmp = False
            else:
                r += "N"
        tmp = True
        for j in range(i-1, -1, -1):
            if(tmp):
                if(inc[j]=="Y" and out[j+1]=="Y"):
                    s += "Y"
                else:
                    s += "N"
                    tmp = False
            else:
                s += "N"
        res = s[::-1] + "Y" + r 
        print(res)