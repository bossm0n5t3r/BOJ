"""
DFS and BFS
Adjacency List

https://www.acmicpc.net/problem/1260
"""


from sys import stdin
import queue


def sol():
    N, M, V = map(int, stdin.readline().rstrip().split())
    nodes = [[] for i in range(N + 1)]
    for i in range(M):
        v1, v2 = map(int, stdin.readline().rstrip().split())
        nodes[v1].append(v2)
        nodes[v2].append(v1)
    for list in nodes:
        list.sort()
    check = [False] * (N + 1)
    dfs(nodes, check, V)
    print()
    check = [False] * (N + 1)
    bfs(nodes, check, V)


def dfs(nodes, check, v):
    if check[v]:
        return
    check[v] = True
    print(str(v) + ' ', end = '')
    for element in nodes[v]:
        if not check[element]:
            dfs(nodes, check, element)


def bfs(nodes, check, v):
    q = queue.Queue()
    q.put(v)
    check[v] = True
    while not q.empty():
        v = q.get()
        print(str(v) + ' ', end = '')
        for element in nodes[v]:
            if not check[element]:
                q.put(element)
                check[element] = True


if __name__ == "__main__":
    sol()
