n = int(input())

arr = [int(x) for x in input().split()]
st = set()

for i in range(n):
    st.add(arr[i])
    
print(len(st))




