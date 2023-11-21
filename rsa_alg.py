from math import gcd


def RSA(p: int, q: int, msg: int):
    n=p*q
    
    # calculate totient
    t = (p-1)*(q-1)
    
    # pub key, e
    for i in range(2,t):
        if gcd(i,t)==1:
            e=i
            break 
        
    # pri key, d
    j=0
    while True:
        if (j*e)%t==1:
            d=j
            break
        j+=1
        
    # performing encryption
    ct = (msg ** e) % n
    print(f"Encrypted message is {ct}")

    # performing decryption
    mes = (ct ** d) % n
    print(f"Decrypted message is {mes}")   

# Testcase - 1
RSA(p=53, q=59, msg=89)

# Testcase - 2
RSA(p=3, q=7, msg=12)

  