def sol():
    N, M = map(int, input().split(" "))
    visited = [False] * (N + 1)
    arr = list(range(N + 1))
    dfs(N, M, visited, arr, 0, 1, "")


def dfs(N, M, visited, arr, cnt, start, line):
    if cnt == M:
        print(line)
        return
    for i in range(start, N + 1):
        visited[i] = True
        if cnt == 0:
            dfs(N, M, visited, arr, cnt + 1, i, str(arr[i]))
        else:
            dfs(N, M, visited, arr, cnt + 1, i, line + " " + str(arr[i]))
        visited[i] = False


if __name__ == "__main__":
    sol()
