import math

for _ in range(int(input())):
    flag = False
    crescente = True
    n = int(input())
    arr = [int(x) for x in input().split()]

    for i in range(1, len(arr)):
        if arr[i] < arr[i-1]: crescente = False

    if (crescente): print("YES")

    else:
        for i in range(2, 5):
            if(flag): break
            for j in range(int(math.pow(2,i-1)), int(math.pow(2,i)-1)):
                if(flag): break
                if(j >= n): break
                if(arr[j] > arr[j+1]): flag = True
