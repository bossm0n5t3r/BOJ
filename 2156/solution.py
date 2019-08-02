import sys


def sol(n, wine):
    a, b, c = 0, 0, 0
    for i in wine:
        a, b, c = max(a, b, c), a + i, b + i
    return max(a, b, c)


if __name__ == "__main__":
    input = sys.stdin.readline
    n = int(input())
    wine = [int(input()) for _ in range(n)]
    print(sol(n, wine))
