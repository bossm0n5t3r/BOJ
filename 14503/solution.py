def sol():
    N, M = map(int, input().split())
    r, c, d = map(int, input().split())
    space = []
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]
    for i in range(N):
        space.append(list(map(int, input().split())))
    exploring(r, c, d, space, dx, dy)
    count = 0
    for i in range(N):
        for j in range(M):
            if space[i][j] == 2:
                count += 1
    print(count)


def exploring(x, y, dir, space, dx, dy):
    if space[x][y] == 0:
        space[x][y] = 2
    for i in range(4):
        dir = (dir + 3) % 4
        nx = x + dx[dir]
        ny = y + dy[dir]
        if space[nx][ny] == 0:
            exploring(nx, ny, dir, space, dx, dy)
            return
    if space[x - dx[dir]][y - dy[dir]] == 1:
        return
    exploring(x - dx[dir], y - dy[dir], dir, space, dx, dy)


if __name__ == "__main__":
    sol()
