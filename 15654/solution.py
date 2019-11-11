def sol():
    N, M = map(int, input().split(" "))
    data = sorted(list(map(int, input().split(" "))))
    visited = [False] * (N + 1)
    dfs(N, M, data, visited, 0, "")


def dfs(N, M, data, visited, cnt, line):
    if cnt == M:
        print(line)
        return
    for i in range(1, N + 1):
        if not visited[i]:
            visited[i] = True
            if cnt == 0:
                dfs(N, M, data, visited, cnt + 1, str(data[i - 1]))
            else:
                dfs(N, M, data, visited, cnt + 1, line + " " + str(data[i - 1]))
            visited[i] = False


if __name__ == "__main__":
    sol()
