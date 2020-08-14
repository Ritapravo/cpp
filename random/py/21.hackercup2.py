N = int(input("Enter the value of N: "))
for i in range(1, N+1):
    for j in range(N-i):
        print(" ", end = " ")
    for j in range(i, 2*i):
        print(j, end = " ") 
    for j in range(2*i-2, i-1, -1):
        print(j, end = " ")
    print()