n = int(input())

# 시간복잡도 O(N)
def q1(n):
    s = 0
    for i in range(1, n+1):
        if i%3 == 0 or i%5 == 0:
            s += i

    return s

print(q1(n))