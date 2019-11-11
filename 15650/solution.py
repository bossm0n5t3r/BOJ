def sol():
    N, M = map(int, input().split(" "))
    visited = [False] * (N + 1)
    arr = [0] * M
    dfs(N, M, visited, arr, 0, 1)


def dfs(N, M, visited, arr, cnt, start):
    if cnt == M:
        print(" ".join(map(str, arr)))
        return
    for i in range(start, N + 1):
        if not visited[i]:
            visited[i] = True
            arr[cnt] = i
            dfs(N, M, visited, arr, cnt + 1, i + 1)
            visited[i] = False


if __name__ == "__main__":
    sol()
