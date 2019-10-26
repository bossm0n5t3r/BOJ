import sys


def sol():
    input = sys.stdin.readline
    N = int(input())
    ropes = []
    for i in range(N):
        ropes.append(int(input()))
    ropes = sorted(ropes, reverse=True)
    maximum = 0
    for i in range(N):
        if maximum < ropes[i] * (i + 1):
            maximum = ropes[i] * (i + 1)
    print(maximum)


if __name__ == "__main__":
    sol()
