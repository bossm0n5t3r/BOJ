import sys


def sol(n, data):
    for i in range(n - 1, 0, -1):
        for j in range(len(data[i]) - 1):
            if data[i][j] > data[i][j + 1]:
                data[i - 1][j] += data[i][j]
            else:
                data[i - 1][j] += data[i][j + 1]
    return data[0][0]


if __name__ == "__main__":
    input = sys.stdin.readline
    n = int(input())
    data = []
    for i in range(n):
        data.append(list(map(int, input().split())))
    print(sol(n, data))
