

def compute(li, meax):
    n = len(li)
    count = 0
    for i in range(1<<n):
        count_one = 0
        z = 0
        for j in range(n):
            if((i>>j)&1):
                count_one += li[j]
                z += meax - li[j]
        if (count_one==z):
            if(z!=0):
                count += 1
    return count



n = int(input())
array = [int(i) for i in input().split()]
m = array[0]
for i in range(n):
    if array[i]>m:
        m = array[i]
def binary(n):
    s = ""
    while(n>0):
        s += str(n%2)
        n = n//2
    return s[::-1]

meax = len(binary(m))
bi = []
for x in array:
    b = binary(x)
    count_one = 0
    for i in b:
        if(i=='1'):
            count_one += 1
    bi.append(count_one)

c = compute(bi,meax)

result = c

result = binary(c)
final = (result)
if len(result)<=meax:
    final = "0"*(meax-len(result)) + result
print(final)




#python "F:\cpp\random\py\30.codevita1.py"