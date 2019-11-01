import sys


def sol():
    input = sys.stdin.readline
    N = int(input())
    node = [[] for i in range(N)]
    for i in range(N):
        vector = list(map(int, input().split(" ")))
        for j in range(N):
            if vector[j] == 1:
                node[i].append(j)
    for i in range(N):
        visited = ["0"] * N
        dfs(node, visited, i)
        print(" ".join(visited))


def bfs(N, node, i):
    queue = []
    visited = [False] * N
    queue.append(i)
    while len(queue) > 0:
        v = queue.pop(0)
        for w in node[v]:
            if not visited[w]:
                visited[w] = True
                queue.append(w)
    result = []
    for check in visited:
        if check:
            result.append("1")
        else:
            result.append("0")
    return result


def dfs(node, visited, v):
    for w in node[v]:
        if visited[w] == "0":
            visited[w] = "1"
            dfs(node, visited, w)


if __name__ == "__main__":
    sol()
