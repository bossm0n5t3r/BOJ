def sol():
    N, M = map(int, input().split(" "))
    data = sorted(list(map(int, input().split(" "))))
    save = set()
    dfs(N, M, save, data, 0, 1, "")


def dfs(N, M, save, data, cnt, start, line):
    if cnt == M:
        if line not in save:
            save.add(line)
            print(line)
        return
    for i in range(start, N + 1):
        if cnt == 0:
            dfs(N, M, save, data, cnt + 1, i, str(data[i - 1]))
        else:
            dfs(N, M, save, data, cnt + 1, i, line + " " + str(data[i - 1]))


if __name__ == "__main__":
    sol()
