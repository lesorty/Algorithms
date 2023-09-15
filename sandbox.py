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

# valicum = [0]*len(validos)

# valicum[0] = validos[0]
# for i in range(1,len(validos)):
#     valicum[i] = validos[i] + valicum[i-1]

for i in range(len(validos)-1, -1,-1):
    soma += validos[i] * (len(validos) - i)

print(soma)
print(validos)
# print(valicum)