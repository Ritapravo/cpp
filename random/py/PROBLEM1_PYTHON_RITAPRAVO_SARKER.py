#https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/a-game-of-numbers-1-5d3a8cb3/

arr = []
n = int(input())
a, b, s1, s2 = dict(), dict(), [], []
for i in range(n):
    arr.append(int(input()))
    x = arr[i]
    while(s1!=[] and s1[-1][0]<x):
        a[s1.pop()[1]] = i
    s1.append((x, i))
    while(s2!=[] and s2[-1][0]>x):
        b[s2.pop()[1]] = i
    s2.append((x, i))
for i in range(n):
    if i in a:
        if a[i] in b:
            print(arr[b[a[i]]], end = " ")
        else:
            print(-1, end = " ")
    else:
        print(-1, end = " ")
print()