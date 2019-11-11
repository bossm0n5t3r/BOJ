def sol():
    N, M = map(int, input().split(" "))
    visited = [False] * (N + 1)
    arr = [0] * M
    dfs(N, M, visited, arr, 0, 1)


def dfs(N, M, visited, arr, cnt, start):
    if cnt == M:
        for i in range(M):
            print(arr[i], end=" ")
        print()
        return
    for i in range(start, N + 1):
        if not visited[i]:
            visited[i] = True
            arr[cnt] = i
            dfs(N, M, visited, arr, cnt + 1, i + 1)
            visited[i] = False


if __name__ == "__main__":
    sol()
