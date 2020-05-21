def sol():
    N = int(input())
    house = []
    doors = []
    dist = [[[-1] * 4 for c in range(N)] for r in range(N)]
    for r in range(N):
        tmp = list(input())
        for c in range(N):
            if tmp[c] == "#":
                if not doors:
                    arr = []
                    for d in range(4):
                        arr.append([r, c, d])
                        dist[r][c][d] = 0
                    doors.append(arr)
                else:
                    doors.append([r, c])
                tmp[c] = "!"
        house.append(tmp)
    bfs(N, house, doors, dist)


def bfs(N, house, doors, dist):
    dr = [1, -1, 0, 0]
    dc = [0, 0, 1, -1]
    start, end = doors
    q = start
    while q:
        r, c, d = q.pop(0)
        if [r, c] == end:
            print(dist[r][c][d])
            return
        nr, nc = r + dr[d], c + dc[d]
        while move(N, nr, nc) and house[nr][nc] == ".":
            nr, nc = nr + dr[d], nc + dc[d]
        if move(N, nr, nc) and house[nr][nc] == "!":
            dist[nr][nc][d] = dist[r][c][d]
            q.append([nr, nc, d])
            k = 2 if d < 2 else 0
            for i in range(k, k + 2):
                if dist[nr][nc][i] == -1:
                    dist[nr][nc][i] = dist[r][c][d] + 1
                    q.append([nr, nc, i])


def move(N, r, c):
    if r < 0 or r >= N or c < 0 or c >= N:
        return False
    return True


if __name__ == "__main__":
    sol()
