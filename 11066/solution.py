import sys


def sol(K, data):
    cumulative = [sum(data[:i]) for i in range(K + 1)]
    memo = [[0] * K for _ in range(K)]
    knuth = [[0] * K for _ in range(K)]
    sup = 10 ** 9
    for i in range(K):
        memo[i][i] = 0
        knuth[i][i] = i
    for i in range(K - 1):
        memo[i][i + 1] = cumulative[i + 2] - cumulative[i]
        knuth[i][i + 1] = i
    for j in range(2, K):
        for i in range(K):
            s = i
            e = i + j
            if e < K:
                tmp = sup
                for k in range(knuth[s][e - 1],knuth[s + 1][e]+1):
                    local_sum = memo[s][k] + memo[k + 1][e]
                    if tmp > local_sum:
                        tmp = local_sum
                        knuth[s][e] = k
                memo[s][e] = cumulative[e + 1] - cumulative[s] + tmp
    return memo[0][K - 1]


if __name__ == "__main__":
    input = sys.stdin.readline
    T = int(input())
    for i in range(T):
        K = int(input())
        data = list(map(int, input().split()))
        sys.stdout.write(str(sol(K, data)) + "\n")
