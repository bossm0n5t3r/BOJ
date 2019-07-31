import sys


def sol(n, stairs):
    save = {
        0 : stairs[0],
        1 : stairs[1] + stairs[0],
        2 : stairs[2] + max(stairs[0], stairs[1])
    }
    score(n - 1, save, stairs)
    return save[n - 1]


def score(n, save, stairs):
    if n not in save:
        save[n] = stairs[n] + max(
            stairs[n - 1] + score(n - 3, save, stairs),
            score(n - 2, save, stairs)
        )
    return save[n]


if __name__ == "__main__":
    input = sys.stdin.readline
    n = int(input())
    stairs = [int(input()) for _ in range(n)]
    print(sol(n, stairs))
