from sys import stdin
import queue


def sol():
    N, M, V = map(int, stdin.readline().rstrip().split())
    matrix = [[0] * (N + 1) for i in range(N + 1)]
    for i in range(M):
        v1, v2 = map(int, stdin.readline().rstrip().split())
        matrix[v1][v2] = 1
        matrix[v2][v1] = 1
    check = [False] * (N + 1)
    dfs(matrix, check, V, True)
    print()
    check = [False] * (N + 1)
    bfs(matrix, check, V)


def dfs(matrix, check, v, flag):
    stack = []
    n = len(matrix) - 1
    stack.append(v)
    check[v] = True
    print(str(v) + " ", end="")
    while len(stack) > 0:
        element = stack[-1]
        flag = False
        for i in range(1, n + 1):
            if matrix[element][i] == 1 and not check[i]:
                stack.append(i)
                print(str(i) + " ", end="")
                check[i] = True
                flag = True
                break
        if not flag:
            stack.pop()


def bfs(matrix, check, v):
    q = queue.Queue()
    n = len(matrix) - 1
    q.put(v)
    check[v] = True
    while not q.empty():
        v = q.get()
        print(str(v) + " ", end="")
        for i in range(1, n + 1):
            if matrix[v][i] == 1 and not check[i]:
                q.put(i)
                check[i] = True


if __name__ == "__main__":
    sol()
