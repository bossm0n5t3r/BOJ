"""
A + B 6

https://www.acmicpc.net/problem/10953
"""


def sol():
    T = int(input())
    for i in range(T):
        a, b = map(int, input().split(","))
        print(a + b)


if __name__ == "__main__":
    sol()
