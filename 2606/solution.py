import sys

input = sys.stdin.readline


def sol():
    total_coms = int(input())
    N = int(input())
    graph = [[] for _ in range(total_coms + 1)]
    for i in range(N):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)
    visited = [1]
    queue = []
    queue.append(1)
    while queue:
        cur = queue.pop(0)
        for n in graph[cur]:
            if n not in visited:
                visited.append(n)
                queue.append(n)
    print(len(visited) - 1)


if __name__ == "__main__":
    sol()
