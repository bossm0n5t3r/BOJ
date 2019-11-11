def sol():
    N, M = map(int, input().split(" "))
    visited = [False] * (N + 1)
    arr = list(range(N + 1))
    dfs(N, M, visited, arr, 0, "")


def dfs(N, M, visited, arr, cnt, line):
    if cnt == M:
        print(line)
        return
    for i in range(1, N + 1):
        visited[i] = True
        if cnt == 0:
            dfs(N, M, visited, arr, cnt + 1, str(arr[i]))
        else:
            dfs(N, M, visited, arr, cnt + 1, line + " " + str(arr[i]))
        visited[i] = False


if __name__ == "__main__":
    sol()
