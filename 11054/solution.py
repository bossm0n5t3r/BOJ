def sol(N, seq):
    lis = [1 for i in range(N)]
    for i in range(1, N):
        for j in range(i):
            if seq[i] > seq[j] and lis[i] < lis[j] + 1:
                lis[i] = lis[j] + 1
    lds = [1 for i in range(N)]
    for i in range(N - 2, -1, -1):
        for j in range(N - 1, i, -1):
            if seq[i] > seq[j] and lds[i] < lds[j] + 1:
                lds[i] = lds[j] + 1
    result = list(map(lambda x, y : x + y - 1, lis, lds))
    return max(result)


if __name__ == "__main__":
    N = int(input())
    seq = list(map(int, input().split()))
    print(sol(N, seq))
