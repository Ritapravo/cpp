
n = (input())
n = int(n)
arr = [int(i) for i in input().split()]
ans = 0
if(arr[0]>=0):
    ans += 1
if(arr[n-1]<=0):
    ans += 1
neg = [0 for i in range(n-1)]
pos = [0 for i in range(n-1)]
for i in range(1, n-1):
    if(arr[i]>=0):
        neg[i] = neg[i-1]+1
    else:
        neg[i] = neg[i-1]
for i in range(n-3, -1, -1):
    if(arr[i+1]<=0):
        pos[i] = pos[i+1]+1
    else:
        pos[i] = pos[i+1]
m = 1000000000000

for i in range(n-1):
    m = min(pos[i]+neg[i], m)
final = str(ans+m)
print(final)

#python "F:\cpp\random\tmp.py"