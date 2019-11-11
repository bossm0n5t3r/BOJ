import sys


def sol():
    input = sys.stdin.readline
    N, M, T = map(int, input().split(" "))
    castle = []
    for i in range(N):
        castle.append(list(map(int, input().split(" "))))
    visited = [[False for j in range(M)] for i in range(N)]
    print(bfs(N, M, T, castle, visited))


def bfs(N, M, T, castle, visited):
    gram = 0
    dx = [0, 1, 0, -1]
    dy = [-1, 0, 1, 0]
    q = []
    visited[0][0] = True
    q.append((0, 0, 0))
    while len(q) > 0:
        x, y, count = q.pop(0)
        if castle[x][y] == 2:
            gram = count + ((N - 1) - x) + ((M - 1) - y)
        if x == N - 1 and y == M - 1:
            time = count
            if gram != 0:
                time = min(count, gram)
            if time <= T:
                return time
            return "Fail"
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < N and 0 <= ny < M:
                if not visited[nx][ny] and castle[nx][ny] != 1:
                    visited[nx][ny] = True
                    q.append((nx, ny, count + 1))
    if gram != 0 and gram <= T:
        return gram
    return "Fail"


if __name__ == "__main__":
    sol()
