import sys


def sol():
    input = sys.stdin.readline
    N = int(input())
    multitab = [int(input()) for i in range(N)]
    print(sum(multitab) - (N - 1))


if __name__ == "__main__":
    sol()
