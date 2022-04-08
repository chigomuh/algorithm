def func4(N):
    i = 1
    while 2**i <= N:
        i += 1
    return 2**(i-1)

print(func4(1024))
# 시간복잡도 = O(lgN)