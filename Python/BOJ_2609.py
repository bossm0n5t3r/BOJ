"""
GCD and LCM

https://www.acmicpc.net/problem/2609
"""


def sol():
    a, b = map(int, input().split())
    print(gcd(a, b))
    print(lcm(a, b))


def gcd(x, y):
    while y:
        x, y = y, x % y
    return x


def lcm(x, y):
    return x * y // gcd(x, y)


if __name__ == "__main__":
    sol()
