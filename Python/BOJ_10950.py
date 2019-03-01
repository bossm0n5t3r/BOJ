"""
A + B 3

https://www.acmicpc.net/problem/10950
"""


def sol():
    T = int(input())
    for i in range(T):
        a, b = map(int, input().split())
        print(a + b)


if __name__ == "__main__":
    sol()
