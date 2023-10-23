# t = int(input()
for _ in range (int(input())):
    n,k = [int(x) for x in input().split()]
    nums = [int(x) for x in input().split()]
    out = 10e5

    for i in range(n):
        resto = nums[i] % k
        esse = 0
        if resto != 0:
            esse = k - resto
        # if nums[i] >= k:
        if esse < out: out = esse
        # else:
        #     if resto < out: out = resto
    
    print(out)
