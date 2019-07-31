import sys
sys.setrecursionlimit(100000)


def sol():
    dh = [-1, -1, 0, 1, 1, 1, 0, -1]
    dw = [0, 1, 1, 1, 0, -1, -1, -1]
    while True:
        w, h = map(int, sys.stdin.readline().rstrip().split())
        if w == h == 0:
            break
        islands_map = [[] for i in range(h)]
        for i in range(h):
            islands_map[i].extend(list(map(int, sys.stdin.readline().rstrip().split())))
        count = 0
        for i in range(h):
            for j in range(w):
                if islands_map[i][j] == 1:
                    count += 1
                    check_islands(islands_map, i, j, dh, dw)
        print(count)


def check_islands(islands_map, h, w, dh, dw):
    islands_map[h][w] = 0
    max_h = len(islands_map) - 1
    max_w = len(islands_map[0]) - 1
    for i in range(8):
        new_h = h + dh[i]
        new_w = w + dw[i]
        if new_h < 0 or new_h > max_h or new_w < 0 or new_w > max_w:
            continue
        if islands_map[new_h][new_w] == 1:
            check_islands(islands_map, new_h, new_w, dh, dw)


if __name__ == "__main__":
    sol()
