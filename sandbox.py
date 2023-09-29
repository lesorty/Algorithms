a,b = [int(x) for x in input().split()]
flag = False
ans = []

for i in range(10):
    if flag: break
    ans = [a] 
    soma = a
    for j in range(i):
        soma = (10*soma) + 1
        ans.append(soma)
        if soma == b:
            flag = True
            break
        if soma > b:
            break
    if flag: break
    while soma < b:
        soma *= 2
        ans.append(soma)
        if soma == b:
            flag = True
            break


if flag:
    print("YES")
    print(len(ans))
    print(*ans,sep= " ")
else:
    print("NO")