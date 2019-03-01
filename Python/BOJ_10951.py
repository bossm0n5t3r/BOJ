"""
A + B 4

https://www.acmicpc.net/problem/10951
"""


def sol():
    while True:
        try:
            a, b = map(int, input().split())
            print(a + b)
        except EOFError:
            break


if __name__ == "__main__":
    sol()
