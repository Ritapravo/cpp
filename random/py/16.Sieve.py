
def sieve(n):
    primes = [True for i in range(n+1)]
    primes[0],primes[1] = False, False
    i = 2
    while(i*i<=n):
        p = i*i 
        if (primes[p]):
            while(p<=n):
                primes[p] = False
                p = p+i
        i += 1
    return primes



if __name__=="__main__":
    n = int(input())
    arr = sieve(n)
    for i in range(n+1):
        if(arr[i]):
            print(i)