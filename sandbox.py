mod = (10**9) + 7
s = input()
a = 0
t = False
soma = 0
validos = []

for i in range(len(s)):
    if s[i] == "a":
        a += 1
        t = False
    elif s[i] == "b":
        if i > 0 and t == False:
            validos.append(a)
        t = True

if not t:
    validos.append(a)

print(validos)