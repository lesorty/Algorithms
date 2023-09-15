modulo = (10**9)+7

factors = [1]
fact = 1
for i in range(1,1000007):
    fact = (i*fact) % modulo
    factors.append(fact)