"""
Tournament

https://www.acmicpc.net/problem/1057
"""


def sol():
    N, k, l = map(int, input().split())
    count = 0
    while k != l:
        count += 1
        k = (k + 1) // 2
        l = (l + 1) // 2
    print(count)


if __name__ == "__main__":
    sol()
