"""
Printing stars - 6

https://www.acmicpc.net/problem/2443
"""


def sol():
    N = int(input())
    for i in range(N):
        print(' ' * (i) + '*' * (2 * (N - i) - 1))

if __name__ == "__main__":
    sol()
