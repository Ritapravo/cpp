import sys
def solve(n, ans, tmp, ni):
    if(n<=0):
        op = 0
        for i in range(ni):
            op += tmp[i]//pow(2,i)
        ans.append(op)
        return 
    m = n
    while(m>=0):
        tmp[m], tmp[n] = tmp[n], tmp[m]
        solve(n-1, ans, tmp[:], ni)
        tmp[m], tmp[n] = tmp[n], tmp[m]
        m -= 1


def search(nums, target):
    l = 0
    r = len(nums)-1
    while(l<=r):
        mid = l+(r-l)//2
        if((mid == 0 or nums[mid]>nums[mid-1]) and nums[mid]==target):
            return mid
        elif(target>nums[mid]):
            l = mid+1
        else:
            r = mid-1
    return l


n = int(sys.stdin.readline())
li1 = [int(x) for x in sys.stdin.readline().split()]
li = []
solve(n-1, li, li1, n)
li.sort()
print(li)
nx = len(li)
q = int(sys.stdin.readline())
qli = [int(x) for x in sys.stdin.readline().split()]
ans = []
for i in qli:
    ans.append(nx-search(li, i))
for i in ans:
    sys.stdout.write(str(i)+" ")