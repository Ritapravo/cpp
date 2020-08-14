
while(True):
    choice = int(input("1: Encrypt \n2: Decrypt \n0: Exit \n"))
    if(choice == 0):
        break
    if(choice==1):
        p,q = map(int, input("Enter two prime numbers: ").split())
        e = int(input("value of e: "))
        m = int(input("Value of plain text(number): "))
        n = p*q
        phi = (p-1)*(q-1)
        d = (1+(2*phi))//e 
        c = pow(m,e,n)
        print("Encrypted msg:",c)
        print("Private Key:",d)
    else:
        m = int(input("Enter the number to decrypt: "))
        p,q = map(int, input("Enter the two prime numbers: ").split())
        d = int(input("Enter private key: "))
        n = p*q
        dm = pow(m,d,n)
        print("Decrypted msg:",dm)
        