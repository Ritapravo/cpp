n = int(input())
a = input()
b = input()
d = {"r":0, "m":0}
for c in b:
    d[c] += 1
ans = 0
for i in range(n):
    c = a[i]
    if d[c]>0:
        d[c] -= 1
    else:
        ans = n-i
        break
print(ans, end = " ")