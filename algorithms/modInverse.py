import math

def binpow(a, b,m):
    res = 1
    while (b > 0):
        if (b & 1):
            res = (res * a) % m
        a = (a * a) % m
        b >>= 1
    return res

def modInverse(b,m):
    g = math.gcd(b, m)
    if (g != 1):
        return -1
    else:
        return binpow(b, m - 2, m)
    
def modDivide(a,b,m):
    a = a % m
    inv = modInverse(b,m)
    if(inv == -1):
        return -1
    else:
        return (inv*a) % m