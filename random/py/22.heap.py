from heapq import heapify, heappush as push, heappop as pop

n ,k = map(int, input().split())
li = [-int(x) for x in input().split()]
heapify(li)
for i in range(k):
    push(li, -1*((-1*pop(li))//2))
print(li)
print(-sum(li))


#li = [5,7,9,1,3]
#python "F:\cpp\random\py\22.heap.py"

print("abcd")