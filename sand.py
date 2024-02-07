s = list(input())
s = s[::-1]
aux = []
pilha1 = []
pilha2 = []
menor = "z"

for i in range(len(s)):
    menor = min(s[i], menor)
    aux.append(menor)

print("s", s)
print("aux", aux)
print("pilha1", pilha1)
print("pilha2", pilha2)
print()

for i in range(len(s)-1, -1,-1):
    if s[i] == aux[i]:
        pilha2.append(s[i])
        s.pop()
        aux.pop()
        while(len(pilha1) > 0):
            if len(aux) == 0 or pilha1[-1] <= aux[-1]:
                pilha2.append(pilha1[-1])
                pilha1.pop()
            else: break
    else:
        pilha1.append(s[i])
        s.pop()
        aux.pop()
        
    print("i",i)
    print("s", s)
    print("aux", aux)
    print("pilha1", pilha1)
    print("pilha2", pilha2)
    print()
        
print(*pilha2, sep="")
