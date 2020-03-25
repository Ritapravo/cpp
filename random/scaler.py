from math import *
def ncr(n, r): 
    p = 1
    k = 1
    if (n - r < r): 
        r = n - r 
    if (r != 0):  
        while (r): 
            p *= n 
            k *= r 
            m = gcd(p, k) 
            p //= m 
            k //= m 
            n -= 1
            r -= 1
    else: 
        p = 1
    return (p%1000000007)
class solution:
    def solve(self,a,b):
        n = a//b
        ans = 1
        for i in range(1,n+1):
            s = (a-i*(b-1))%1000000007
            ans += ncr(s,i)%1000000007
        return ans%1000000007
test = solution()
print(test.solve(1962,328))