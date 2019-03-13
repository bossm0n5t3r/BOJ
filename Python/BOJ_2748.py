"""
Fibonacci number - 2

https://www.acmicpc.net/problem/2748
"""


def sol():
    a, b = 0, 1
    for i in range(int(input())):
        a, b = b, a + b
    print(a)


if __name__ == "__main__":
    sol()
