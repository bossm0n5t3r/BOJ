def sol():
    N, M = map(int, input().split(" "))
    data = sorted(list(map(int, input().split(" "))))
    visited = [False] * (N + 1)
    save = set()
    dfs(N, M, data, visited, save, 0, "")


def dfs(N, M, data, visited, save, cnt, line):
    if cnt == M:
        if line not in save:
            save.add(line)
            print(line)
        return
    for i in range(1, N + 1):
        if not visited[i]:
            visited[i] = True
            if cnt == 0:
                dfs(N, M, data, visited, save, cnt + 1, str(data[i - 1]))
            else:
                dfs(N, M, data, visited, save, cnt + 1, line + " " + str(data[i - 1]))
            visited[i] = False


if __name__ == "__main__":
    sol()
