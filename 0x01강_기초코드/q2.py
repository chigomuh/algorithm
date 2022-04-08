def func2(arr, N):
    arr = list(arr)
    for i in range(N):
        for j in range(N):
            if i == j:
                continue
            elif (arr[i] + arr[j]) == 100:
                return 1
    return 0
# 시간복잡도는 for문을 2번 도니까 O(N^2)
print(func2({4,13,63,87}, 4))