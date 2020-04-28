def rangeBitwiseAnd(m, n):
    x = bin(m)[2:]
    y = bin(n)[2:]
    l1 = len(x)
    l2 = len(y)
    if(l1>l2):
        return 0
    ans = 0
    i = 0
    #print(l1)
    while(i<l1):
        if(x[i]=='0'):
            break
        print(x[i])
        ans = ans*2 + int(x[i])
        i += 1
    while(i<l1):
        ans *= 2
        i += 1
    return ans

print(rangeBitwiseAnd(5,7))
print("ritoman")
#python "F:\cpp\random\tmp.py"