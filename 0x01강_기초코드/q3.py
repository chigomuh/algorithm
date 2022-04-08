# 내 코드
#  def func3(n):
#     i = 1
#     while True:
#         if i*i == n:
#             return 1
#         elif i == 32000:
#             return 0
#         else:
#             i += 1


# print(func3(756580036))
# 시간복잡도 = O(루트N)

# 강의 코드
def func3(n):
    i = 1
    while i * i <= n:
        if i*i == n:
            return 1
        else:
            i += 1
    return 0

print(func3(756580036))