import math


modulo = (10**9)+7

factors = [1]
fact = 1
for i in range(1,1000007):
    fact = (i*fact) % modulo
    factors.append(fact)

mod = (10**9) + 7
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

n, m = [int(x) for x in input().split()]
cn = binpow(factors[m], (modulo-2), modulo)
cm = binpow(factors[n], (modulo-2),modulo)
result = factors[n+m] * cn * cm
print(result)