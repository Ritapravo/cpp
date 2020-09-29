
arr = [25,60,10,25,30]
n = len(arr)

""" for i in range(n):
    for j in range(n-i-1):
        if(arr[j]>arr[j+1]):
            arr[j],arr[j+1] = arr[j+1],arr[j] """

for i in range(1,len(arr)):
    key = arr[i]
    j = i-1
    while(j>=0 and key<arr[j]):
        arr[j+1] = arr[j]
        j -= 1
    arr[j+1] = key
""" 
for i in range(1, len(arr)): 
  
        key = arr[i] 
        j = i-1
        while j >= 0 and key < arr[j] : 
                arr[j + 1] = arr[j] 
                j -= 1
        arr[j + 1] = key  """
print(arr)

#python "F:\cpp\random\py\new.py"