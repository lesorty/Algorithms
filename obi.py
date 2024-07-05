def contapizza(arr, k):
    total = 0
    for i in range(len(arr)):
        total += (k // arr[i])
    return total
    
    
n, p = [int(x) for x in input().split()]
arr = [int(x) for x in input().split()]

l = 0
r = 1e18
out = 0
while l <= r:
    mid = (l + r) // 2
    if(contapizza(arr, mid) >= p):
        out = mid
        r = mid - 1
    else:
        l = mid + 1
        
print(int(out))
