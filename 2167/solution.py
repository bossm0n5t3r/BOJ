import sys


def sol():
    N, M = map(int, sys.stdin.readline().rstrip().split())
    arrays = [[0] * (M + 1) for i in range(N + 1)]
    dp = [[0] * (M + 1) for i in range(N + 1)]
    for i in range(1, N + 1):
        tmp = list(map(int, sys.stdin.readline().rstrip().split()))
        for j in range(1, M + 1):
            arrays[i][j] = tmp[j - 1]
            dp[i][j] = arrays[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]
    K = int(sys.stdin.readline().rstrip())
    for case in range(K):
        i, j, x, y = map(int, sys.stdin.readline().rstrip().split())
        print(dp[x][y] - (dp[i - 1][y] + (dp[x][j - 1] - dp[i - 1][j - 1])))


if __name__ == "__main__":
    sol()
