import sys


def sol():
    T = int(sys.stdin.readline())
    for i in range(T):
        a, b = map(int, sys.stdin.readline().split())
        print(a + b)


if __name__ == "__main__":
    sol()
