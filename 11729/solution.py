import sys


def sol(N):
    print(str(2 ** N - 1) + "\n")
    hanoi(N, 1, 3, 2)


def hanoi(N, start, end, sub):
    if N == 1:
        print("%d %d\n" % (start, end))
        return
    hanoi(N - 1, start, sub, end)
    print("%d %d\n" % (start, end))
    hanoi(N - 1, sub, end, start)


if __name__ == "__main__":
    input = sys.stdin.readline
    print = sys.stdout.write
    N = int(input())
    sol(N)
