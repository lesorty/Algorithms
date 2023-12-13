def solve():
    n = int(input())
    seg = [list(map(int, input().split())) for x in range(n)]

    def check(k):
        ll, rr = 0, 0
        for e in seg:
            ll = max(ll - k, e[0])
            rr = min(rr + k, e[1])
            if ll > rr:
                return False
        return True

    l, r = -1, 10 ** 9
    while r - l > 1:
        mid = (r + l) // 2
        if check(mid):
            r = mid
        else:
            l = mid
    print(r)


for _ in range(int(input())):
    solve()