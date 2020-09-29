
def solve(li,n): 

    ind = 0
    for i in range(9,-1,-1): 
        start = ind 
        ma = -100000
        j = ind
        while(j<n):   
            if ( (li[j] & (1 << i)) and li[j] > ma ):    
                ma,start = li[j] ,j
            j+=1

        if ( not ma != -100000): 
            continue
 
        li[ind],li[start] = li[start],li[ind]

        start = ind  
        for j in range(n): 

            if ((not j == start) and (li[j] & (1 << i))): 
                li[j] = li[j] ^ li[start] 
        ind += 1
    ans = 0
    for i in li: 
        ans =ans ^ i 
    return ans     



N = 10
n = int(input())
li = [int(i) for i in input().split()]
ans = solve(li,n)
print(ans)


#python "F:\cpp\random\py\PROBLEM2_PYTHON_RITAPRAVO_SARKER.py"