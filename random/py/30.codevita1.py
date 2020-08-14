def Largest(num):
  newStr=str(num)
  i=9
  while(i>=0):
    if str(i) in newStr:
        return i
    i-=1
def Smallest(num):
  newStr=str(num)
  i=0
  while(i<=9):
    if str(i) in newStr:
        return i
    i+=1
def Pair_form(num):
    if num==2:
        return 1
    if num>=3:
        return 2
    return 0


N=int(input())
num=list(map(int,input().split()))
bitsscore=[" "]*N
for i in range(len(bitsscore)):
    cur_Store = str(11 * Largest(num[i]) + 7 * Smallest(num[i]))
    if len(cur_Store) > 2:
        cur_Store = cur_Store[-2:]
    bitsscore[i] = cur_Store
#print(bitsscore)
odd_pos_freq=[0]*10
even_pos_freq=[0]*10
for i  in range(len(bitsscore)):
    index=int(bitsscore[i][0])
    if (i + 1) % 2 == 0:
        even_pos_freq[index] += 1
    else:
        odd_pos_freq[index] += 1
#print(odd_pos_freq)
#print(even_pos_freq)
count_pair = 0
for i in range(10):
    x = 0
    if(even_pos_freq[i]>=2):
        if(even_pos_freq[i]<=3):
            x += even_pos_freq[i] - 1
        else:
            x += 2
    if(odd_pos_freq[i]>=2):
        if(odd_pos_freq[i]<=3):
            x += odd_pos_freq[i] - 1
        else:
            x += 2   
    if(x>=2):
        x = 2
    count_pair += x
print (count_pair)


