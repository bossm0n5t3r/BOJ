def sol():
    N, M = map(int, input().split(" "))
    data = sorted(list(map(int, input().split(" "))))
    visited = [False] * (N + 1)
    dfs(N, M, visited, data, 0, 1, "")


def dfs(N, M, visited, data, cnt, start, line):
    if cnt == M:
        print(line)
        return
    for i in range(start, N + 1):
        visited[i] = True
        if cnt == 0:
            dfs(N, M, visited, data, cnt + 1, i, str(data[i - 1]))
        else:
            dfs(N, M, visited, data, cnt + 1, i, line + " " + str(data[i - 1]))
        visited[i] = False


if __name__ == "__main__":
    sol()
