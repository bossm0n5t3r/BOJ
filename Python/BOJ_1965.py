"""
Boxing

https://www.acmicpc.net/problem/1965
"""


def sol():
    n = int(input())
    boxes = list(map(int, input().split()))
    dp = [0] * n
    MAX = 0
    dp[0] = 1
    for i in range(1, n):
        dp[i] = 1
        for j in range(i):
            if boxes[i] > boxes[j] and dp[j] + 1 > dp[i]:
                dp[i] = dp[j] + 1
        if MAX < dp[i]:
            MAX = dp[i]
    print(MAX)


if __name__ == "__main__":
    sol()
