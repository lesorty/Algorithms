from sys import stdin
input = lambda: stdin.readline()[:-1]

n = int(input())
arestas = [[] for _ in range(n)]
contagem = [0] * n

for _ in range(n - 1):
    a, b = map(lambda x: int(x) - 1, input().split())
    arestas[a].append(b)
    arestas[b].append(a)
    contagem[a] += 1
    contagem[b] += 1

def dfs(raiz):
    distancia = [-1] * n
    distancia[raiz] = 0
    pai = [-1] * n
    para_fazer = [(raiz, -1)]

    while para_fazer:
        v, p = para_fazer.pop()
        for u in arestas[v]:
            if u != p:
                distancia[u] = distancia[v] + 1
                pai[u] = v
                para_fazer.append((u, v))

    mx = max(distancia)
    v = distancia.index(mx)
    return v, distancia, pai

v0, _, _ = dfs(0)
v1, dist0, par0 = dfs(v0)
_, dist1, _ = dfs(v1)

para_fazer = []
for i in range(n):
    if contagem[i] == 1 and i != v0 and i != v1:
        para_fazer.append(i)

resposta = 0
resposta_lista = []

while para_fazer:
    v = para_fazer.pop()
    d0 = dist0[v]
    d1 = dist1[v]
    
    if d0 >= d1:
        resposta_lista.append((v, v0, v))
        resposta += d0
    else:
        resposta_lista.append((v, v1, v))
        resposta += d1
    
    for u in arestas[v]:
        contagem[u] -= 1
        if contagem[u] == 1:
            para_fazer.append(u)

diametro = []
tmp = v1

while True:
    diametro.append(tmp)
    if tmp == v0:
        break
    tmp = par0[tmp]

diametro.reverse()

while len(diametro) >= 2:
    v = diametro.pop()
    resposta += dist0[v]
    resposta_lista.append((v, v0, v))

print(resposta)

for x, y, z in resposta_lista:
    print(x + 1, y + 1, z + 1)