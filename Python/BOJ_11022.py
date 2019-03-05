"""
A + B 8

https://www.acmicpc.net/problem/11022
"""


def sol():
    T = int(input())
    for i in range(T):
        a, b = map(int, input().split())
        print("Case #" + str(i + 1) + ": " + str(a) + " + " + str(b) + " = " + str(a + b))


if __name__ == "__main__":
    sol()
