"""
Pills

https://www.acmicpc.net/problem/4811
"""


import sys


def sol():
    map = [[0] * 31 for x in range(31)]
    for i in range(31):
        for j in range(31 - i):
            if i == 0:
                map[i][j] = 1
                continue
            if j == 0:
                map[i][j] = map[i - 1][j + 1]
                continue
            map[i][j] = map[i - 1][j + 1] + map[i][j - 1]
    while True:
        N = int(sys.stdin.readline().rstrip())
        if N == 0:
            break
        print(map[N][0])


if __name__ == "__main__":
    sol()
