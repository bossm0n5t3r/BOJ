import sys


def sol():
    input = sys.stdin.readline
    N = int(input())
    data = list(map(int, input().split(" ")))
    print(min(data) * max(data))


if __name__ == "__main__":
    sol()
