def sol():
    N, M = map(int, input().split(" "))
    visited = [False] * (N + 1)
    arr = [0] * M
    dfs(N, M, visited, arr, 0)


def dfs(N, M, visited, arr, cnt):
    if cnt == M:
        if arr == sorted(arr):
            for i in range(M):
                print(arr[i], end=" ")
            print()
        return
    for i in range(1, N + 1):
        if not visited[i]:
            visited[i] = True
            arr[cnt] = i
            dfs(N, M, visited, arr, cnt + 1)
            visited[i] = False


if __name__ == "__main__":
    sol()
