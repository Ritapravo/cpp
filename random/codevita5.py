for _ in range(int(input())):
    x, y = map(int, input().split())
    ans1 = 0
    ans2 = 0
    for i in range(2, x+1):
        if(x%i==0):
            ans1 += pow(i, y)
    for i in range(2, y+1):
        if(y%i==0):
            ans2 += i*x
    print(ans1, ans2)

#python "F:\cpp\random\codevita5.py"