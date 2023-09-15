import math

i = 1
while i <= math.sqrt(n):
    if n % i == 0:
        if n/i == i:
            divisores.append(i)
        else:
            divisores.append(i)
            divisores.append(int(n/i))

    i += 1