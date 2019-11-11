def sol():
    N, M = map(int, input().split(" "))
    data = sorted(list(map(int, input().split(" "))))
    dfs(N, M, data, 0, "")


def dfs(N, M, data, cnt, line):
    if cnt == M:
        print(line)
        return
    for i in range(1, N + 1):
        if cnt == 0:
            dfs(N, M, data, cnt + 1, str(data[i - 1]))
        else:
            dfs(N, M, data, cnt + 1, line + " " + str(data[i - 1]))


if __name__ == "__main__":
    sol()
