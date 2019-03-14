"""
Consecutive sum

https://www.acmicpc.net/problem/1912
"""


def sol():
    n = int(input())
    data = list(map(int, input().split()))
    maximum = data[0]
    for i in range(1, n):
        if data[i-1] > 0 and data[i] + data[i-1] > 0:
            data[i] += data[i-1]
        if data[i] > maximum:
            maximum = data[i]
    print(maximum)


if __name__ == "__main__":
    sol()
