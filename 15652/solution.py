def sol():
    N, M = map(int, input().split(" "))
    arr = list(range(N + 1))
    dfs(N, M, arr, 0, 1, "")


def dfs(N, M, arr, cnt, start, line):
    if cnt == M:
        print(line)
        return
    for i in range(start, N + 1):
        if cnt == 0:
            dfs(N, M, arr, cnt + 1, i, str(arr[i]))
        else:
            dfs(N, M, arr, cnt + 1, i, line + " " + str(arr[i]))


if __name__ == "__main__":
    sol()
