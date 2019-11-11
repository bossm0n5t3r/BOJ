import sys


def sol():
    input = sys.stdin.readline
    N, M, V = map(int, input().split(" "))
    data = list(map(int, input().split(" ")))
    loop_size = N - V + 1
    for i in range(M):
        C = int(input())
        if C >= N:
            tmp = C - V + 1
            tmp %= loop_size
            C = tmp + V - 1
        print(data[C])


if __name__ == "__main__":
    sol()
