"""
A + B 7

https://www.acmicpc.net/problem/11021
"""


def sol():
    T = int(input())
    for i in range(T):
        a, b = map(int, input().split())
        print("Case #" + str(i + 1) + ": " + str(a + b))


if __name__ == "__main__":
    sol()
