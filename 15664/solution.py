def sol():
    N, M = map(int, input().split(" "))
    data = sorted(list(map(int, input().split(" "))))
    visited = [False] * (N + 1)
    save = set()
    dfs(N, M, visited, data, save, 0, 1, "")


def dfs(N, M, visited, data, save, cnt, start, line):
    if cnt == M:
        if line not in save:
            save.add(line)
            print(line)
        return
    for i in range(start, N + 1):
        if not visited[i]:
            visited[i] = True
            if cnt == 0:
                dfs(N, M, visited, data, save, cnt + 1, i, str(data[i - 1]))
            else:
                dfs(
                    N, M, visited, data, save, cnt + 1, i, line + " " + str(data[i - 1])
                )
            visited[i] = False


if __name__ == "__main__":
    sol()
